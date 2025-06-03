[Home](../README.md#data-structures)

# Binary Search Trees
Each node's data is greater than all the data in its left subtree and less than all the data in its right subtree.
- All items in the left sub-tree are less than the root.
- All items in the right sub-tree are greater than or equal to the root.
- Each sub-tree is also a binary search tree.

- In order depth first traversal gives the list in order for a binary search tree.
   - Left, root, right

- O(log2(Height))

This allows for quick searching, inserting, and deleting unlike a linked list.

For this example, no duplicate values are allowed. If you want duplicates you can include a counter in each node.

<!-- TOC -->

- [Destructor](#destructor)
- [Getters](#getters)
	- [Get Height](#get-height)
		- [Get Height Recursive implementation](#get-height-recursive-implementation)
	- [Search](#search)
	- [Max and Min](#max-and-min)
- [Insert](#insert)
- [Remove](#remove)
- [Traversals](#traversals)
	- [Breadth First Search](#breadth-first-search)
	- [Depth First Search](#depth-first-search)
		- [Recursive Implementation](#recursive-implementation)
- [Balance](#balance)
	- [Red and Black Trees](#red-and-black-trees)

<!-- /TOC -->

```C++
template <typename T>
class BinarySearchTree {
	private:
		struct Node {
			T data;
			Node* left = nullptr;
			Node* right = nullptr;
		};

		Node* root = nullptr;
		int count;

	public:
		BinarySearchTree();
		~BinarySearchTree();

		// Getters
		int getCount() const { return count; }
		bool isEmpty() const { return count == 0; }
		int getHeight() const;
      Node<T>* search(T value, Node<T>** parentPtr = nullptr, int* depth = nullptr) const;
      Node<T>* max(Node<T>* subTreeRoot = nullptr, Node<T>** parentPtr = nullptr) const; // Right most leaf
      Node<T>* min(Node<T>* subTreeRoot = nullptr, Node<T>** parentPtr = nullptr) const; // Left most leaf

		// Inserting
		bool insert(T value);

		// Removing
		bool remove(T value);

		// Traversals
         // If process returns true, it breaks out of the loop
      enum class TypeOfBreadthFirstTraversal {
         LEFT_TO_RIGHT_LEVEL_ORDER,
         RIGHT_TO_LEFT_REVERSE_LEVEL_ORDER,
      };
      void breadthFirstTraversal(bool (*process)(T&), TypeOfBreadthFirstTraversal order = TypeOfBreadthFirstTraversal::LEFT_TO_RIGHT_LEVEL_ORDER);
      enum class TypeOfDepthFirstTraversal {
         IN_ORDER, // left, root, right
         PRE_ORDER, // root, left, right
         POST_ORDER, // left, right, root
         REVERSE_IN_ORDER, // right, root, left
         REVERSE_PRE_ORDER, // root, right, left
         REVERSE_POST_ORDER // right, left, root
      };
      void depthFirstTraversal(bool (*process)(T&), TypeOfDepthFirstTraversal order = TypeOfDepthFirstTraversal::IN_ORDER);

      // Balancing
      void fullRebalance();
}
```

## [Destructor](#binary-search-trees)

```C++
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
}
```

## [Getters](#binary-search-trees)

### [Get Height](#binary-search-trees)

```C++
template <typename T>
int BinarySearchTree<T>::getHeight() const {
   if (root == nullptr) return -1;
   Stack s;
   s.push({root, 0});
   int maxHeight = 0;
   while (!s.isEmpty()) {
      auto [node, depth] = s.pop();
      if (node) {
         maxHeight = max(maxHeight, depth);
         s.push({node->left, depth + 1});
         s.push({node->right, depth + 1});
      }
   }
   return maxHeight;
}
```

#### [Get Height Recursive implementation](#binary-search-trees)
```C++
template <typename T>
int BinarySearchTree<T>::getHeight() const {
   return _recursivelyGetHeight(root);
}

template <typename T>
int _recursivelyGetHeight(Node<T> node) const {
   if (node == nullptr) return -1;
   int leftHeight = _recursivelyGetHeight(node->left);
   int rightHeight = _recursivelyGetHeight(node->right);
   return 1 + max(leftHeight, rightHeight);
}
```

### [Search](#binary-search-trees)

```C++
template <typename T>
Node<T>* BinarySearchTree<T>::search(T value, Node<T>** parentPtr = nullptr, int* depth = nullptr) const {
	Node<T>* curNode = root;
	if(depth) *depth = 0;
   if(parentPtr) (*parentPtr) = nullptr;
	while (curNode) {
		if (curNode->data == value) {
			return curNode;
		} else if (curNode->data > value) {
			if(depth) (*depth)++;
         if(parentPtr) (*parentPtr) = curNode;
			curNode = curNode->left;
		} else {
			if(depth) (*depth)++;
         if(parentPtr) (*parentPtr) = curNode;
			curNode = curNode->right;
		}
	}
	return nullptr;
}
```

### [Max and Min](#binary-search-trees)
- Min is the same as max, but using left instead of right.

```C++
template <typename T>
Node<T>* BinarySearchTree<T>::max(Node<T>* subTreeRoot = nullptr, Node<T>** parentPtr = nullptr) const {
   if (parentPtr) (*parentPtr) = nullptr;
   Node<T>* prevNode = nullptr;
   Node<T>* curNode = subTreeRoot ? subTreeRoot : root;
   while (curNode) {
      if (parentPtr) (*parentPtr) = prevNode;
      prevNode = curNode;
      curNode = curNode->right;
   }
   if (prevNode) return prevNode;
   else return nullptr;
}
```

## [Insert](#binary-search-trees)
- New nodes are always added as leafs.
- Duplicates are inserted to the right.
   - New element are inserted to the level closes possible to the root.

```C++
template <typename T>
bool BinarySearchTree<T>::insert(T value) {
   // Create new node
	Node<T>* newNode = new Node;
	if (!newNode) return false;
   newNode->data = value;

   // If empty tree
   if (!root) {
      root = newNode;
      return true;
   }

   // Loop until you get to the correct leaf
   Node<T>* prevNode = nullptr;
   Node<T>* curNode = root;
   while (curNode) {
      prevNode = curNode;
      if (curNode->data > value) {
         curNode = curNode->left;
      } else {
         curNode = curNode->right;
      }
   }

   // Insert new node
   if (prevNode->data > value) {
      prevNode->left = newNode;
   } else {
      prevNode->right = newNode;
   }
   return true;
}
```

## [Remove](#binary-search-trees)

```C++
template <typename T>
bool BinarySearchTree<T>::remove(T value) {
   Node<T>* parent = nullptr;
   Node<T>* curNode = search(value, &parent);
   if (!curNode) return false;

   // Remove leaf node
   if (!curNode->left && !curNode->right) {
      if (parent) {
         if (parent->left == curNode) parent->left = nullptr;
         else parent->right = nullptr;
      } else {
         root = nullptr;
      }
   }
   // Remove node with one child
   else if (!curNode->left || !curNode->right) {
      Node<T>* child = curNode->left ? curNode->left : curNode->right;
      if (parent) {
         if (parent->left == curNode) parent->left = child;
         else parent->right = child;
      } else {
         root = child;
      }
   }
   // Remove node with two children
   else {
      Node<T>* parentOfReplacementNode;
      Node<T>* replacementNode = max(curNode->left, &parentOfReplacementNode); // Always going to be a leaf
      if (parent) {
         if (parent->left == curNode) parent->left = replacementNode;
         else parent->right = replacementNode;
      } else {
         root = replacementNode;
      }
      // Update replacement node links
      if (replacementNode != curNode->left) replacementNode->left = curNode->left;
      replacementNode->right = curNode->right; // No if statement necessary because search is only done on the left subtree
      // Update parent of replacement node
      if (parentOfReplacementNode) {
         if (parentOfReplacementNode->left == replacementNode) parentOfReplacementNode->left = nullptr;
         else parentOfReplacementNode->right = nullptr;
      }
   }

   delete curNode;
   count--;
   return true;
}
```

## [Traversals](#binary-search-trees)
Traverse through each node and applying a function to it.

### [Breadth First Search](#binary-search-trees)
- Traverse by level

```C++
template <typename T>
void BinarySearchTree<T>::breadthFirstTraversal(bool (*process)(T&), TypeOfBreadthFirstTraversal order) {
   if (root == nullptr) return;
   Queue que;
   que.push(root);
   Node<T>* curNode;
   while (!que.isEmpty()) {
      curNode = que.pop();
      if(process(curNode->data)) return true;
      switch (order) {
         case TypeOfBreadthFirstTraversal::LEFT_TO_RIGHT_LEVEL_ORDER:
            if (curNode->left) que.push(curNode->left);
            if (curNode->right) que.push(curNode->right);
            break;
         case TypeOfBreadthFirstTraversal::RIGHT_TO_LEFT_LEVEL_ORDER:
            if (curNode->right) que.push(curNode->right);
            if (curNode->left) que.push(curNode->left);
            break;
      }
   }
}
```

### [Depth First Search](#binary-search-trees)
- Traverse by branch

```C++
template <typename T>
void BinarySearchTree<T>::depthFirstTraversal(bool (*process)(T&), TypeOfDepthFirstTraversal order = TypeOfDepthFirstTraversal::IN_ORDER) {
   if (root == nullptr) return;
   switch (order) {
      case TypeOfDepthFirstTraversal::IN_ORDER:         inOrder(process, false); break;
      case TypeOfDepthFirstTraversal::REVERSE_IN_ORDER: inOrder(process, true); break;
      case TypeOfDepthFirstTraversal::PRE_ORDER:         preOrder(process, false); break;
      case TypeOfDepthFirstTraversal::REVERSE_PRE_ORDER: preOrder(process, true); break;
      case TypeOfDepthFirstTraversal::POST_ORDER:         postOrder(process, false); break;
      case TypeOfDepthFirstTraversal::REVERSE_POST_ORDER: postOrder(process, true); break;
   }
}
```

```C++
template <typename T>
void BinarySearchTree<T>::inOrder(bool (*process)(T&), bool reversed) {
   Stack stack;
   Node<T>* curNode = root;
   while (!stack.isEmpty()) {
      while (curNode) {
         stack.push(curNode);
         curNode = reversed ? curNode->right : curNode->left;
      }
      curNode = stack.pop();
      if (process(curNode->data)) return;
      curNode = reversed ? curNode->left : curNode->right;
   }
}
```

```C++
template <typename T>
void BinarySearchTree<T>::preOrder(bool (*process)(T&), bool reversed) {
   Stack stack;
   Node<T>* curNode;
   stack.push(root);
   while (!stack.isEmpty()) {
      curNode = stack.pop();
      if(process(curNode->data)) return true;
      if (reversed) {
         if (curNode->right) stack.push(curNode->right);
         if (curNode->left) stack.push(curNode->left);
      } else {
         if (curNode->left) stack.push(curNode->left);
         if (curNode->right) stack.push(curNode->right);
      }
   }
}
```

```C++
template <typename T>
void BinarySearchTree<T>::postOrder(bool (*process)(T&), bool reversed) {
   Stack stack;
   Node<T>* curNode = root;
   Node<T>* lastVisited = nullptr;

   while (!stack.isEmpty() || curNode) {
      if (curNode) {
         stack.push(curNode);
         curNode = reversed ? curNode->right : curNode->left;
      } else {
         Node<T>* peekNode = stack.peek();
         Node<T>* next = reversed ? peekNode->left : peekNode->right;
         if (next && lastVisited != next) {
            curNode = next;
         } else {
            if(process(peekNode->data)) return;
            lastVisited = stack.pop();
         }
      }
   }
}
```

#### [Recursive Implementation](#binary-search-trees)

```C++
template <typename T>
void BinarySearchTree<T>::depthFirstTraversal(void (*process)(T&), TypeOfDepthFirstTraversal order = TypeOfDepthFirstTraversal::IN_ORDER) {
   _recursiveDepthFirstTraversal(root, process, order);
}

template <typename T>
void BinarySearchTree<T>::_recursiveDepthFirstTraversal(Node<T>* treeRoot, void (*process)(T&), TypeOfDepthFirstTraversal order = TypeOfDepthFirstTraversal::IN_ORDER) {
   if (treeRoot == nullptr) return;
   switch (order) {
      case TypeOfDepthFirstTraversal::IN_ORDER:
         _recursiveDepthFirstTraversal(treeRoot->left, process, order);
         process(treeRoot->data);
         _recursiveDepthFirstTraversal(treeRoot->right, process, order);
         break;
      case TypeOfDepthFirstTraversal::PRE_ORDER:
         process(treeRoot->data);
         _recursiveDepthFirstTraversal(treeRoot->left, process, order);
         _recursiveDepthFirstTraversal(treeRoot->right, process, order);
         break;
      case TypeOfDepthFirstTraversal::POST_ORDER:
         _recursiveDepthFirstTraversal(treeRoot->left, process, order);
         _recursiveDepthFirstTraversal(treeRoot->right, process, order);
         process(treeRoot->data);
         break;
      case TypeOfDepthFirstTraversal::REVERSE_IN_ORDER:
         _recursiveDepthFirstTraversal(treeRoot->right, process, order);
         process(treeRoot->data);
         _recursiveDepthFirstTraversal(treeRoot->left, process, order);
         break;
      case TypeOfDepthFirstTraversal::REVERSE_PRE_ORDER:
         process(treeRoot->data);
         _recursiveDepthFirstTraversal(treeRoot->left, process, order);
         _recursiveDepthFirstTraversal(treeRoot->right, process, order);
         break;
      case TypeOfDepthFirstTraversal::REVERSE_POST_ORDER:
         _recursiveDepthFirstTraversal(treeRoot->right, process, order);
         _recursiveDepthFirstTraversal(treeRoot->left, process, order);
         process(treeRoot->data);
         break;
   }
}
```

## Balance
- O(N) balancing algo
   - In order traversal into an array
   - Find the middle element and move to the front
   - Divide the remaining array in 2
   - Repeat finding the middle of each and moving to the front
   - Reconstruct binary tree
      - Insert each in order

### Red and Black Trees