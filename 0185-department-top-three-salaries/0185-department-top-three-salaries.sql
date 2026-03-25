# Write your MySQL query statement below
WITH step1 AS (
    SELECT d.name AS Department, 
           e.name AS Employee, 
           e.salary AS Salary, 
           DENSE_RANK() OVER(PARTITION BY d.id ORDER BY e.salary DESC) AS rank1 
    FROM employee e
    LEFT JOIN department d ON e.departmentId = d.id
)
SELECT Department, Employee, Salary 
FROM step1 
WHERE rank1 <= 3;