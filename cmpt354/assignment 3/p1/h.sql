-- Write an INSERT statement that fails for violating (b).
INSERT INTO Trade (aid, seq, type, timestamp, sym, shares, price) 
VALUES (500, 4, 'hold', '2025-09-01 12:00:00', 'AAPL', 10, 150.00);