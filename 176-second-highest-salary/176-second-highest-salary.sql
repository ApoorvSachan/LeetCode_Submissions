# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary FROM employee where salary NOT IN (SELECT MAX(salary) from Employee);