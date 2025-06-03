[Home](../README.md#data-structures)

# Concrete Data Structures
Concrete data structures are data structures that have specific implementations that define exactly how data is stored and accessed. They are usually used to create abstract data structures.

The 4 most common operations are create/add/insert, read/get/access, update, and delete/remove. Commonly abbreviated as **CRUD**.

- Ordered vs sorted
	- Ordered means that the data structure retains the order in which elements are added.
		- Ex: A bag is unordered. Cubby boxes are ordered.
	- Sorted means that the ordering is arranged in a specific way.

DataStructure: Iterators and overload ++ operator for traversals. bool allowDuplicates
   BinaryTree: traversal methods
      BinarySearchTree: insert/remove/search and rebalance
         AVLTree: override insert/remove and remove rebalance
         RedBlackTree: override insert/remove and remove rebalance
   MinHeap and MaxHeap
      PriorityQueue(KeyType key, DataType data) uses heaps
   SinglyLinkedList and DoublyLinkedList
      Stack and Queue uses SinglyLinkedList
   DynamicArray
   HashTable(KeyType key, DataType data, hashFunc): If the KeyType is string or int, then it can use default hash functions.
   Graph
   BTree and BPlusTree


<!-- TOC -->

- [Common CDSs](#common-cdss)
- [Types of linked lists](#types-of-linked-lists)
- [Binary Trees](#binary-trees)
	- [Applications](#applications)

<!-- /TOC -->

## [Common CDSs](#concrete-data-structures)

- **Array** - Ordered collection of elements, usually stored on the stack, with a max size.
	- Inserting, deleting: O(n) when needing to shift. O(1) when inserting on the end.
	- Reading, updating: O(1). Direct memory access.
- **Dynamic array** - An array without a max size.
- **Linked list** - Sequence of nodes where each node points to the next. Can be implemented with arrays or pointers.
	- Inserting, deleting: O(n), but O(1) when inserting on the front or end.
	- Reading, updating: O(n)
- **Trees**
	- **Binary Trees**
		- **Binary Search Trees**
			- **AVL**
			- **Black and Red**
			- **Frequency** - The tree is reordered based on the frequency of readings. Higher frequency gets closer to the root.
		- **Heaps**
	- **B Trees**
		- **B+ Trees**
- **Hash Table** - Maps keys to indexes using a hash function.
	- Reading, updating: O(1). Rarely O(n)
- **Graph** - Represents connection between items(vertices) connected by edges.

## [Types of linked lists](#concrete-data-structures)
- Singly vs Doubly - A node has a singly pointer to the next node, or double pointers pointing to the next and previous.
- Circular - The tail's next points to the head. And for doubly, the head's prev points to the tail.
- Multi - Each node contains multiple pointers, allowing for traversals with different ordering.
	- Ex: Each node contains an author and a book title. One linked list is ordered based on the author while the other is ordered based on the book title.
	- This can also be done with binary search trees.

## [Binary Trees](#concrete-data-structures)
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
		- The nodes on the last need to be as far left as possible.
	- **Perfect** - All internal nodes have 2 children and all leaf nodes are on the same level.

 ```
        Not Complete                Complete                    Perfect
             *                         *                           *
        /         \               /         \                 /         \
       *           *             *           *               *           *
     /   \       /   \         /   \       /   \           /   \       /   \
    *     *     *     *       *     *     *     *         *     *     *     *
   /     /     /     /       / \   / \                   / \   / \   / \   / \
  *     *     *     *       *   * *   *                 *   * *   * *   * *   *
 ```

### [Applications](#concrete-data-structures)
- Huffman codes
- Non-binary tree can represent files and folders
- Converting back and forth between polish notation and regular math notation
	- Internal nodes are the operations, leaf nodes are constants/variables.
	- Pre-ordered depth first traversal creates the polish notation.
	- In order depth first traversal creates the regular math notation with parentheses.
- Converting regular trees to binary trees
	- Keep the left children.
	- Link siblings nodes together through their right child.
- Binary space partitioning(BSP)
	- Only a few objects in a 2d world should be visible on screen.
	- Rendering off screen objects is bad.
	- Checking the intersection for all objects with the screen takes too long.
	- The root of the binary tree represents all objects in the world.
		- The left child contains all objects on the left half.
		- The right child contains all objects on the right half.
	- The screen position can be used to quickly narrow down which objects to check because they aren't anywhere close to the screen.