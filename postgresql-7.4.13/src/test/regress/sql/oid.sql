--
-- OID
--

CREATE TABLE OID_TBL(f1 oid);

INSERT INTO OID_TBL(f1) VALUES ('1234');

INSERT INTO OID_TBL(f1) VALUES ('1235');

INSERT INTO OID_TBL(f1) VALUES ('987');

INSERT INTO OID_TBL(f1) VALUES ('-1040');

INSERT INTO OID_TBL(f1) VALUES ('99999999');

INSERT INTO OID_TBL(f1) VALUES ('');

-- bad inputs 

INSERT INTO OID_TBL(f1) VALUES ('asdfasd');
INSERT INTO OID_TBL(f1) VALUES ('99asdfasd');

SELECT '' AS six, OID_TBL.*;


SELECT '' AS one, o.* FROM OID_TBL o WHERE o.f1 = 1234;

SELECT '' AS five, o.* FROM OID_TBL o WHERE o.f1 <> '1234';

SELECT '' AS three, o.* FROM OID_TBL o WHERE o.f1 <= '1234';

SELECT '' AS two, o.* FROM OID_TBL o WHERE o.f1 < '1234';

SELECT '' AS four, o.* FROM OID_TBL o WHERE o.f1 >= '1234';

SELECT '' AS three, o.* FROM OID_TBL o WHERE o.f1 > '1234';

DROP TABLE OID_TBL;
