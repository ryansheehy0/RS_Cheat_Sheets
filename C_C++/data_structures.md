[Home](../README.md)

# Data Structures
- Can be implemented with arrays or pointers(linked lists)

## Stack
- push
- pop
- peek - Look at the top without popping it
- getLength - keep track when you push and pop
- isEmpty

```C++
bool push(int data) {
	// Make a new node
	int* newNode = new int;
	// Check if the creation of the new node was successful
	// Copy data into the new node
	newNode.data = data;
	// Point the top to the new node
	// Move the top the new node
	// Update the length
	length++;
}
```

- Reversing a stack if you don't have the member variables.
	- Push and pop into another stack(stackA)
	- Push and pop into another stack(stackB)
	- Push and pop into the original stack
- Stack applications
	- Checking for unmatched parentheses.
		- Push open pars, if close par then pop.
		- If not empty then unmatched pars.
	- Convert infix() to posfix()