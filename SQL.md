```sql
SELECT DISTINCT props
FROM tab1 alias1
INNER / LEFT RIGHT(OUTER) / CROSS JOIN tab2 alias2
ON tab1.prop = tab2.prop
-- self join(use alias), multiple talbes join,
-- compound join(JOIN ... ON ... AND ...).
WHERE (logical expressions) (AND OR NOT IN BETWEEN LIKE (IS / IS NOT NULL))
-- % any number of characters.
-- _ single character.
-- use REGEXP filter results.
ORDER BY props ASC / DESC, props ASC / DESC
LIMIT offset, lim
UNION
...
```

datatypes

```sql
INT
VARCHAR
CHAR
DATE
```

PK：Primary Key 主键

NN：Not Null 非空

AI：Auto Increment 自动递增



插入记录：

```sql
INSERT INTO tab (
    prop1,
    prop2,
    ...
)
VALUES (
    value1,
    value2,
    ...
),
(...)
```

备份数据库中的某个表（复制）：

```sql
CREATE TABLE tab_archived AS
SELECT *
FROM tab
-- tab_archived will have no primary key. (and also no auto increment prop.)
```

更新记录：

```sql
UPDATE tab
SET
	prop1 = xxx,
	prop2 = xxx
WHERE (logical expressions)
```

子查询：

```sql
UPDATE tab1
SET
	prop1 = xxx,
	prop2 = xxx
WHERE prop3 IN
	(SELECT prop4
	FROM tab2
	WHERE (logical expressions))
```



时间 戏剧性、背景的、可能性

健康 

金钱 通用的资源调配符号

人际 认同

爱欲 推动的、超越的

理性 避免极化