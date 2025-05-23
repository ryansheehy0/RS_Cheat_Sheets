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
	- [Applications](#applications)
- [Hash tables](#hash-tables)

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

## Hash tables
- Hash tables use a lot of memory for faster operations.

- All keys are stores in the range Ex: [0-9].
- Can use a fixed size array to store elements.
- Searching takes O(1) time assuming there are no more than one element in the cell

- Hash tables store unordered items by mapping/hashing each item to a location called a bucket.
- A hash map is an implementation of a map ADT using a hash table.
	- What is a map adt? Key value pairs.

- hashCode = hash(value)
- index = hashCode % arraySize

- Collision - 2 different keys map to the same bucket index.
	- Chaining - Each bucket has a list of items
	- Open addressing - Looking for an empty bucket elsewhere.
		- Linear probing
			- If there's a collision when inserting, then linear search down until you find an empty bucket.
			- If not found at the correct index when searching, then linear searching down the buckets until you find the element or an empty from start bucket or reached the starting index again.
				- When searching, loop back to the top.
			- Empty buckets need to be labeled empty since start or empty after removal.
				- Over time, all empty buckets will be empty after removal.
		- Quadratic probing - Spreads out bullets more evenly compared to linear probing.
			- nextIndex = (hash(value) + c1 * i + c2 * i^2) % arraySize
				- c1 and c2 are constants. c1 = 1 and c2 = 1 often works well.

- Resizing - New array is created, usually to the size of the next prime number.
	- All elements are then inserted into this new array in O(N) time.
	- Load factors = numOfFilledBuckets / numOfFilledBuckets; Used to decide when to resize.
		- Load factor cannot exceed 1 for open addressing.
	- When chaining, the size of a bucket's largest linked list.

- A perfect hash function can be created if the number of items and all possible keys are known beforehand.

- Common hash functions
	- Modulo: value % arraySize
	- Mid-square: extractMiddleDigits(value^2) % arraySize
	- Multiplicative string: Multiplies each character of a string by a multiplier and mods at the end.
		- Good for short english strings

```C++
int hashMiddleSquare(int value) {
	const int numOfBits = 24;
	int square = value * value;

	int lowBitsToRemove = (sizeof(int) - numOfBits) / 2;

	// This is usually done in binary instead of decimal due to the simplification
	int middleBits = value >> lowBitsToRemove; // Shift off lower bits
	middleBits = middleBits & (~0 >> (32 - numOfBits));

	return middleBits;
}
```

```C++
// index = (a * key + b) % size
	// a, b, and size are all prime
int hashMultiplicative(string value) {
	int hash = 5381;
	const int multiplier = 33; // Usually prime
	for (int i = 0; i < value.size(); i++) {
		char c = value.at(i);
		hash = (hash * multiplier) + c;
	}
	return hash;
}
```

- Add up all ascii characters % size
	- Square or cube before adding for larger index.

- Hash table of linked lists, with each linked list having a sentinel.
	- Takes up more mem.