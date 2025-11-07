CREATE TABLE The_points_of_the_Cock (
    point_1 varchar,
    point_2 varchar,
    cost smallint
);

-- DROP TABLE the_points_of_the_cock;

INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('A', 'B', 10);
INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('B', 'A', 10);

INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('A', 'C', 15);
INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('C', 'A', 15);

INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('A', 'D', 20);
INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('D', 'A', 20);

INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('B', 'C', 35);
INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('C', 'B', 35);

INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('B', 'D', 25);
INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('D', 'B', 25);

INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('D', 'C', 30);
INSERT INTO the_points_of_the_cock (point_1, point_2, cost) VALUES ('C', 'D', 30);
