from flask import Flask, request, jsonify
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy.sql import text
import time, datetime

app = Flask(__name__)
# Update the below configuration with your existing PostgreSQL database details
psql_user = 'postgres'
psql_password = 'jay123'
db_name = 'pits'
app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql://{}:{}@localhost/{}'.format(psql_user, psql_password, db_name)
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

@app.route('/')
def index():
    # Execute a raw SQL query directly
    connection = db.engine.raw_connection()
    cursor = connection.cursor()
    cursor.execute("SELECT * FROM Stock WHERE sym = 'AAPL';")
    query_result = cursor.fetchall()
    if len(query_result) > 0:
        res = query_result[0]
    else:
        res = []
    return jsonify(res)

# @app.route('/')
# def index():
#     """
#         an alternative implementation of the index() function
#         with query parameter and placeholder
#     """
#     res = []
#     with db.engine.begin() as conn:
#         query_result = conn.execute(text("SELECT * FROM Stock WHERE sym = :sym ;"), 
#                                     dict(sym='AAPL'))
#         for sym, price in query_result:
#             res.append([sym, price])
#     return jsonify(res[0])

@app.route('/getOwner')
def getOwner():
    """
        This HTTP method takes aid as input, and returns the owner's pid in a list.
        If the account does not exist, return [{'pid': -1}]
    """
    aid = int(request.args.get('aid', -1))
    if aid == -1:
        return jsonify([{'pid': -1}])

    try:
        query = text("SELECT pid FROM Owns WHERE aid = :aid;")
        pids = db.session.execute(query, {"aid": aid}).scalars()
        response = [{"pid": int(pid)} for pid in pids]
        return jsonify(response or [{"pid": -1}])
    except Exception as e:
        return str(e), 500


@app.route('/getHoldings')
def getHoldings():
    """
        This HTTP method takes aid and sym as input, 
        and returns the total share of holdings for a stock sym of an account
        If the stock does not exist or the account does not exist, return {'shares': -1};
        If the account does not hold any share of the stock, return {'shares': 0}
        DO NOT USE the view you create in P1
    """
    aid = int(request.args.get('aid', -1))
    sym = request.args.get('sym', '')
    # complete the function by replacing the line below with your code
    # validates the existence of account and stock symbol
    validation_query = text("SELECT EXISTS(SELECT 1 FROM Account WHERE aid=:aid) AND EXISTS(SELECT 1 FROM Stock WHERE sym=:sym)")
    aid_and_sym_exists = db.session.execute(validation_query, {"aid": aid, "sym": sym}).scalar()
    
    shares = -1
    if aid_and_sym_exists:
        query = text("""
            SELECT COALESCE(SUM(
                CASE WHEN type = 'buy' THEN shares ELSE shares * -1 END), 0) AS shares
            FROM Trade
            WHERE sym = :sym AND aid = :aid
        """)
        shares = db.session.execute(query, {"sym": sym, "aid": aid}).scalar()
    
    return jsonify({'shares': shares})

def currentTime():
    ts = time.time()
    return datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S')
    
@app.route('/trade')
def trade():
    """
        This HTTP method takes the information of a trade as input: aid, sym, type, shares, price 
        You need to retrieve the current maximum seq numer (max_seq) for aid and 
        then insert with max_seq+1 and the current timestamp.
        It returns {'res' : 'fail'} if there is an oversell or other errors like aid/sym/type does not exist;
        Otherwise, it returns {'res': the current seq} and also updates the database accordingly.
        You should implement the check of the violation in the Python function 
        and DO NOT use the view you implemented in P1.
        You will need to finish a multi statement transaction in this function.
        
        Ideally, you need to send a HTTP POST request for such editing requests, 
        but we just choose GET for easier test
    """
    aid = int(request.args.get('aid', -1))
    sym = request.args.get('sym', '')
    trade_type = request.args.get('type', '')
    shares = float(request.args.get('shares', -1))
    price = float(request.args.get('price', -1))
    #validating the input
    if aid == -1 or sym == '' or trade_type not in ['buy', 'sell'] or shares <= 0 or price <= 0:
        return jsonify({'res': 'fail'})

    try:
        validation_query = text("SELECT EXISTS(SELECT 1 FROM Account WHERE aid=:aid) AND EXISTS(SELECT 1 FROM Stock WHERE sym=:sym)")
        shares_query = text("SELECT COALESCE(SUM(CASE WHEN type = 'buy' THEN shares ELSE shares * -1 END), 0) FROM Trade WHERE aid=:aid AND sym=:sym")
        
        aid_and_sym_exists = db.session.execute(validation_query, {"aid": aid, "sym": sym}).scalar()
        total_shares = db.session.execute(shares_query, {"aid": aid, "sym": sym}).scalar()

        #checking for the oversell
        is_not_oversell = trade_type == 'buy' or total_shares >= shares

        if aid_and_sym_exists and is_not_oversell:
            latest_seq_id = db.session.execute(text("SELECT COALESCE(MAX(seq), 0) FROM Trade WHERE aid=:aid"), {"aid": aid}).scalar() + 1
            current_timestamp = datetime.datetime.now()

            add_trade_stmt = text("""
                INSERT INTO Trade (aid, seq, type, timestamp, sym, shares, price) 
                VALUES (:aid, :seq, :type, :timestamp, :sym, :shares, :price)
            """)

            db.session.execute(add_trade_stmt, {
                "aid": aid,
                "seq": latest_seq_id,
                "type": trade_type,
                "timestamp": current_timestamp,
                "sym": sym,
                "shares": shares,
                "price": price
            })
            db.session.commit()

            return jsonify({"res": latest_seq_id})

        return jsonify({"res": "fail"})

    except Exception as e:
        db.session.rollback()
        return jsonify({'res': 'fail', 'error': str(e)})

if __name__ == '__main__':
    app.run(debug=True, port=5000)