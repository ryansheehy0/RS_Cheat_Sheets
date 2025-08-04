[Home](../README.md#c)

# C++ Data Structures

<!-- TOC -->

- [Array](#array)
- [Vector](#vector)
- [List](#list)
- [Forward List](#forward-list)
- [Deque](#deque)
- [Stack](#stack)
- [Queue](#queue)
- [Sets and Maps](#sets-and-maps)
- [Priority Queue](#priority-queue)
- [Bitset](#bitset)
- [String and String View](#string-and-string-view)

<!-- /TOC -->

| C++ Data Structure | Underlying data structure                                        |
|--------------------|------------------------------------------------------------------|
| Vector/String      | Dynamic array                                                    |
| List               | Doubly linked list                                               |
| Forward List       | Singly linked list                                               |
| Deque              | Fixed size array blocks that are managed by an array of pointers |
| Stack/Queue        | Deque by default                                                 |
| Set/Map            | Red-Black Tree                                                   |
| Unordered Set/Map  | Hash table                                                       |
| Priority Queue     | Dynamic array                                                    |
| Bitset             | Array                                                            |

## [Array](#c-data-structures)
Fixed size container.

- `#include <array>`

| Method                                   | Description                                                                 |
|------------------------------------------|-----------------------------------------------------------------------------|
| Capacity                                 |                                                                             |
| `constexpr size_t size()`                | Number of elements.                                                         |
| Iterators                                |                                                                             |
| `iterator begin()` and `end()`           | Iterator to first element and one past the last. `v.begin() + size_t index` |
| `reverse_iterator rbegin()` and `rend()` | Returns the reverse iterators.                                              |
| Getting and Updating                     |                                                                             |
| `T& operator[size_t]`                    | Get element at index.                                                       |
| `T& at(size_t)`                          | Throws std::out_of_range error for invalid indexes.                         |
| `T* data()`                              | Pointer to underlying array.                                                |

## [Vector](#c-data-structures)
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
| `void push_back(const T&/T&&)`                 | Adds element to the end.                                                    |
| `T& emplace_back(ConstructorArgs...)`          | Constructs an object at the end.                                            |
| `iterator insert(iterator, const T&/T&&)`      | Insert element at iterator.                                                 |
| `void resize(size_t)`                          | Changes number of elements. Larger adds default or smaller removes.         |
| Getting and Updating                           |                                                                             |
| `T& operator[size_t]`                          | Get element at index.                                                       |
| `T& at(size_t)`                                | Throws std::out_of_range error for invalid indexes.                         |
| Remove                                         |                                                                             |
| `void pop_back()`                              | Removes the last element.                                                   |
| `void clear()`                                 | Removes all elements.                                                       |
| `iterator erase(iterator)`                     | Removes element and returns the element after the erased element.           |
| `iterator erase(iterator start, iterator end)` | Removes a range of elements.                                                |

- Getting the second to last element
	- `v.end()[-2]`
	- `v.rbegin()[1]`

## [List](#c-data-structures)
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
| `void push_back(const T&/T&&)`                 | Adds element to the end.                                          |
| `void push_front(const T&/T&&)`                | Adds element to the front.                                        |
| `T& emplace_back(ConstructorArgs...)`          | Constructs an object at the end.                                  |
| `T& emplace_front(ConstructorArgs...)`         | Constructs an object at the front.                                |
| `iterator insert(iterator, const T&/T&&)`      | Insert element at iterator.                                       |
| Remove                                         |                                                                   |
| `void pop_back()`                              | Removes the last element.                                         |
| `void pop_front()`                             | Removes the first element.                                        |
| `void clear()`                                 | Removes all elements.                                             |
| `iterator erase(iterator)`                     | Removes element and returns the element after the erased element. |
| `iterator erase(iterator start, iterator end)` | Removes a range of elements.                                      |

## [Forward List](#c-data-structures)
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
| `void push_front(const T&/T&&)`                      | Adds element to the front.                                              |
| `T& emplace_front(ConstructorArgs...)`               | Constructs an object at the front.                                      |
| `iterator insert_after(iterator, const T&/T&&)`      | Insert element after the iterator.                                      |
| Remove                                               |                                                                         |
| `void pop_front()`                                   | Removes the first element.                                              |
| `void clear()`                                       | Removes all elements.                                                   |
| `iterator erase_after(iterator)`                     | Removes element after and returns the element after the erased element. |
| `iterator erase_after(iterator start, iterator end)` | Removes a range of elements after start and up to end.                  |

## [Deque](#c-data-structures)
Fixed size array blocks that are managed by an array of pointers.

- `#include <deque>`

| Method                                         | Description                                                         |
|------------------------------------------------|---------------------------------------------------------------------|
| Capacity                                       |                                                                     |
| `size_t size()`                                | Number of elements.                                                 |
| `bool empty()`                                 | Is empty?                                                           |
| Iterators                                      |                                                                     |
| `iterator begin()` and `end()`                 | Iterator to first element and one past the last.                    |
| `reverse_iterator rbegin()` and `rend()`       | Returns the reverse iterators.                                      |
| Adding                                         |                                                                     |
| `void assign(size_t, const T&)`                | Clears and fills with count copies of value.                        |
| `void assign(initializer_list)`                | Clears and fills with initializer list elements.                    |
| `void push_back(const T&/T&&)`                 | Adds element to the end.                                            |
| `void push_front(const T&/T&&)`                | Adds element to the front.                                          |
| `T& emplace_back(ConstructorArgs...)`          | Constructs an object at the end.                                    |
| `T& emplace_front(ConstructorArgs...)`         | Constructs an object at the front.                                  |
| `iterator insert(iterator, const T&/T&&)`      | Insert element at iterator.                                         |
| `void resize(size_t)`                          | Changes number of elements. Larger adds default or smaller removes. |
| Getting and Updating                           |                                                                     |
| `T& operator[size_t]`                          | Get element at index.                                               |
| `T& at(size_t)`                                | Throws std::out_of_range error for invalid indexes.                 |
| Remove                                         |                                                                     |
| `void pop_back()`                              | Removes the last element.                                           |
| `void pop_front()`                             | Removes the first element.                                          |
| `void clear()`                                 | Removes all elements.                                               |
| `iterator erase(iterator)`                     | Removes element and returns the element after the erased element.   |
| `iterator erase(iterator start, iterator end)` | Removes a range of elements.                                        |

## [Stack](#c-data-structures)
- `#include <stack>`

| Method                             | Description                                                       |
|------------------------------------|-------------------------------------------------------------------|
| Capacity                           |                                                                   |
| `size_t size()`                    | Number of elements.                                               |
| `bool empty()`                     | Is empty?                                                         |
| Adding                             |                                                                   |
| `void push(const T&/T&&)`          | Adds element to the top.                                          |
| `void emplace(ConstructorArgs...)` | Constructs an element and puts it at the top.                     |
| Getting and Updating               |                                                                   |
| `T& top()`                         | Reference to top element.                                         |
| `void swap(stack&)`                | Swaps two stacks in constant time by swapping underlying members. |
| Remove                             |                                                                   |
| `void pop()`                       | Removes the top element.                                          |

## [Queue](#c-data-structures)
- `#include <queue>`

| Method                             | Description                                                       |
|------------------------------------|-------------------------------------------------------------------|
| Capacity                           |                                                                   |
| `size_t size()`                    | Number of elements.                                               |
| `bool empty()`                     | Is empty?                                                         |
| Adding                             |                                                                   |
| `void push(const T&/T&&)`          | Adds element to the back.                                         |
| `void emplace(ConstructorArgs...)` | Constructs an element and puts it to the back.                    |
| Getting and Updating               |                                                                   |
| `T& front()`                       | Reference to the front.                                           |
| `T& back()`                        | Reference to the back.                                            |
| `void swap(queue&)`                | Swaps two stacks in constant time by swapping underlying members. |
| Remove                             |                                                                   |
| `void pop()`                       | Removes the front element.                                        |

## [Sets and Maps](#c-data-structures)
- Sets - Stores elements
	- `#include <set>` - Sorted with red-black trees.
		- `set` - Unique elements
		- `multiset` - Duplicate elements
	- `#include <unordered_set>` - Unsorted with hash tables.
		- `unordered_set` - Unique elements
		- `unordered_multiset` - Duplicate elements
- Maps - Stores key-value pairs
	- `#include <map>` - Sorted keys with red-black trees.
		- `map` - Unique keys
		- `multimap` - Duplicate keys
	- `#include <unordered_map>` - Unsorted with hash table.
		- `unordered_map` - Unique keys
		- `unordered_multimap` - Duplicate keys

| Set Methods                                      | Description                                                       |
|--------------------------------------------------|-------------------------------------------------------------------|
| Capacity                                         |                                                                   |
| `size_t size()`                                  | Number of elements.                                               |
| `bool empty()`                                   | Is empty?                                                         |
| Iterators                                        |                                                                   |
| `iterator begin()` and `end()`                   | Iterator to first element and one past the last.                  |
| `reverse_iterator rbegin()` and `rend()`         | Returns the reverse iterators.                                    |
| Adding                                           |                                                                   |
| `std::pair<iterator, bool> insert(const T&/T&&)` | Iterator to inserted or existing element. Bool for success.       |
| `iterator emplace(ConstructorArgs...)`           | Constructs an object and inserts.                                 |
| Getting and Updating                             |                                                                   |
| `iterator find(const T&)`                        | Finds element by value.                                           |
| `size_t count(const T&)`                         | 1 if exists or 0 if not.                                          |
| Remove                                           |                                                                   |
| `void clear()`                                   | Removes all elements.                                             |
| `iterator erase(iterator)`                       | Removes element and returns the element after the erased element. |
| `iterator erase(iterator start, iterator end)`   | Removes a range of elements.                                      |

| Different map methods                             | Description                                                   |
|---------------------------------------------------|---------------------------------------------------------------|
| Adding                                            |                                                               |
| `pair<iterator, bool> insert(const pair<Key, T>)` | Inserts if element doesn't exists, else returns that element. |
| `iterator emplace(KeyArgs..., ValueArgs...)`      | Constructs an object and inserts.                             |
| Getting and Updating                              |                                                               |
| `T& operator[const Key&]`                         | Access or insert value by key.                                |

- Map methods replace `const T&` and `T&&` with `const pair<Key, T>&` and `pair<Key, T>&&`

| Unordered methods             | Description                                                                       |
|-------------------------------|-----------------------------------------------------------------------------------|
| `size_t bucket_count() const` | Number of buckets in the hash table.                                              |
| `float load_factor() const`   | num of elements / num of buckets                                                  |
| `void rehash(size_t)`         | Sets the number of buckets to at least the given size and rehashes the container. |

| Multi methods                                      | Description                                 |
|----------------------------------------------------|---------------------------------------------|
| `iterator insert(const T&/T&&)`                    | Allow you to insert duplicates.             |
| `size_t count(const T&)`                           | The number of elements.                     |
| `pair<iterator, iterator> equal_range(const Key&)` | Returns list of elements with the given key |
| `size_t erase(const Key&)`                         | Removes all elements with the given key     |

## [Priority Queue](#c-data-structures)
A max-heap by default that uses vector.

- `#include <queue>`

| Method                             | Description                                                                |
|------------------------------------|----------------------------------------------------------------------------|
| Capacity                           |                                                                            |
| `size_t size()`                    | Number of elements.                                                        |
| `bool empty()`                     | Is empty?                                                                  |
| Adding                             |                                                                            |
| `void push(const T&/T&&)`          | Adds element and reorders.                                                 |
| `void emplace(ConstructorArgs...)` | Construct an element and reorders.                                         |
| Getting                            |                                                                            |
| `const T& top()`                   | Access the top element.                                                    |
| `void swap(priority_queue&)`       | Swaps two priority queues in constant time by swapping underlying members. |
| Remove                             |                                                                            |
| `void pop()`                       | Removes the top element.                                                   |

- Change the type of heap
	- `priority_queue<int, vector<int>, greater<int>> minHeap;`

```C++
// Custom heap
struct Container {
	int key;
	int value;
};

struct Compare {
	bool operator()(const Container& c1, const Container& c2) const {
		return c1.key > c2.key;
	}
};

priority_queue<Container, vector<Container>, Compare> customHeap;
```

## [Bitset](#c-data-structures)
Fixed size sequence of bits which makes bitwise operations easier.

- `#include <bitset>`
- `std::bitset<8> bits; // Default: 00000000`

| Method                                  | Description                 |
|-----------------------------------------|-----------------------------|
| Capacity                                |                             |
| `size_t size()`                         | Number of bits.             |
| `bool any()`                            | Any bits set?               |
| `bool none()`                           | No bits are set?            |
| `bool all()`                            | All bits are set?           |
| Getting and Updating                    |                             |
| `bitset<N> set()`                       | Set all bits to 1.          |
| `bitset<N> set(size_t)`                 | Set bit at index to 1.      |
| `bool test(size_t)`                     | Get value at index          |
| `bitset<N>::reference operator[size_t]` | Get and change bit at index |
| `bitset<N> flip()`                      | Flips all bits              |
| `bitset<N> flip(size_t)`                | Flips bit at index          |
| `bitset<N> reset()`                     | Sets all bits to 0          |
| `bitset<N> reset(size_t)`               | Sets bit to 0 at index      |

## [String and String View](#c-data-structures)
- `#include <string>`
- `#include <string_view>` - Read only string that is just a pointer and size. It avoids heap allocation.

| Method                                           | Description                                                                 |
|--------------------------------------------------|-----------------------------------------------------------------------------|
| `size_t size()/length()`                         | Number of characters.                                                       |
| `bool empty()`                                   | Is empty?                                                                   |
| Iterators                                        |                                                                             |
| `iterator begin()` and `end()`                   | Iterator to first element and one past the last. `v.begin() + size_t index` |
| `reverse_iterator rbegin()` and `rend()`         | Returns the reverse iterators.                                              |
| Adding                                           |                                                                             |
| `=` or `+=`                                      | Equals or concatenate                                                       |
| `string& insert(size_t, const string&)`          | Inserts string starting at index, shifting existing chars.                  |
| Getting and Updating                             |                                                                             |
| `char& operator[size_t]`                         | Get characters                                                              |
| `char& at(size_t)`                               | Can throw an invalid index error                                            |
| `const char* c_str()`                            | Returns C-style null terminating string                                     |
| `string& replace(size_t, size_t, const string&)` | Replace len(2nd arg) chars starting at pos(1st arg) with the string.        |
| `size_t find(const string&, size_t pos = 0)`     | Returns the index of the first match or `std::string::npos`                 |
| Removing                                         |                                                                             |
| `void pop_back()`                                | Removes last character                                                      |
| `void clear()`                                   | Removes all elements.                                                       |
| `iterator erase(iterator)`                       | Removes element and returns the element after the erased element.           |
| `iterator erase(iterator start, iterator end)`   | Removes a range of elements.                                                |
| Converting                                       |                                                                             |
| `string(size_t, char)`                           | Convert char to string and repeats char size_t times.                       |
| `string(const char*)`                            | Convert null terminating character array to string                          |
| `int stoi(string)`                               | String to int                                                               |
| `unsigned int stoul(string)`                     | String to unsigned int                                                      |
| `double stod(string)`                            | String to double                                                            |
| `string to_string(int/float/double/etc)`         | Converts to string                                                          |
| `const char* data()`                             | Pointer to the underlying chars. Used for string_view                       |

- Constructing a string view
	- `string_view name(str.data() + index, count)` - Constructs a string_view starting at the character and spanning count characters.
- `istream& getline(istream&, string&, char delim = '\n')` - Reads characters from istream into string until delim or EOF.