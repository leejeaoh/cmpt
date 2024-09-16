-- Write an INSERT statement that fails for violating (c).
INSERT INTO Trade (aid, seq, type, timestamp, sym, shares, price)
VALUES (1, 4, 'buy', '2023-01-01 12:00:00', 'GOOGL', 20, 2000.00);