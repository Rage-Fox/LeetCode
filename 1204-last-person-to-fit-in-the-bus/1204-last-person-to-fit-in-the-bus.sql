# Write your MySQL query statement below
# OVER clause is a window function. If it's empty, it mentions all the records of the table.
SELECT person_name FROM (
    SELECT person_name,turn,SUM(weight) OVER(ORDER BY turn) AS cum FROM queue) p1
WHERE cum<=1000 ORDER BY turn DESC LIMIT 1;
# As we need the last person, we ordered records by turn which makes last person come to top and grab it with limit 1