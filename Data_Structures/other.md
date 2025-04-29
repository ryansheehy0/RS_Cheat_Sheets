Data structures store data in an organized way, define the types of values that can be stored, and specify the operations that can be performed on that data.

The 4 most common operations are create/add/insert, read/get/access, update, and delete/remove. Commonly abbreviated as CRUD.
	- IGUD
	- IGUR

**Ordered** means that the data structure retains the order in which elements are added.
- Ex: A bad is unordered because you pull things out in no particular order, while cubby boxes are ordered, you place items in specific spots.
**Sorted** means that the ordering is arranged in a specific way.

## Concrete data structures
Concrete data structures are specific implementations of ADTs that define how data is stored and how operations are performed on memory.

- **Array** - Ordered collection of elements with a max size.
- **Dynamic array** - An array without a max size.
- **Linked list** - Sequence of nodes where each node pointer to the next. Allows for faster insertion/deletion.
	- Singly linked list - Each node has a pointer to the next node.
	- Doubly linked list - Each node has two pointers, one for its parent and one for the next node.
- **Record** - Stores named fields. Similar to objects in JS.
- **Binary Tree** - Each node stores data and has up to 2 children nodes.
- **Hash Table** - Maps keys to indexes using a hash function. Allows for fast lookups.
- **Heap** - Partially sorted trees.
	- **Max-Heap** - Parent node is greater than or equal to it's children.
	- **Min-Heap** - Parent node is less than or equal to it's children.
- **Graph** - Represents connection between items(vertices) connected by edges.

- Multi linked list
	- With 2 or more logical links
	- Ex: Each node contains an author and a book title.
		- One linked list is sorted based on the author while a separate linked list is sorted based on the book title.
			- Each linked list shares the same memory, they just have different ordering.

- Accessing
	- Arrays: Fast(direct)
	- Linked list: slow(walking)
- Searching
	- Arrays: Fast(Binary)
	- Linked list: Slow(Linear)
		- Why not binary for a doubly linked list?
- Inserting
	- Arrays: Slow(Shifting)
	- Linked list: Fast(Move pointers)
- Deleting
	- Arrays: Slow(Shifting)
	- Linked list: Fast(Move pointers)

### Linked List

- First node is called the head and last is called the tail.
- They often contain a sentinel node, a dummy node that is always set as the head.
	- This removes the need for methods to check if the list is empty or not.

- Append - Put at end.
	- If the list is empty, both the head and tail are assigned the new node.
	- If the list isn't empty, the tail's next node is assign, then the tail is assigned the new node.
- Prepend - Put at start.
	- If the list is empty, both the head and tail are assigned the new node.
	- If the list isn't empty, new node's next node is assign the head, then the head is assigned the new node.
- `ListNode search(Type value)` - Returns the first node that matches the value. nullptr is returned if nothing is found.
- `bool insertAfter(Type searchedValue, Type newValue)` - Inserts a new node with new value after the first node that has searched value.
	- If the list is empty, the head and tail are set to the new node.
	- If the searchedValue is the tail, the tail's next is set to the new node, then the tail is set to the new node.
	- If inserting in the middle of the list, the new node's next needs to be set to the searched node's next, then the searched node's next needs to be set to the new node.
	- If the searched Value isn't found, then it returns false and doesn't change the list.
	- If the list is empty, you can pass in null.

```C++
ListInsertNodeAfter(list, currentNode, newNode) {
   // Special case for empty list
   if (list⇢head == null) {
      list⇢head = newNode
      list⇢tail = newNode
   }
   else if (currentNode == list⇢tail) {
      list⇢tail⇢next = newNode
      list⇢tail = newNode
   }
   else {
      newNode⇢next = currentNode⇢next
      currentNode⇢next = newNode
   }
}
```

```C++
ListInsertAfter(list, currentItem, newItem) {
   currentNode = ListSearch(list, currentItem)
   if (currentNode != null) {
      newNode = Allocate new singly-linked list node
      newNode⇢data = newItem
      newNode⇢next = null
      ListInsertNodeAfter(list, currentNode, newNode)
      return true
   }
   return false
}
```

- `void removeAfter(Type value)` - Removes the node after the value.
	- If null, it removes the 1st node.
	- If value is the tail, then it doesn't remove anything.
	- Have to make sure the list isn't empty.

```C++
ListRemoveNodeAfter(list, curNode) {
   // Special case, remove head
   if (curNode is null) {
      sucNode = list⇢head⇢next
      list⇢head = sucNode

      if (sucNode is null) { // Removed last item
         list⇢tail = null
      }
   }
   else if (curNode⇢next is not null) {
      sucNode = curNode⇢next⇢next
      curNode⇢next = sucNode

      if (sucNode is null) { // Removed tail
         list⇢tail = curNode
      }
   }
}
```

```C++
ListRemove(list, itemToRemove) {
   // Traverse to the node with data equal to itemToRemove, 
   // keeping track of the previous node in the process
   previous = null
   current = list⇢head
   while (current != null) {
      if (current⇢data == itemToRemove) {
         ListRemoveNodeAfter(list, previous)
         return true
      }
         
      // Advance to next node
      previous = current
      current = current⇢next
   }
      
   // Not found
   return false
}
```

#### Pseudocode Implementation of stack
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

#### Pseudocode Implementation of Queue
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