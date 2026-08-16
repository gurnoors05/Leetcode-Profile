-- Last updated: 8/16/2026, 6:56:36 PM
# Write your MySQL query statement below
SELECT employee_id FROM Employees
WHERE salary < 30000 AND manager_id IS NOT NULL 
    AND manager_id NOT IN (SELECT employee_id FROM Employees) 
ORDER BY employee_id;