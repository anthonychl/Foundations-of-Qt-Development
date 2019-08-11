ATTACH DATABASE "litedb.db" AS names
CREATE TABLE IF NOT EXISTS names (id INTENGER PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30))
INSERT INTO names (id, firstname, lastname) VALUES (1, 'John', 'Doe')
INSERT INTO names (id, firstname, lastname) VALUES (2, 'James', 'Doe')
INSERT INTO names (id, firstname, lastname) VALUES (3, 'Jane', 'Roe')
INSERT INTO names (id, firstname, lastname) VALUES (4, 'Jake', 'Roe')