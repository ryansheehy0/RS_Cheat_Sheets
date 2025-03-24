[Home](../README.md)

# SQL vs NoSQL
The decisions 

- Only has to do with nested data.

- SQL allows the storage order of the data to be different then the organization of the data, thus allowing the storage to have the data sorted while the organization is unsorted. This allows for binary lookup instead of linear.
	- But this comes at the cost of having to dereference(with the join command) in order to get the organization of the data.


Reading - NoSQL because you don't have to dereference.
Updating - SQL because binary look up
Deleting - SQL because binary look up.
Adding - SQL because binary look up.

NoSQL
	Board 1
		List 1
			Card 1
			Card 2
		List 2
	Board 2

SQL

Boards
	Board 1
	Board 2

Lists
	List 1
	List 2

Cards
	Card 1
	Card 2

- NoSQL is like an array of arrays.
[
	Board 1: [
		List 1: [
			Card 1: [],
			Card 2: 
		]
	]
]

- While SQL is like multiple arrays.

Boards: [Board 1, Board 2]
Lists: [List 1, List 2]
Cards: [Card 1, Card 2]

I'm wrong.
	- You can make both NoSQL and SQL have the data be a separate order than the organization fo the data.
		- You just need to store the order of its children along with the data.