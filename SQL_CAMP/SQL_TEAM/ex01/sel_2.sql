WITH po AS (
    WITH RECURSIVE point AS (
        SELECT point_1, point_2, cost,
               0 AS step,
               ARRAY [point_1] AS points,
               FALSE AS bool,
               ARRAY [cost] AS costs
        FROM the_points_of_the_cock
        WHERE point_1 = 'A'

        UNION ALL

        SELECT fuck_points.point_1, fuck_points.point_2, fuck_points.cost + point.cost AS cost,
               step + 1 AS step,
               point.points || fuck_points.point_1 AS points,
               fuck_points.point_1 = ANY (point.points) AS bool,
               point.costs || fuck_points.cost AS costs
        FROM the_points_of_the_cock fuck_points JOIN point ON fuck_points.point_1 = point.point_2
            AND NOT bool )
    -- SELECT *
-- FROM point
-- ORDER BY cost )
    SELECT cost - costs[5] AS cost, points
    FROM point
    WHERE step = 4 AND 'A' = ANY(points) AND 'B' = ANY(points) AND 'C' = ANY(points)
      AND 'D' = ANY(points) AND points[1] = points[5]
    ORDER BY cost, points)

SELECT DISTINCT *
FROM po
WHERE cost = (select min(cost) from po) OR cost = (select max(cost) from po)
ORDER BY 1, 2;

