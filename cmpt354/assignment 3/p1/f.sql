-- Write an INSERT statement on Account that fails because the
-- account's brokerpid doesn't refer to an existing broker.
INSERT INTO Account (aid, brokerpid) VALUES (210, 8008008000);