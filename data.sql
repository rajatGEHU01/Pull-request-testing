CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    employee_name VARCHAR(100),
    department VARCHAR(50),
    salary DECIMAL(10, 2)
);

INSERT INTO employees VALUES
(1, 'John', 'Engineering', 50000),
(2, 'David', 'Marketing', 40000),
(3, 'Sarah', 'Finance', 60000);


-- ISSUE 1: SQL003 - Wildcard selection
-- Retrieves unnecessary columns
SELECT * FROM employees;


-- ISSUE 2: SQL002 - UPDATE without WHERE
-- May update every employee's salary
UPDATE employees SET salary = 10000;


-- ISSUE 3: SQL001 - DELETE without WHERE
-- May delete every employee record
DELETE FROM employees;


-- ISSUE 4: SQL009 - Always-true condition
-- WHERE condition provides no restriction
DELETE FROM employees WHERE 1 = 1;


-- ISSUE 5: SQL008 - Repeated SQL query
SELECT employee_name FROM employees
WHERE department = 'Engineering';

SELECT employee_name FROM employees
WHERE department = 'Engineering';


-- ISSUE 6: SQL004 - Cartesian join
-- Produces unnecessary combinations of rows
SELECT a.employee_name, b.employee_name
FROM employees a CROSS JOIN employees b;


-- ISSUE 7: SQL006 - TRUNCATE statement
-- Removes all records from the table
TRUNCATE TABLE employees;


-- ISSUE 8: SQL005 - DROP statement
-- Removes the entire table structure
DROP TABLE employees;
