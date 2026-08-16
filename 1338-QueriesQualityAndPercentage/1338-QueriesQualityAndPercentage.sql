-- Last updated: 8/16/2026, 7:03:17 PM
# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT 
    query_name,
    ROUND(AVG(rating / position),2) AS quality,
    ROUND(AVG(IF(rating < 3,1,0))*100,2) AS poor_query_percentage 
FROM Queries
GROUP BY query_name