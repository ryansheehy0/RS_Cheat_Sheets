[Home](../README.md)

# Abstract Data Structures
Abstract data types(ADTs) define which operation can be used, but not how the data is to be stored and organized.

<!-- TOC -->

- [Stack](#stack)
	- [Common operations](#common-operations)
	- [Common use cases](#common-use-cases)
- [Queues](#queues)
	- [Common operations](#common-operations)
	- [Common use cases](#common-use-cases)
- [Lists](#lists)
	- [Common operations](#common-operations)
	- [Common use cases](#common-use-cases)

<!-- /TOC -->

- **Priority Queue** - A queue where each item has a priority and items with higher priority dequeue first.
- **Double-ended Queue(Deque)** - Items can be inserted and removed from both the front and back.
- **Bag/Multiset** - Unordered collection that allows for duplicates.
- **Set** - Unordered collection of unique items.
- **Map/Dictionary** - Key value pairs with unique keys.

## Stack
Items are only inserted on or removed from the top.

**Last in first out(LIFO)** - The last item added to the collection is the first one to be taken out.

### Common operations
- `bool push(Type x)` - Inserts x on the top of the stack.
- `Type pop()` - Removes and returns the stack's top item.
	- Need to check that the stack isn't empty before calling.
- `Type peek()` - Returns the stack's top item without removing it.
	- Need to check that the stack isn't empty before calling.
- `bool isEmpty()`
- `int getLength()`
	- The stack usually increments or decrements the length when you push/pop.

### Common use cases
- Reversing a stack
	- Push and pop into another stack(stackA)
	- Push and pop into another stack(stackB)
	- Push and pop into the original stack
	- Or push and pop into an queue, then push and pop the queue back on the original stack.
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

## Queues
Items are only inserted at the end and removed from the front.

**First in first out(FIFO)** - The first item added to the collection si the first one to be taken out.

### Common operations
- `bool enqueue(Type x)` or `push` - Insert an item at the end.
- `Type dequeue()` or `pop` - Removes and returns the item at the front.
- `Type peek()` - Returns the item at the front.
- `bool isEmpty()`
- `int getLength()`

### Common use cases
- Categorizing data
	- Ex: Put positive numbers in one category and negative numbers in another while preserve the original order.
- OS maintain a queue of processes waiting to be executed.
- Used for buffers which is a temporary holding area for data being transferred from one place to another.
	- Data comes in sequentially, processed, then stored in a buffer thats a queue because it preserves the ordering.
- Simulating real world lines.
	- Ex: Customers waiting in line or cars at a traffic light.

## Lists

- **List** - Ordered collection that allows for access via index.
- All have to have unique values?
	- Should the operations use indexes instead of values?

### Common operations
- `bool append(Type x)` - Adds x to the end.
- `bool prepend(Type x)` - Adds x to the beginning.
- `bool insertAfter(Type w, Type x)` - Inserts x after w.
- `void remove(Type x)`
- `bool contains(Type x)`
- `void print()`
- `void sort()` - Sorts in ascending order.
- `bool isEmpty()`
- `int getLength()`

- insert
- delete
- search
- traverse

### Common use cases
