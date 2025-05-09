# Concrete data structures
Concrete data structures are data structures that 

Data structures store data in an organized way, define the types of values that can be stored, and specify the operations that can be performed on that data.

The 4 most common operations are create/add/insert, read/get/access, update, and delete/remove. Commonly abbreviated as CRUD.
	- IGUD
	- IGUR

**Ordered** means that the data structure retains the order in which elements are added.
- Ex: A bad is unordered because you pull things out in no particular order, while cubby boxes are ordered, you place items in specific spots.
**Sorted** means that the ordering is arranged in a specific way.

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

- Is there a data structure that takes into account the frequency at which things are looked up in and organizes things so that more frequently looked up things appear closer tot he root?
	- You can also construct it with a frequency.
	- Splay trees operate based on recency, not frequency.

- These 
	- Array
	- DynamicArray
	- SinglyLinkedList
	- DoublyLinkedList
	- BinaryTree
	- BinarySearchTree
	- AVLTree
	- RedAndBlackTree

## Binary Trees
- Vocabulary
	- **Leaf** - A node with no children.
	- **Internal node** - A node with at least one child.
	- **Root** - The node with no parent. At the top.
	- **Edge** - The link from a node to a child node.
	- A node's **depth** - Number of edges from it to the root. The root has 0 depth.
	- **Levels** - Nodes with the same depth. Levels start at 0.
	- The tree's **height** - Largest depth of any node.
- Types of binary trees
	- **Full** - Every node has 0 or 2 children
	- **Complete** - All levels, except the last, contain all possible nodes.
		- Nodes need to be as far left as possible.
		- There can only be blank spaces on the right side for the total binary tree.
			- There are no gaps on the last level.
	- **Perfect** - All internal nodes have 2 children and all leaf nodes are on the same level.



```
This is not complete because there is space on the left side of the whole binary tree.
           *
      /         \
     *           *
   /   \       /   \
  *     *     *     *
 /     /     /     /
*     *     *     *
```

```
This is complete because the only space is on the right side.
           *
      /         \
     *           *
   /   \       /   \
  *     *     *     *
 / \   / \
*   * *   *
```

Binary space partitioning(BSP)
- Only a few objects in a 2d world should be visible on screen.
- Rendering off screen objects is bad.
- Checking the intersection for all objects with the screen takes too long.
- The root of the binary tree represents all objects in the world.
	- The left child contains all objects on the left half.
	- The right child contains all objects on the right half.
- The screen position can be used to quickly narrow down which objects to check because they aren't anywhere close to the screen.


- Successor - If you ordered the BST node from less than to greater than, it would be before another node.
- Predecessor - If you ordered the BST node from less than to greater than, it would be after another node.

Use cases:
	- Trees can represent hierarchical data, like files and folders.
		- Not binary trees.


- Convert regular tree to binary tree
	- Keep the left children.
	- Link sibling nodes together to their right children.

Applications of binary trees
	- Internal nodes are operations.
	- Leafs are constants
	- Depth first
		- preorder traversal - polish notation
		- inorder traversal - regular math notation with parentheses
	- Huffman codes
		- Go through text and count the frequency of characters
		- 