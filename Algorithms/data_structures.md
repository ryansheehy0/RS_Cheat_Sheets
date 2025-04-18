[Home](../README.md)

# Data Structures
Data structures store data in an organized way, define the types of values that can be stored, and specify the operations that can be performed on that data.

The 4 most common operations are create/add/insert, read/get/access, update, and delete/remove. Commonly abbreviated as CRUD.

**Ordered** means that the data structure retains the order in which elements are added.
- Ex: A bad is unordered because you pull things out in no particular order, while cubby boxes are ordered, you place items in specific spots.
**Sorted** means that the ordering is arranged in a specific way.

<!-- TOC -->

- [Abstract data types](#abstract-data-types)
	- [Stack](#stack)
		- [Common operations](#common-operations)
		- [Pseudocode Implementation](#pseudocode-implementation)
		- [Common use cases](#common-use-cases)
	- [Queues](#queues)
		- [Common operations](#common-operations)
		- [Pseudocode Implementation](#pseudocode-implementation)
		- [Common use cases](#common-use-cases)
- [Concrete data structures](#concrete-data-structures)

<!-- /TOC -->

## Abstract data types
Abstract data types(ADTs) define which operation can be used, but not how the data is to be stored and organized.

- **Stack** - Items are only inserted on or removed from the top.
- **Queue** - Items are only inserted at the end and removed from the front.
- **Priority Queue** - A queue where each item has a priority and items with higher priority dequeue first.
- **Double-ended Queue(Deque)** - Items can be inserted and removed from both the front and back.
- **List** - Ordered collection that allows for access via index.
- **Bag/Multiset** - Unordered collection that allows for duplicates.
- **Set** - Unordered collection of unique items.
- **Map/Dictionary** - Key value pairs with unique keys.

### Stack
**Last in first out(LIFO)** - The last item added to the collection is the first one to be taken out.

#### Common operations
- `bool push(Type x)` - Inserts x on the top of the stack.
- `Type pop()` - Removes and returns the stack's top item.
	- Need to check that the stack isn't empty before calling.
- `Type peek()` - Returns the stack's top item without removing it.
	- Need to check that the stack isn't empty before calling.
- `bool isEmpty()`
- `int getLength()`
	- The stack usually increments or decrements the length when you push/pop.

#### Pseudocode Implementation
- With arrays
	- The top of the stack is typically at the end of the array to avoid shifting elements when adding or removing items.
	- bool push(Type x)
		- Check if the top index equals the max length
		- Increment the top index
		- Assign the value at the top index with x
	- pop
		- Decrement the top index
		- Return the value at top index + 1
	- getLength
		- Return the top index + 1
- With linked lists
	- push
		- Create a new node
		- Check if the creation was successful
		- Assign the new node's data
		- Point the new node's next to the top
		- Move the top to the new node
		- Increment length
	- pop
		- Assign local var with top's data
		- Save the top node as old top
		- Move the top node down
		- Delete the old top node
		- Decrement length
		- Return local var

#### Common use cases
- Reversing a stack
	- Push and pop into another stack(stackA)
	- Push and pop into another stack(stackB)
	- Push and pop into the original stack
- Checking for unmatched parentheses
	- Push open pars on the stack.
	- If closed par, then pop an open pars.
	- At the end, if the stack isn't empty, then there were unmatched pars.
- Converting infix(a + b) to postfix/Reverse polish notation(a b +)
	- In postfix notation, you don't need parentheses to determine order of operations.
	- Have 2 stacks, operation stack and output stack.
	- Push variables onto the output stack.
	- If an operation has higher precedence then the top of the operation stack, then push that operation on top.
	- If an operation doesn't have higher precedence or is equal precedence, then top the operation stack onto the output stack until you reach an operation of lower precedence.
	- If an open parentheses, push onto operation stack.
	- If a closed parentheses, pop from operation stack onto output stack until you reach an open parentheses.
	- At the end, push operation stack onto output stack. The output stack should not have any pars and be in postfix notation.
	- Ex: a + 5 * b -> a 5 b * +
- Calculating postfix expressions
	- Push variables onto stack.
	- If operation, pop from stack as the right argument and pop again for the left argument. The result gets pushed onto the stack.
		- Ex: Stack = |3, 2, 7| and operation = *. 2 * 3 = 6. New Stack = |6, 7|
	- At the end, the only value on the stack should be the result if it was a valid postfix expression.
- Backtracking - Searching for solutions based on trial and error/brute force. Use stack instead of recursion.
	- Push the first possible move on the stack.
	- Repeatedly check if the current stack represents a complete and valid solution.
	- If not, try extending it by pushing a new move.
	- If no valid moves are left, backtrack by popping the last move and trying alternatives.

### Queues
**First in first out(FIFO)** - The first item added to the collection si the first one to be taken out.

#### Common operations
- `bool enqueue(Type x)` - Insert an item at the end.
- `Type dequeue()` - Removes and returns the item at the front.
- `Type peek()` - Returns the item at the front.
- `Type peekRear()` - Returns the item at the rear.
- `bool isEmpty()`
- `int getLength()`

#### Pseudocode Implementation
- Arrays
	- Queue starts at `arr[frontIndex]` and continue through `length` items. if the array's end is met before encountering all items, remaining items are stored starting at index 0.
		- You might also have a `rearIndex`.
	- Enqueue
		- Check if `length` equals `maxLength`
		- `arr[frontIndex + length] % arr.length() = x`
			- Increment rearIndex
			- Assign rearIndex with x
		- Increment length
	- Dequeue
		- Local var of `arr[frontIndex]`
		- Decrement `length`
		- Increment `frontIndex`, if greater than `arr.length()`, then set to 0.
		- Return local var
- Linked list
	- Enqueue
		- Crease a new node
		- Check if the creation worked
		- Assign the node's data with x
		- Assign the endNode->next to the new node
	- Dequeue
		- Local var of frontNode->data
		- Save the front node as the old front node
		- Assign frontNode to its next node
		- Delete the old front node
		- return the local var

		- What if there is only 1 node in the que?
			- If only 1 node, then rear = null

#### Common use cases

## Concrete data structures
Concrete data structures are specific implementations of ADTs that define how data is stored and how operations are performed on memory.

- **Array** - Ordered collection of elements with a max size.
- **Dynamic array** - An array without a max size.
- **Linked list** - Sequence of nodes where each node pointer to the next. Allows for faster insertion/deletion.
- **Record** - Stores named fields. Similar to objects in JS.
- **Binary Tree** - Each node stores data and has up to 2 children nodes.
- **Hash Table** - Maps keys to indexes using a hash function. Allows for fast lookups.
- **Heap** - Partially sorted trees.
	- **Max-Heap** - Parent node is greater than or equal to it's children.
	- **Min-Heap** - Parent node is less than or equal to it's children.
- **Graph** - Represents connection between items(vertices) connected by edges.