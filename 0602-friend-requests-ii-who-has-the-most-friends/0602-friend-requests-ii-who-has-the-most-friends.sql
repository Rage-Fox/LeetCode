# Write your MySQL query statement below
WITH CTE AS(
    SELECT requester_id as id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id as id FROM RequestAccepted
)
SELECT id,COUNT(*) AS num FROM CTE GROUP BY id ORDER BY COUNT(*) DESC LIMIT 1;