[Home](../README.md#data-structures)

# Concrete Data Structures
Concrete data structures are data structures that have specific implementations that define exactly how data is stored and accessed. They are usually used to create abstract data structures.

The 4 most common operations are create/add/insert, read/get/access, update, and delete/remove. Commonly abbreviated as **CRUD**.

- Ordered vs sorted
	- Ordered means that the data structure retains the order in which elements are added.
		- Ex: A bag is unordered. Cubby boxes are ordered.
	- Sorted means that the ordering is arranged in a specific way.

<!-- TOC -->

- [Common CDSs](#common-cdss)
- [Types of linked lists](#types-of-linked-lists)
- [Binary Trees](#binary-trees)

<!-- /TOC -->

## Common CDSs

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

## Types of linked lists
- Singly vs Doubly - A node has a singly pointer to the next node, or double pointers pointing to the next and previous.
- Circular - The tail's next points to the head. And for doubly, the head's prev points to the tail.
- Multi - Each node contains multiple pointers, allowing for traversals with different ordering.
	- Ex: Each node contains an author and a book title. One linked list is ordered based on the author while the other is ordered based on the book title.
	- This can also be done with binary search trees.

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