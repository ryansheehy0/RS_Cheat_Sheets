[Home](../README.md)

# Singly Linked List
This is meant to be a simple implementation of a singly linked list, not a full one.

<!-- TOC -->

- [Constructor](#constructor)
- [Destructor](#destructor)
- [Inserting](#inserting)
	- [Push Back](#push-back)
	- [Push Front](#push-front)
	- [Insert Sort](#insert-sort)
- [Removing](#removing)
	- [Pop Front](#pop-front)
	- [Pop Back](#pop-back)
	- [Remove](#remove)
- [Applications](#applications)

<!-- /TOC -->

```C++
template <typename T>
class SinglyLinkedList {
	private:
		Node* head;
		Node* tail;
		int length;

	public:
		struct Node {
			T data;
			Node* next = nullptr;
		};

		SinglyLinkedList();
		~SinglyLinkedList();

		// Getters
		int getLength() const { return length; };
		bool isEmpty() const { return length == 0; };
		T peek() const { return head->next->data; }; // Assumes the list isn't empty
		T peekRear() const { return tail->data; }; // Assumes the list isn't empty

		// Inserting
		bool pushBack(T value);
		bool pushFront(T value);

		bool insertSort(T value); // Arranges from least to greatest.

		// Removing
		T popFront(); // Assumes the list isn't empty
		T popBack(); // Assumes the list isn't empty

		bool remove(T value);
		bool removeSorted(T value);
};
```

- Other common methods
	- `bool contains(T value) const;`
	- `void print() const;`
	- `void sort();`
	- `bool removeAll(T value)`
	- Iterators
	- `Node<T>* search(T value);` and `Node<T>* searchSorted(T value);`
	- Traversals
		- Applies a function to all data in the linked list.

## Constructor
A sentinel node is a dummy node that is always set as the head. This removes the need for methods to check if the list is empty or not.

```C++
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	Node<T>* sentinel = new Node; // Create sentinel node
	head = sentinel;
	tail = sentinel;
	length = 0;
}
```

## Destructor
Loop through the linked list, freeing every node.

```C++
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	while (head) {
		Node<T>* deletedNode = head;
		head = head->next;
		delete deletedNode;
	}
}
```

## Inserting

### Push Back

```C++
template <typename T>
bool SinglyLinkedList<T>::pushBack(T value) {
	Node<T>* newNode = new Node; // Create new node
	if (!newNode) return false; // Check if the creation worked
	newNode->data = value;
	tail->next = newNode; // Set tail's next to the next node
	tail = newNode; // Change the tail to the new node
	length++;
	return true;
}
```

### Push Front

```C++
template <typename T>
bool SinglyLinkedList<T>::pushFront(T value) {
	Node<T>* newNode = new Node; // Create new node
	if (!newNode) return false; // Check if the creation worked
	newNode->data = value;
	newNode->next = head; // Point new node's next to the head
	head = newNode; // Change the head
	length++;
	return true;
}
```

### Insert Sort

```C++
template <typename T>
bool SinglyLinkedList<T>::insertSort(T value) {
	// Make sure you can create the new node
	Node<T>* newNode = new Node; // Create new value
	if (!newNode) return false;
	// Find where to insert the new node
	Node<T>* prevNode = head;
	Node<T>* curNode = head->next; // Skip the sentinel
	while (curNode && curNode->data < value) {
		// Move to next node
		prevNode = curNode;
		curNode = curNode->next;
	}
	// Insert the new node
	newNode->data = value;
	newNode->next = curNode; // Set the new node's next to the curNode
	prevNode->next = newNode; // Set the previous node's next node to the new node
	length++;
	return true;
}
```

## Removing

### Pop Front

```C++
template <typename T>
T SinglyLinkedList<T>::popFront() {
	T value = head->next->data; // Skip the sentinel
	Node<T>* oldHead = head->next;
	head->next = head->next->next;
	if (length == 1) rear = head; // Point back to the sentinel
	delete oldHead;
	length--;
	return value;
}
```

### Pop Back

```C++
template <typename T>
T SinglyLinkedList<T>::popBack() {
	// Find the previous node before the tail
	Node<T>* prevNode = head;
	Node<T>* curNode = head->next; // Skip the sentinel
	while (curNode != tail) {
		prevNode = curNode;
		curNode = curNode->next;
	}
	T value = tail->data; // Skip the sentinel
	Node<T>* oldTail = tail;
	tail = prevNode;
	delete oldTail;
	length--;
	return value;
}
```

### Remove

```C++
template <typename T>
bool SinglyLinkedList<T>::remove(T value) {
	Node<T>* prevNode = head;
	Node<T>* curNode = head->next;
	while (curNode) {
		if (curNode->data == value) {
			prevNode->next = curNode->next;
			if (curNode == tail) tail = prevNode;
			delete curNode;
			length--;
			return true;
		}
		prevNode = curNode;
		curNode = curNode->next;
	}
	return false;
}
```

- Remove sorted can exit early.

```C++
template <typename T>
bool SinglyLinkedList<T>::removeSorted(T value) {
	Node<T>* prevNode = head;
	Node<T>* curNode = head->next; // Skip sentinel
	while (curNode && curNode->data < value) { // Skip all nodes who's data is less than the target
		prevNode = curNode;
		curNode = curNode->next;
	}
	if (curNode && curNode->data == value) {
		prevNode->next = curNode->next;
		if (curNode == tail) tail = prevNode;
		delete curNode;
		length--;
		return true;
	}
	return false;
}
```

## Applications
- Linked lists can be implemented with arrays instead of pointers
	- Each array element has data and the index to the next node.
	- When you insert, you look for an empty cell.
- Working with large numbers
	- Each node stores a digit or groups of digits.
- Operations on polynomials
	- Each node represents a term with a coefficient and exponent.
- Text processing
	- Characters or lines are nodes, allowing for efficient insertion and deletion without shifting.
- Heap management for OSs