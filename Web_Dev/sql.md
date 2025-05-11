[Home](../README.md#web-dev)

# SQL
A programming language to manage relational databases.

<!-- TOC -->

- [Atomicity Consistency Isolation DurabilityACID](#atomicity-consistency-isolation-durabilityacid)
- [Attribute Properties](#attribute-properties)
	- [Data types](#data-types)
- [Database Commands](#database-commands)
- [Table Commands](#table-commands)
- [Insert Command](#insert-command)
- [Select Command](#select-command)
- [Update Command](#update-command)
- [Deleting Elements](#deleting-elements)
- [Where](#where)
	- [Like](#like)
- [Join](#join)
	- [Cross Join](#cross-join)
	- [Inner Join](#inner-join)
	- [Outer Join](#outer-join)
		- [Full Outer Join](#full-outer-join)
		- [Left Outer Join](#left-outer-join)
		- [Right Outer Join](#right-outer-join)
	- [Natural Join](#natural-join)
	- [Excluding Join](#excluding-join)
		- [Outer Excluding Join](#outer-excluding-join)
		- [Left Excluding Join](#left-excluding-join)
		- [Right Excluding Join](#right-excluding-join)
	- [Dereferencing](#dereferencing)
- [Functions](#functions)
- [Group By](#group-by)
	- [Having](#having)
- [Alias Tables](#alias-tables)
- [Variables](#variables)
- [Indexes](#indexes)
- [Types of Relationships](#types-of-relationships)
- [MySQL](#mysql)
	- [Installation](#installation)

<!-- /TOC -->

# [Relational Databases](#sql)
Relational databases organize things into tables with each element in the table having a unique id/primary key. Elements in these tables can connect to elements from other tables by having a column of that connection's unique id.

Rows are called elements and columns are called attributes. Each cell contains one value of a specific data type.

**Keys** in SQL have the be unique for each element and are used to define that element.
- A **surrogate key** is a unique id that has no mapping to anything in the real world. It is just used internally in the db.
- A **natural key** is a unique attribute that has a real world mapping. Like a unique email address.
- A **foreign key** is an attribute on a table that links to a unique key of another table.
- A **composite key** is a primary key that is made up of 2 attributes. Only both of the attributes can uniquely identify an element.

Table 1

| email(natural key)  | username |
|---------------------|----------|
| user123@example.com | user123  |
| alice@example.com   | alice    |
| bob@example.com     | bob      |

Table 2

| post_id(surrogate key) | email(foreign key)  | message      |
|------------------------|---------------------|--------------|
| 1                      | user123@example.com | Hello World  |
| 2                      | alice@example.com   | My Thoughts  |
| 3                      | user123@example.com | Another Post |

- A **schema** refers to how the database is layed out. The structure or design of the database.
- A **query** is a search in the database in order to read information.
- **Create Read Update Delete(CRUD)** are the 4 main operation when dealing with databases.

## [Atomicity Consistency Isolation Durability(ACID)](#sql)
One of the fundamental guarantees a transaction(Sequence of CRUD operations) must satisfy for a database.

**Atomicity** means that a transaction either executes entirely or not at all. If part of the transaction doesn't work then the database is not changed.

**Consistency** means the database only goes from one valid state to another valid state. The database can never be in a state that breaks its own internal rules. For example, an attribute always containing a consistent data type.

**Isolation** means that 2 transactions happening at the same time do not interfere with one another. No race conditions.

**Durability** means that once a database is changed those changes will persist and not be lost. This may include some form of backups.

## [Attribute Properties](#sql)
Attributes(columns) have various properties that define their behavior/internal rules.

- **Nullable** defines if an attribute contain NULL value or not.
- **Primary Key** defines a unique id to each element/row. Used to link elements from one table to another. No NULL values.
- **Unique Key** enforces uniqueness of each value, but allows NULL values.
- **Index** improves data retrieval speeds. You can query using the index directly. Like the key in a JS object.
- **Auto Increment** allows the column to automatically generate a unique value and is often used for primary keys.
- **Unsigned** used for numerical data types and decides if they can have signed or unsigned values.

### [Data types](#sql)

| Most Common Data Types | Description                                                        |
|------------------------|--------------------------------------------------------------------|
| INT                    | Integers of 4 bytes.                                               |
| BIGINT                 | Integers of 8 bytes.                                               |
| FLOAT                  | Floating-point numbers                                             |
| VARCHAR(#)             | Strings with a pre-defined length, limited to # of characters.     |
| TEXT                   | Strings of undefined length.                                       |
| DATE                   | Date value in 'YYYY-MM-DD' format.                                 |
| TIME                   | Time value in 'HH:MM:SS' format.                                   |
| DATETIME               | Date and time value in 'YYYY-MM-DD HH:MM:SS' format.               |
| BOOLEAN                | Boolean value representing true or false.                          |
| CHAR(#)                | Fixed-length character string. If shorter then padded with spaces. |
| BLOB                   | Binary large object, for storing binary data.                      |
| DECIMAL                | Store fixed point decimal numbers. Often used for monetary values. |

You can specify a default value.

```SQL
time DATETIME DEFAULT CURRENT_TIMESTAMP,
```

VARCHAR(255) is often used over TEXT because it takes up less space.

# [Structured Query Language(SQL)](#sql)
SQL is a language used to interact with relational databases. Tends to retrieve data very fast.

- SQL keywords are not case sensitive, however capital letters for the commands are recommended.
- Table names and column names tend to be put in lowercase with underscores instead of spaces.
- Strings are put inside single quotes. 's
- Commands in SQL end in semi-columns. ;s
- `--`s and `/**/`s are used for comments in SQL

## [Database Commands](#sql)

```SQL
-- Creating a new database
CREATE DATABASE record_company;

-- This tells SQL which database to use when using commands.
USE record_company;

-- Sees what database is in use
SELECT DATABASE();

-- List Databases
  -- MySQL
SHOW DATABASES;

-- Deleting a databases
DROP DATABASE record_company;

-- In your schema.sql you usually run this at the beginning
DROP DATABASE IF EXISTS sample_db;
CREATE DATABASE sample_db;
```

## [Table Commands](#sql)

```SQL
-- Creating 2 new table
CREATE TABLE bands (
  id INT NOT NULL AUTO_INCREMENT, -- NOT NULL means it has to have a value
  name VARCHAR(255) NOT NULL UNIQUE, -- Enforces the name column/attribute to be unique
  favorite_band INT,
  PRIMARY KEY (id), -- Sets the primary key for the table
  FOREIGN KEY (favorite_band) REFERENCES bands(id) -- Sets an internal reference
);

CREATE TABLE albums (
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, -- You can also create a primary key inline
  name VARCHAR(255) NOT NULL,
  release_year INT, -- Can have NULL values
  band_id INT NOT NULL,
  FOREIGN KEY (band_id) REFERENCES bands(id), -- Sets a foreign key for band_id from the id attribute/column in the bands table
  ON DELETE SET NULL -- When something is deleted it is set to null
);

-- Adding another column
ALTER TABLE bands
ADD another_column VARCHAR(255);

-- Deleting columns from tables
ALTER TABLE bands
DROP COLUMN another_column;

-- Showing tables
  -- MySQL
SHOW TABLES;

-- Shows the different columns and their properties
DESCRIBE table_name;

-- Deleting a table
DROP TABLE table_name;
```

## [Insert Command](#sql)

```SQL
-- Adding elements
INSERT INTO table_name (column_1, foreign_key)
VALUES
  ('1st element in column 1', 1),
  ('2nd element in column 1', NULL);
```

## [Select Command](#sql)

```SQL
-- Gets all attributes and all elements for that table.
SELECT * FROM table_name;

-- Get the first 2 elements of the table
SELECT * FROM table_name LIMIT 2;

-- Gets the 2nd element
SELECT * FROM table_name LIMIT 1,1; -- Limit offset, count

-- Gets all the elements, but only those columns of that element
SELECT column_1 FROM table_name;
SELECT column_1, column_2 FROM table_name;

-- Returns the column with a different name for the column
SELECT id AS 'ID', column_1 AS 'Column 1'
FROM table_name;

-- Get elements, but ordered by a different column. If the column is a text is does by alphabetical order.
SELECT * FROM table_name ORDER BY column_1;
-- or descending order
SELECT * FROM table_name ORDER BY column_1 DESC;

-- Only get unique elements from a column
SELECT DISTINCT column_1 FROM table_name;

-- Only returns the elements with an id greater than 1
SELECT * FROM table_name
WHERE id > 1;

-- Gets column1 and column2 from table_name and adds to it the dbs and the tables in those dbs
SELECT column1, column2 FROM table_name
UNION ( -- Adds onto another query
  -- Gets all the dbs and the tables in those dbs
    -- information_schema.tables is inbuilt into SQL
  SELECT TABLE_SCHEMA AS 'databases', TABLE_NAME as 'tables' FROM information_schema.tables
  WHERE
    TABLE_SCHEMA != 'mysql' AND
    TABLE_SCHEMA != 'information_schema' AND
    TABLE_SCHEMA != 'performance_schema' AND
    TABLE_SCHEMA != 'sys'
);
```

## [Update Command](#sql)

```SQL
-- Updating elements
UPDATE table_name
SET column_1 = 'name'
WHERE id = 1;
```

## [Deleting Elements](#sql)

```SQL
-- Deletes the first element from a table
DELETE FROM table_name
WHERE id = 1;

-- Deletes all the rows in a table
DELETE FROM table_name;
```

## [Where](#sql)
Used to filter rows/elements based upon specific conditions.

| Operator | Description              |
|----------|--------------------------|
| =        | Equal to                 |
| <> or != | Not equal to             |
| <        | less than                |
| >        | greater than             |
| <=       | Less than or equal to    |
| >=       | Greater than or equal to |
| AND      | Logical and              |
| OR       | Logical or               |
| NOT      | Logical not              |
| IS NULL  | Is it equal to null      |
| BETWEEN  | BETWEEN 2000 AND 2018;   |
| LIKE     | Search for pattern.      |

### [Like](#sql)
`LIKE` is used to search for a specific string pattern.

`%` means zero or more characters.

`_` means a single character.

```SQL
-- Selects all names starting with J
SELECT * FROM customers
WHERE customer_name LIKE 'J%';

-- Selects all names with 5 characters or Bob
SELECT * FROM customers
WHERE customer_name LIKE '_____' OR customer_name = 'Bob';
```

## [Join](#sql)
The JOIN command is used to get data from 2 or more tables.

Types of JOIN commands:
- [Cross Join](#cross-join)
- [Inner Join](#inner-join)
- [Outer Join](#outer-join)
  - [Full Outer Join](#full-outer-join)
  - [Left Outer Join](#left-outer-join)
  - [Right Outer Join](#right-outer-join)
- [Natural Join](#natural-join)
- [Excluding Join](#excluding-join)
  - [Outer Excluding Join](#full-outer-join)
  - [Left Excluding Join](#left-outer-join)
  - [Right Excluding Join](#right-outer-join)

Ex:

tableA

| a_id | name     |
|------|----------|
| 1    | apple    |
| 2    | orange   |
| 3    | tomato   |
| 4    | cucumber |

tableB

| b_id | name     |
|------|----------|
| A    | apple    |
| B    | banana   |
| C    | cucumber |
| D    | dill     |

### [Cross Join](#sql)
For every row in tableB all rows from tableA are added.

```SQL
SELECT * FROM tableA
CROSS JOIN tableB;
```

| a_id | name     | b_id | name     |
|------|----------|------|----------|
| 4    | cucumber | A    | apple    |
| 3    | tomato   | A    | apple    |
| 2    | orange   | A    | apple    |
| 1    | apple    | A    | apple    |
| 4    | cucumber | B    | banana   |
| 3    | tomato   | B    | banana   |
| 2    | orange   | B    | banana   |
| 1    | apple    | B    | banana   |
| 4    | cucumber | C    | cucumber |
| 3    | tomato   | C    | cucumber |
| 2    | orange   | C    | cucumber |
| 1    | apple    | C    | cucumber |
| 4    | cucumber | D    | dill     |
| 3    | tomato   | D    | dill     |
| 2    | orange   | D    | dill     |
| 1    | apple    | D    | dill     |


### [Inner Join](#sql)
Mergers only the matching rows in both tables.

By default join is an inner join.

```SQL
SELECT * FROM tableA
INNER JOIN tableB
ON tableA.name = tableB.name;

--or

SELECT * FROM tableA
JOIN tableB
ON tableA.name = tableB.name;
```

| a_id | name     | b_id | name     |
|------|----------|------|----------|
|    1 | apple    | A    | apple    |
|    4 | cucumber | C    | cucumber |

### [Outer Join](#sql)

#### [Full Outer Join](#sql)
Returns matched and unmatched rows from both tables. If there is no match the other side will contain null.

```SQL
SELECT * FROM tableA
FULL OUTER JOIN tableB
ON tableA.name = tableB.name;

-- There is no FULL OUTER JOIN in MySQL
SELECT * FROM tableA
LEFT JOIN tableB ON tableA.name = tableB.name
UNION ALL
SELECT * FROM tableA
RIGHT JOIN tableB ON tableA.name = tableB.name
WHERE tableA.name IS NULL;
```

| a_id | name     | b_id | name     |
|------|----------|------|----------|
| 1    | apple    | A    | apple    |
| 2    | orange   | NULL | NULL     |
| 3    | tomato   | NULL | NULL     |
| 4    | cucumber | C    | cucumber |
| NULL | NULL     | B    | banana   |
| NULL | NULL     | D    | dill     |

#### [Left Outer Join](#sql)
Returns all rows from the left table(tableA) with the matching rows from the right table(tableB) or null.

```SQL
SELECT * FROM tableA
LEFT OUTER JOIN tableB
ON tableA.name = tableB.name;
```

| a_id | name     | b_id | name     |
|------|----------|------|----------|
| 1    | apple    | A    | apple    |
| 2    | orange   | NULL | NULL     |
| 3    | tomato   | NULL | NULL     |
| 4    | cucumber | C    | cucumber |

#### [Right Outer Join](#sql)
Returns all rows from the right table(tableB) with the matching rows from the left table(tableA) or null.

```SQL
SELECT * FROM tableA
RIGHT OUTER JOIN tableB
ON tableA.name = tableB.name;
```

| a_id | name     | b_id | name     |
|------|----------|------|----------|
| 1    | apple    | A    | apple    |
| 4    | cucumber | C    | cucumber |
| NULL | NULL     | B    | banana   |
| NULL | NULL     | D    | dill     |

### [Natural Join](#sql)
Columns with the same values appear only once.

```SQL
SELECT * FROM tableA
NATURAL JOIN tableB;
```

| name     | a_id | b_id |
|----------|------|------|
| apple    |    1 | A    |
| cucumber |    4 | C    |

### [Excluding Join](#sql)

#### [Outer Excluding Join](#sql)
Returns all the rows in tableA and tableB that don't match.

```SQL
SELECT * FROM tableA
FULL OUTER JOIN tableB
  ON tableA.name = tableB.name
WHERE tableA.name IS NULL tableB.name IS NULL;
```

| a_id | name     | b_id | name     |
|------|----------|------|----------|
| 2    | orange   | NULL | NULL     |
| 3    | tomato   | NULL | NULL     |
| NULL | NULL     | B    | banana   |
| NULL | NULL     | D    | dill     |

#### [Left Excluding Join](#sql)
Returns all the rows in tableA that don't match any rows in tableB.

```SQL
SELECT * FROM tableA
LEFT JOIN tableB
  ON tableA.name = tableB.name
WHERE tableB.name IS NULL;
```

| a_id | name     | b_id | name     |
|------|----------|------|----------|
| 2    | orange   | NULL | NULL     |
| 3    | tomato   | NULL | NULL     |

#### [Right Excluding Join](#sql)
Returns all the rows in tableB that don't match any rows in tableA.

```SQL
SELECT * FROM tableA
RIGHT JOIN tableB
  ON tableA.name = tableB.name
WHERE tableA.name IS NULL;
```

| a_id | name     | b_id | name     |
|------|----------|------|----------|
| NULL | NULL     | B    | banana   |
| NULL | NULL     | D    | dill     |

### [Dereferencing](#sql)
You can use join to dereference references. Whenever you have columns with the same name for different tables you need to specify which one you are referring to.

```SQL
SELECT albums.id, albums.name, release_year AS 'release year', bands.name
FROM albums
JOIN bands ON albums.band_id = bands.id;
```

This returns the table:

```
| id   | name                      | release year | name                |
|------|---------------------------|--------------|---------------------|
| 1    | 'The Number of the Beast' | 1982         | 'Iron Maiden'       |
| 2    | 'Power Slave'             | 1984         | 'Iron Maiden'       |
| 3    | 'Nightmare'               | 2018         | 'Deuce'             |
| 4    | 'Nightmare'               | 2010         | 'Avenged Sevenfold' |
```

## [Functions](#sql)
Functions are almost always slower than doing checks(=, !=, >, <, etc) with hard coded data values. This is because the database can quickly find the row in which the hard coded data is in.

| Name         | Type        | Description                                  |
|--------------|-------------|----------------------------------------------|
| CONCAT()     | String      | Concatenates 2 or more strings               |
| UPPER()      | String      | Converts string to uppercase                 |
| LOWER()      | String      | Converts string to lowercase                 |
| LENGTH()     | String      | Gets the length of the string                |
| SUM()        | Numeric     | Calculates the sum of numbers                |
| AVG()        | Numeric     | Calculates the average of numbers            |
| COUNT()      | Numeric     | Counts the number of rows or non-null values |
| MIN()        | Numeric     | Finds the minimum value in a column          |
| MAX()        | Numeric     | Finds the maximum value in a column          |
| DATEPART()   | Date/Time   | Extracts a specific part from a date or time |
| DATEDIFF()   | Date/Time   | Calculates the difference between two dates  |
| CASE         | Conditional | Performs conditional logic                   |
| COALESCE()   | Conditional | Returns the first non-null value in a list   |
| GROUP BY     | Aggregation | Groups rows based on one or more columns     |
| HAVING       | Aggregation | Filters aggregated results                   |
| ORDER BY     | Aggregation | Sorts the result set                         |
| ROW_NUMBER() | Window      | Assigns a unique row number to each row      |
| LAG()        | Window      | Accesses the value of a previous row         |
| MONTH()      | Numeric     | Gets month between 1 and 12                  |

Examples:

```SQL
-- AVG
SELECT AVG(release_year) FROM albums;
  -- 1998.5  It doesn't count null values

-- Count
SELECT COUNT(release_year) FROM albums;
  -- 4
```

## [Group By](#sql)
Takes all the rows and groups them by a single column. If there are 2 rows that have the same value in a column group by combines them.

This is often used with `COUNT` in order to count how many rows are in each column.

```SQL
SELECT band_id, COUNT(band_id) from albums
GROUP BY band_id;
```

This returns the table:

```
| band_id | COUNT(band_id) |
|---------|----------------|
| 1       | 2              |
| 2       | 1              |
| 3       | 1              |

```

### [Having](#sql)
The `HAVING` is the same as where, but happens after the `GROUP BY` so you can use data before an aggravate function.

```SQL
-- Get the number of bands with only 1 album
SELECT b.name band_name, COUNT(a.id) num_albums
FROM bands b
LEFT JOIN albums a ON b.id = a.band_id
GROUP BY b.id
HAVING num_albums = 1;
```

## [Alias Tables](#sql)
Alias tables are temporary names given to a table or column in order to resolve naming conflicts.

This is often used to de-reference an internal reference in a table.

```SQL
SELECT b.name AS band_name, COUNT(a.id) AS num_albums
FROM bands AS b
LEFT JOIN albums AS a;

-- You can also leave out the AS
SELECT b.name band_name, COUNT(a.id) num_albums
FROM bands b
LEFT JOIN albums a;
```

## [Variables](#sql)
You can have variables(user defined values) in sql by using the `@` symbol.

```SQL
SET @var = 1;

SELECT @var FROM table_name; -- Gets teh 1st column from table_name
```

## [Indexes](#sql)
Indexes are used to speed up queries in exchange for taking up more memory and increasing times to create data.

```SQL
CREATE INDEX index_name ON table_name (column1, column2);
```

When the database creates an index it aligns everything in order(numerically or alphabetically) and creates a balanced tree to speed up queries.

A balanced tree is a binary tree where the left tree and the right tree cannot have a difference greater than 1.

Without indexing:

```
1->2->3->4->5->6->7->8->9->10

Is x == 1?
  If no then is x == 2?
    If no then is x == 3?
      etc.
```

With indexing:

```
         5
      /     \
     3       8
    / \     / \
   2   4   7   9
  /         \
 1           10

Is x == 5?
  If no then is x < 5?
    If yes then is x == 3?
      If no then is x < 3?
        etc.
    If no then is x == 8?
      If no then is x < 8?
        etc.
```

## [Types of Relationships](#sql)
- One-to-One
  - One row in a table is associated with exactly one row in another table. This is enforced with unique.
  - Ex: A `User` has one `Profile` and a `Profile` belongs to one `User`
- One-to-Many/Many-to-One
  - One row in a table can be associated with many different rows from another column.
  - Ex: A `User` has many `Task`s, but a `Task` belongs to only one `User`
- Many-to-Many
  - An intermediate table(junction table) that has columns which references both tables. This junction table is used to link the 2 tables.
  - Ex: `Students` can belong to many `Courses` and each `Course` can have many `Students`

# [Relational Database Management System(RDBMS)](#sql)
A special software program used to create and maintain a database.

Databases are usually kept on separate servers than your http endpoints(NodeJS and Express) because it is much easier to scale the database, secure the database, backup and recover the database, etc.

## [MySQL](#sql)
The default port for MySQL is 3306.

`SOURCE schema.sql` allows you to run a sql file in MySQL.

### [Installation](#sql)
1. `sudo apt update`
1. `sudo apt install mysql-server`
1. `sudo mysql -u root -p`
1. Change the default mysql password
  - For your local host root it is recommended to make the password `root`
  - `ALTER USER 'root'@'localhost' IDENTIFIED WITH 'mysql_native_password' BY 'new_password';`
  - `FLUSH PRIVILEGES;`
  - `exit`
1. Now you can run `mysql -u root -p` to start you mysql server in the future