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

<!-- /TOC -->

```C++
template <typename T>
class SinglyLinkedList {
	private:
		struct Node {
			T data;
			Node* next = nullptr;
		};

		Node* head;
		Node* tail;
		int length;

	public:
		SinglyLinkedList();
		~SinglyLinkedList();

		// Getters
		int length() const { return length; };
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
}
```

- Other common methods
	- `bool contains(T value) const;`
	- `void print() const;`
	- `void sort();`
	- `bool removeAll(T value)`
	- Iterators

## Constructor
A sentinel node is a dummy node that is always set as the head. This removes the need for methods to check if the list is empty or not.

```C++
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	Node<T>* sentinel = new Node<T>; // Create sentinel node
	head = sentinel;
	tail = nullptr;
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
	// Find where to insert the new node
	Node<T>* prevNode = head;
	Node<T>* curNode = head->next; // Skip the sentinel
	while (curNode) {
		if (curNode->data > value) break;
		// Move to next node
		prevNode = curNode;
		curNode = curNode->next;
	}
	// Insert the new node
	Node<T>* newNode = new Node; // Create new value
	if (!newNode) return false;
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