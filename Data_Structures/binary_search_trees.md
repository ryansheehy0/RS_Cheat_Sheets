[Home](../README.md)

# Binary Trees
- Definitions
	- Leaf - A node with no children.
	- Internal node - A node with at least one child.
	- Root - The node with no parent. At the top.
	- Edge - the link from a node to a child
	- Levels - Nodes with the same depth. Levels start at 0.
	- A node's depth - Number of edges from it to the root. The root has 0 depth.
	- The tree's height - Largest depth of any node
- Types of binary trees
	- Full binary tree - Every node has 0 or 2 children
	- Complete binary tree - All levels, except the last, contain all possible nodes.
		- Nodes need to be as far left as possible.
		- There can only be blank spaces on the right side for the total binary tree.
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

	- Perfect binary tree - All internal nodes have 2 children and all leaf nodes are on the same level.

Use cases:
	- Trees can represent hierarchical data, like files and folders.
		- Not binary trees.

```C++
template <typename T>
class BinaryTree {
	private:
		struct Node {
			T data;
			Node* leftChild = nullptr;
			Node* rightChild = nullptr;
		};

		Node* root;

	public:
		BinaryTree();
		~BinaryTree();
}
```

Binary space partitioning(BSP)
- Only a few objects in a 2d world should be visible on screen.
- Rendering off screen objects is bad.
- Checking the intersection for all objects with the screen takes too long.
- The root of the binary tree represents all objects in the world.
	- The left child contains all objects on the left half.
	- The right child contains all objects on the right half.
- The screen position can be used to quickly narrow down which objects to check because they aren't anywhere close to the screen.

Binary search tree(BST)
- Each node's data is greater than all the data in its left subtree and less than all the data in its right subtree.
	- This allows for quick searching.
- Search, insert, and remove maybe much faster.
- Successor - If you ordered the BST node from less than to greater than, it would be before another node.
- Predecessor - If you ordered the BST node from less than to greater than, it would be after another node.

```C++
inOrder(Node* node, appliedFunction) {
	if (node == null) return
	inOrder(node->left);
	appliedFunction(node);
	inOrder(node->right);
}
```
- In reverse order.
- Pre-order
	- AppliedFunction, then left, then right
- Post order
	- left, then right, then appliedFunction