-- Active: 1735544718364@@127.0.0.1@3306@mysql

Employee 表：
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id 是这个表的主键。
表的每一行包含员工的工资信息。
 
查询并返回 Employee 表中第二高的 不同 薪水 。如果不存在第二高的薪水，查询应该返回 null(Pandas 则返回 None) 。
查询结果如下例所示。
 
示例 1：
输入：
Employee 表：
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
输出：
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
示例 2：
输入：
Employee 表：
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
输出：
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+

#法一
-- 创建 Employee 表
CREATE TABLE Employee (
    id INT PRIMARY KEY,
    salary INT
);

-- 插入示例数据
INSERT INTO Employee (id, salary) VALUES
(1, 100),
(2, 200),
(3, 300);

-- 执行查询
select 
    max(result.salary) as SecondHighestSalary 
from 
    (select distinct salary from Employee order by salary desc limit 1 offset 1) as result;
#法二
select 
    max(salary) as SecondHighestSalary 
from 
    Employee
where 
    salary < (select max(salary) from Employee)