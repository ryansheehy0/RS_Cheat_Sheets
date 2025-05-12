[Home](../README.md#data-structures)

# Binary Search Trees
Each node's data is greater than all the data in its left subtree and less than all the data in its right subtree.

This allows for quick searching, inserting, and deleting unlike a linked list.

For this example, no duplicate values are allowed. If you want duplicates you can include a counter in each node.

<!-- TOC -->

- [Destructor](#destructor)
- [Search](#search)
- [Insert](#insert)
- [Traversal](#traversal)
	- [Breadth first](#breadth-first)
	- [Depth first](#depth-first)

<!-- /TOC -->

```C++
template <typename T>
class BinarySearchTree {
	private:
		struct Node {
			T data;
			Node* leftChild = nullptr;
			Node* rightChild = nullptr;
		};

		Node* root = nullptr;
		int count;

	public:
		BinarySearchTree();
		~BinarySearchTree();

		// Getters
		int getCount() const;
		bool isEmpty() const;
		int getHeight() const;
		Node<T>* search(T target, int* depth = nullptr) const;

		// Inserting
		bool insert(T value);

		// Removing
		bool remove(T value);

		// Traversals
		void breadthFirstTraversal(func*) const;
		void depthFirstTraversal(func*) const;
}
```

## [Destructor](#binary-search-trees)

```C++
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
}
```

## [Search](#binary-search-trees)

```C++
template <typename T>
Node<T>* BinarySearchTree<T>::search(T value, int* depth = nullptr) {
	Node<T>* curNode = root;
	if(depth) *depth = 0;
	while (curNode) {
		if (curNode->data == value) {
			return curNode;
		} else if (curNode->data > value) {
			if(depth) (*depth)++;
			curNode = curNode->left;
		} else {
			if(depth) (*depth)++;
			curNode = curNode->right;
		}
	}
	return nullptr;
}
```

## [Insert](#binary-search-trees)

```C++
template <typename T>
bool BinarySearchTree<T>::insert(T value) {
	if (search(value)) return false; // Already exists so return false

	Node<T>* newNode = new Node;
	if (!newNode) return false;

	

}
```

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

```C++
template <typename T>
Node* search(T target) {
	Node* curNode = root;
	while (curNode) {
		if (curNode->data == target) return curNode; // Node found
		else if (curNode->data < target) curNode = curNode->left; // Go left
		else curNode = curNode->right; // Go right
	}
	return nullptr;
}
```

Amount of searches in a n binary tree = floor(log2(n)) + 1

```C++
getParent(Node* root, Node* targetNode) {
	if (root == nullptr) return nullptr;
	if (root->left == targetNode || root->right == targetNode) return root;
	else if (root->data < targetNode->data) return getParent(root->left, targetNode);
	else return getParent(root->right, targetNode)l
}
// Don't use recursion here.
```

```C++
bool insertNode(Node* node) {
	if (root == nullptr) {
		root = node;
		return true;
	} else {
		return recursiveInsertNode(root, node);
	}
}

bool recursiveInsertNode(Node* parent, Node* node) {
	if (parent->data == node->data) return false;
	if (parent->data > node->data) { // Go left
		if (parent->left == nullptr) {
			parent->left = node;
			return true;
		} else {
			return recursiveInsertNode(parent->left, node);
		}
	} else { // Go right
		if (parent->right == nullptr) {
			parent->right = node;
			return true;
		} else {
			return recursiveInsertNode(parent->right, node);
		}
	}
}
```

```C++
bool remove(T target) {
	Node* node = search(target);
	Node* parent = parent(node);
	return removeNode(parent, node);
}

bool removeNode(parent, node) {
	if (node == nullptr) return false;

	// Case 1: Internal node with 2 children
	if (node->left && node->right) {
		// Find the greatest leaf node in the left sub tree	.
			// Set that to the root
			// Remove that leaf node
	}
	// Case 3: Node with 1 child
	else if (node->left || node->right) {
		// Set parent's left or right ot the child node
		if (parent->left == node) {
			if (node->left) parent->left = node->left;
			else parent->left = node->right;
			delete node;
			return true;
		} else if (parent->right == node) {
			if (node->left) parent->right = node->left;
			else parent->right = node->right;
			delete node;
			return true;
		} else return false; // Something went wrong
	}
	// Case 2: Leaf node
	else if (node->left == nullptr && node->right == nullptr) {
		if (parent->left == node) parent->left == nullptr;
		else if (parent->right == node) parent->right == nullptr;
		else return false; // Something went wrong
		delete node;
		return true;
	}


   if (node⇢left != null && node⇢right != null) {
      // Find successor and successor's parent
      successorNode = node⇢right
      successorParent = node
      while (successorNode⇢left != null) {
         successorParent = successorNode
         successorNode = successorNode⇢left
      }
            
      // Copy the key from the successor node
      node⇢key = successorNode⇢key
            
      // Recursively remove successor node
      BSTRemoveNode(tree, successorParent, successorNode)
   }

   // Case 2: Root node (with 1 or 0 children)
   else if (node == tree⇢root) {
      if (node⇢left != null) {
         tree⇢root = node⇢left
      }
      else {
         tree⇢root = node⇢right
      }
   }

   // Case 3: Internal with left child only
   else if (node⇢left != null) {
      // Replace node with node's left child
      if (parent⇢left == node) {
         parent⇢left = node⇢left
      }
      else {
         parent⇢right = node⇢left
      }
   }

   // Case 4: Internal with right child only OR leaf
   else {
      // Replace node with node's right child
      if (parent⇢left == node) {
         parent⇢left = node⇢right
      }
      else {
         parent⇢right = node⇢right
      }
   }        

   return true
}

```

```C++
// You're always inserting as a leaf
BSTInsertNode(tree, node) {
   if (tree⇢root is null) {
      tree⇢root = node
   }
   else {
      currentNode = tree⇢root
      while (currentNode is not null) {
         if (node⇢key < currentNode⇢key) {
            if (currentNode⇢left is null) {
               currentNode⇢left = node
               currentNode = null
            }
            else {
               currentNode = currentNode⇢left
            }
         }
         else {
            if (currentNode⇢right is null) {
               currentNode⇢right = node
               currentNode = null
            }
            else {
               currentNode = currentNode⇢right
            }
         }
      }
   }
}
```

```C++
// Balances the binary tree
void balance() {
}
```

- insert, insertAVL, insertRB
- rebalanceAVL, rebalanceRB
- needRebalancingAVL, needRebalancingRB

insertAVL
	insert
	if (needRebalancingAVL)
		rebalanceAVL

```C++
BSTRemove(tree, key) {
   parent = null
   currentNode = tree⇢root
   while (currentNode != null) {
      // Check if currentNode has an equal key
      if (currentNode⇢key == key) {
         if (currentNode⇢left is null && currentNode⇢right is null) {
            // Remove leaf

            if (parent is null) { // Node is root
               tree⇢root = null
            }
            else if (parent⇢left == currentNode) {
               parent⇢left = null
            }
            else {
               parent⇢right = null
            }
            return true // Node found and removed
         }
         else if (currentNode⇢right is null) {
            // Remove node with only left child
            
            if (parent is null) { // Node is root
               tree⇢root = currentNode⇢left
            }
            else if (parent⇢left == currentNode) {
               parent⇢left = currentNode⇢left
            }
            else {
               parent⇢right = currentNode⇢left
            }
            return true // Node found and removed
         }
         else if (currentNode⇢left is null) {
            // Remove node with only right child
            
            if (parent is null) { // Node is root
               tree⇢root = currentNode⇢right
            }
            else if (parent⇢left == currentNode) {
               parent⇢left = currentNode⇢right
            }
            else {
               parent⇢right = currentNode⇢right
            }
            return true // Node found and removed
         }
         else {
            // Remove node with two children
            
            // Find successor (leftmost child of right subtree)
            successor = currentNode⇢right
            while (successor⇢left is not null) {
               successor = successor⇢left
            }

            // Copy successor's key to current node
            currentNode⇢key = successor⇢key
            Parent = currentNode

            // Reassign currentNode and key so that loop continues with new key
            currentNode = currentNode⇢right
            key = successor⇢key
         }
      }
      else if (currentNode⇢key < key) {
         // Search right
         parent = currentNode
         currentNode = currentNode⇢right
      }
      else {
         // Search left
         parent = currentNode
         currentNode = currentNode⇢left
      }
   }
   return false // Node not found
}
```

## [Traversal](#binary-search-trees)
Go through each node and run function
- If it's just a binary tree, not a binary search tree, then these are the two methods for searching.

### [Breadth first](#binary-search-trees)
- Traverse by level

```C++
if (root == nullptr) return

q.push(root)
while (!q.isEmpty()) {
	currNode = q.pop()
	process(curNode->data)
	if (curr->left)
		q.push(curr->left)
	if (curr->right)
		q.push(curr->right)
}
```

### [Depth first](#binary-search-trees)
- Traverse y branch

- in order
	- left right root
- pre-order
	- root left right
- post-order
	- left right root

```C++
pre-order
if (root == nullptr) return

create stack
push root
while (!s.isEmpty(0)) {
	pop
	process
	if (curNode->right)
		push curNode->right
	if (curNode->left)
		push curNode->left

}
```
