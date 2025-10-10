-- 创建工资表
CREATE TABLE salary (
    id INT,
    name VARCHAR(50),
    salary DECIMAL(10, 2),
    date DATE
);

-- 插入工资数据
INSERT INTO
    salary (id, name, salary, date)
VALUES (1, '张三', 10000, '2023-10-1'),
    (1, '张三', 15000, '2023-11-1'),
    (1, '张三', 17000, '2023-12-1'),
    (2, '李四', 15000, '2023-9-1'),
    (2, '李四', 13000, '2023-10-1'),
    (2, '李四', 19000, '2023-11-1'),
    (3, '王五', 21000, '2023-11-1'),
    (3, '王五', 20000, '2023-12-1'),
    (3, '王五', 25000, '2024-1-1');
-- 找出每个人最新的工资记录
SELECT DISTINCT s1.*
FROM salary as s1
    INNER JOIN (
        SELECT id, MAX(date) as max_date
        FROM salary
        GROUP BY id
    ) as s2 ON s1.id = s2.id AND s1.date = s2.max_date
ORDER BY s1.id;

-- 创建打卡记录表
CREATE TABLE clock (
    id INT,
    name VARCHAR(50),
    date DATE
);

-- 插入打卡数据
INSERT INTO
    clock (id, name, date)
VALUES (1, '张三', '2024-2-1'),
    (2, '李四', '2024-2-1'),
    (3, '王五', '2024-2-1'),
    (4, '赵六', '2024-2-1'),
    (1, '张三', '2024-2-2'),
    (2, '李四', '2024-2-2'),
    (3, '王五', '2024-2-2'),
    (4, '赵六', '2024-2-2'),
    (1, '张三', '2024-2-3'),
    (2, '李四', '2024-2-3');
-- 查询2024-2-3没打卡的人
SELECT DISTINCT c1.id, c1.name,'2024-2-3' as date
FROM clock as c1
WHERE NOT EXISTS (
        SELECT 1
        FROM clock as c2
        WHERE c1.id=c2.id AND c2.date = '2024-2-3'
    )
ORDER BY c1.id;