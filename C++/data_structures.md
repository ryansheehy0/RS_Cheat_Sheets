[Home](../README.md#c)

# C++ Data Structures

CRUD
	- Creating/Adding/Inserting
	- Read/Get
	- Update
	- Delete/Remove
- What is T&&
- What is an initializer list? Using {}s

<!-- TOC -->

- [Vector](#vector)
- [List](#list)
- [Forward List](#forward-list)
- [Other](#other)

<!-- /TOC -->

| C++ Data Structure | Underlying data structure |
|--------------------|---------------------------|
| Vector             | Dynamic array             |
| List               | Doubly linked list        |
| Forward List       | Singly linked list        |

## Vector
Dynamic arrays. Size doubles once full.

- `#include <vector>`

| Method                                         | Description                                                                 |
|------------------------------------------------|-----------------------------------------------------------------------------|
| Capacity                                       |                                                                             |
| `size_t size()`                                | Number of elements.                                                         |
| `bool empty()`                                 | Is empty?                                                                   |
| Iterators                                      |                                                                             |
| `iterator begin()` and `end()`                 | Iterator to first element and one past the last. `v.begin() + size_t index` |
| `reverse_iterator rbegin()` and `rend()`       | Returns the reverse iterators.                                              |
| Adding                                         |                                                                             |
| `void assign(size_t, const T&)`                | Clears and fills with count copies of value.                                |
| `void assign(initializer_list)`                | Clears and fills with initializer list elements.                            |
| `void push_back(T&&)`                          | Adds element to the end.                                                    |
| `void insert(iterator, T&&)`                   | Insert element at iterator.                                                 |
| `void resize(size_t)`                          | Changes number of elements. Larger adds default or smaller removes.         |
| Getting and Updating                           |                                                                             |
| `T& operator[size_t]`                          | Get element at index.                                                       |
| `T& at(size_t)`                                | Throws out_or_range error for invalid indexes.                              |
| Remove                                         |                                                                             |
| `void pop_back()`                              | Removes the last element.                                                   |
| `void clear()`                                 | Removes all elements.                                                       |
| `iterator erase(iterator)`                     | Removes element and returns the element after the erased element.           |
| `iterator erase(iterator start, iterator end)` | Removes a range of elements.                                                |

- Getting the second to last element
	- `v.end()[-2]`
	- `v.rbegin()[1]`

## List
Doubly linked list

- `#include <list>`

| Method                                         | Description                                                       |
|------------------------------------------------|-------------------------------------------------------------------|
| Capacity                                       |                                                                   |
| `size_t size()`                                | Number of elements.                                               |
| `bool empty()`                                 | Is empty?                                                         |
| Iterators                                      |                                                                   |
| `iterator begin()` and `end()`                 | Iterator to first element and one past the last.                  |
| `reverse_iterator rbegin()` and `rend()`       | Returns the reverse iterators.                                    |
| Adding                                         |                                                                   |
| `void assign(size_t, const T&)`                | Clears and fills with count copies of value.                      |
| `void assign(initializer_list)`                | Clears and fills with initializer list elements.                  |
| `void push_back(T&&)`                          | Adds element to the end.                                          |
| `void push_front(T&&)`                         | Adds element to the front.                                        |
| `void insert(iterator, T&&)`                   | Insert element at iterator.                                       |
| Remove                                         |                                                                   |
| `void pop_back()`                              | Removes the last element.                                         |
| `void pop_front()`                             | Removes the first element.                                        |
| `void clear()`                                 | Removes all elements.                                             |
| `iterator erase(iterator)`                     | Removes element and returns the element after the erased element. |
| `iterator erase(iterator start, iterator end)` | Removes a range of elements.                                      |

## Forward List
Singly linked list

- `#include <forward_list>`

| Method                                               | Description                                                             |
|------------------------------------------------------|-------------------------------------------------------------------------|
| Capacity                                             |                                                                         |
| `bool empty()`                                       | Is empty?                                                               |
| Iterators                                            |                                                                         |
| `iterator begin()` and `end()`                       | Iterator to first element and one past the last.                        |
| Adding                                               |                                                                         |
| `void assign(size_t, const T&)`                      | Clears and fills with count copies of value.                            |
| `void assign(initializer_list)`                      | Clears and fills with initializer list elements.                        |
| `void push_front(T&&)`                               | Adds element to the front.                                              |
| `void insert_after(iterator, T&&)`                   | Insert element after the iterator.                                      |
| Remove                                               |                                                                         |
| `void pop_front()`                                   | Removes the first element.                                              |
| `void clear()`                                       | Removes all elements.                                                   |
| `iterator erase_after(iterator)`                     | Removes element after and returns the element after the erased element. |
| `iterator erase_after(iterator start, iterator end)` | Removes a range of elements after start and up to end.                  |

## Other
- deque - double ended queue
- Maps/sets
	- map - Stores sorted key-value pairs.(red-black trees).
	- unordered_map - Stores unsorted key-value pairs.(hash table).
	- multimap - Allows duplicate keys.
	- set - Stores sorted unique elements(red-black trees).
	- unordered_set - Unsorted unique elements(hash table).
	- multiset - Allows duplicate values.
- stack
- queue
- priority_queue - max heap
	- How to set to min heap or custom heap? provide a cusom comparator.
- bitset - Space efficient fixed siz sequence of bits. Make bitwise operations easier.
- Other
	- pair - Key value pair
	- tuple - Fixed size collection of values of potentially different types.
		- Useful for returning multiple values form a function. You don't have to define a struct.
- string
- And string_view
- array - Stack array