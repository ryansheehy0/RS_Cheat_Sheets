[Home](../README.md)

# Data Structures
- Define a certain domain of values.
- Defines what operations are allowed.


- Can be implemented with arrays or pointers(linked lists)

- organizing, storing, and performing operations on data
	- accessing, updating, searching, inserting, removing.
	- get/read, update, add/insert, delete/remove
- Basic data structures
	- record - Stores subitems called fields with a name associated with each subitem.(Objects in js).
	- array - Ordered(not necessarily sorted) collection of elements
	- Linked list
		- Fast insertion of data because it avoids the shifting problem.
	- Binary tree - Each node stores data and has up to 2 children nodes
	- Hash table - Stores unordered items by mapping each item to a location in an array
	- Heap
		- Max-heap is a tree that has the parent node greater than or equal to it's children.
		- Min-heap is a tree that has the parent node less than or equal to it's children.
	- Graph - Represents connections among items. Vertices(item in a graph) connected by edges(connection between 2 vertices).
- Algo - Sequence of steps for solving a computational problem. Computation problem - inputs, a question about the input that can be answered using a computer, and the desired output.

- Algo with a polynomial runtime is efficient.
- NP-complete problems - Set of problems which no known efficient algo exists.
	- No efficient algo has been found.
	- No one has proven than an efficient algo is impossible.
	- If an efficient alo exists for one NP problem, then all NP problems can be solved efficiently.

- Ordered - Retain the order in which they were added into the data structure.
	- Ex: A bad is unordered because you pull things out in no particular order, while bubby boxes are ordered, you place items in specific spots.
- Sorted - The ordering is arranged in a specific way.

## Concrete data structures
- Specify how data is to be organized and stored in memory.


## Abstract data types
- Models for data structures that define which operation can be used, but not how they'are to be implemented.

- List - Holds ordered data
- Dynamic array - Ordered data and allowing indexed access.
- Queue - Items are only inserted at the end and removed from the front.
- Deque(deck) - Items can be inserted and removed from both the front and back.
- Bag - Storing items which the order doesn't matter and duplicate items are allowed.
- Set - Collection of distinct items.
- Priority queue - Queue where each item has a priority and items with higher priority are closer to the front.
- Dictionary/Map - Key value pairs.

### Stack
Items are only inserted on or removed from the top.
- **Last in first out(LIFO)** - The last item added to the collection is the first one to be taken out.

#### Common operation
- push(x) - Inserts x on the top of the stack.
- pop() - Removes and returns the stack's top item.
	- Should be preceded by a check that the stack isn't empty.
- peek() - Returns the stack's top item without removing it.
- isEmpty() - True if the stack is empty
- getLength() - Returns the number of items in the stack.
	- The stack usually increments or decrements the length when you push/pop.

#### Implementation
- Arrays
	- A bounded stack has a max size, which is usually the array's initial allocation size.
	- The top of the stack is at the back of the array to prevent the need for shifting everything over.
	- push
		- Increment the top index
		- Assign the top with value
	- pop
		- Decrement the top index
	- getLength
		- Return the top index + 1
- Linked lists
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


#### Use cases

- Reversing a stack if you don't have the member variables.
	- Push and pop into another stack(stackA)
	- Push and pop into another stack(stackB)
	- Push and pop into the original stack
- Stack applications
	- Checking for unmatched parentheses.
		- Push open pars, if close par then pop.
		- If not empty then unmatched pars.
		- You can't just count because the order of the open/closed pars might not be correct.
	- Convert infix(a + b) to postfix(a b +). prefix(+ a b)
		- Useful for compilers.
		- Reverse polish notation is the same as postfix.
			- Don't need any pars to specify order of operations.
		- a + 5 * b -> a 5 b * +
		- Push variables onto output stack.
		- Push operators onto the stack. If higher precedence, then push on top. If not, push to output.
			- If closing pars, then pop everything to output until next opening par.
	- 