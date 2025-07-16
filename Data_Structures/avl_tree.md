[Home](../README.md#data-structures)

# AVL Tree
AVL trees are binary search trees, but they keep their tree balanced as you insert and remove. The heights of the subtrees differ no more than 1 which results in operations still being O(log N).
- AVL trees cannot have duplicate keys put to the right.

<!-- TOC -->

- [Rebalancing](#rebalancing)
	- [Left-Left](#left-left)
	- [Right-Right](#right-right)
	- [Left-Right](#left-right)
	- [Right of Left](#right-of-left)
	- [Code](#code)
- [Update height](#update-height)
- [Rotations](#rotations)
	- [Left rotation](#left-rotation)
	- [Right rotation](#right-rotation)
- [Insert](#insert)
- [Remove](#remove)
- [Other](#other)
- [Inserting](#inserting)
- [Removing](#removing)

<!-- /TOC -->

```C++
template <typename T>
class AVLTree : public BinarySearchTree<T> {
   private:
		class Node {
			T data;
			Node* left = nullptr;
			Node* right = nullptr;
         int height = 0;
         int balanceFactor() const {
            int leftSubtreeHeight = left ? left->height : -1;
            int rightSubtreeHeight = right ? right->height : -1;
            return leftSubtreeHeight - rightSubtreeHeight;
         }
      };

   public:
      bool insert(T value) override;
      bool remove(T& value) override;

   private:
      void rebalance(Node* node);
      void leftRotate(Node* node);
      void rightRotate(Node* node);
      void updateHeight(Node* node);
};
```

## [Rebalancing](#avl-tree)
There are 4 rebalancing scenarios based on first child–second child directions. The direction, left or right, is determined by which child of the unbalanced node has the larger height.

- Simple - Rotation involves a node and its immediate child, without affecting other subtrees.
- Complex - Rotation involves a node and its child's subtree.

### [Left-Left](#avl-tree)
Single rotation right

```
      Simple                        Complex
    30                        30                20
   /          20             /  \              /  \
  20   -->   /  \           20   40   -->    10    30
 /         10    30        /  \              /    /  \
10                       10    25           5   25    40
                         /
                        5
30 - Unbalanced
20 - Left first child
10 - Left second child
```

### [Right-Right](#avl-tree)
Single rotation left

```
      Simple                     Complex
10                        10                20
 \           20          /  \              /  \
  20  -->   /  \        5    20   -->    10    30
   \      10    30          / \          / \    \
    30                    15   30       5   15   40
                                \
                                 40
10 - Unbalanced
20 - Right first child
30 - Right second child
```

### [Left-Right](#avl-tree)
Left rotation on the left child, then do right rotation on unbalanced node.

```
             Simple                                    Complex
  30           30                       30                30                20
 /            /          20            /  \              /  \              /  \
10    ---->  20   --->  /  \          10   40  -->     20    40  -->     10    30
 \          /         10    30       /  \              /                /  \    \
  20       10                       5    20          10                5    15   40
                                        /           /  \
                                       15          5    15
30 - Unbalanced node
10 - Left first child
20 - Right second child
```

### [Right of Left](#avl-tree)
Right rotation on the right child, then do left rotation on unbalanced node.

```
        Simple                                    Complex
10        10                        10               10                  20
  \        \           20          /  \             /  \                /  \
   30  -->  20  -->   /  \        5    30   -->    5    20   -->       10   30
  /          \      10    30          /  \             /  \           / \    \
20            30                     20   40         15    30        5   15   40
                                    /                       \
                                   15                        40

10 - Unbalanced node
30 - Right first child
20 - Left second child
```

### [Code](#avl-tree)
- Negative balance factor means right child has larger height
- Positive balance factor means left child has larger height

```C++
template <typename T>
void AVLTree<T>::rebalance(Node* node) {
   updateHeight(node);
   if (node->balanceFactor() == -2) { // First child is right
      if (node->right->balanceFactor() > 0) { // Second child is left
         rotateRight(node->right); // Double rotations
      }
      rotateLeft(node);
   } else if (node->balanceFactor() == 2) { // First child is left
      if (node->left->balanceFactor() < 0) { // Second child is right
         rotateLeft(node->left); // Double rotations
      }
      rotateRight(node);
   }
}
```

## [Update height](#avl-tree)

```C++
template <typename T>
int AVLTree<T>::updateHeight(Node* node) {
   if (node == nullptr) return 0;
   node->height = 1 + max(updateHeight(node->left), updateHeight(node->right));
   return node->height;
}
```

## [Rotations](#avl-tree)
### [Left rotation](#avl-tree)
### [Right rotation](#avl-tree)

```C++
template <typename T>
void AVLTree<T>::rotateRight(Node* node) {
   T leftsRightChild = node->left->right;
   if (node->parent != nullptr) { // There's a parent
      if (node->parent->left == node) node->parent->left = node->left;
      else node->parent->right = node->left;
   } else { // Node is root
      if (root->left == node) root->left = node->left;
      else root->right = node->left;
   }
   node->left->right = node;
   node->left = leftsRightChild;
}

// node needs to have a left child
void AVLTreeRotateRight(Node* node) {
   leftsRightChild = node->left->right;
   if (node->parent != null) // If there's a parent
      AVLTreeReplaceChild(node->parent, node, node->left) // Replace child of parent
   else { // node is root
      rootPtr = node->left
      root->parent = nullptr;
   }
   AVLTreeSetChild(node->left, "right", node) // Set right node
   AVLTreeSetChild(node, "left", leftRightChild) // Set left node
}
```

## [Insert](#avl-tree)

```C++
template <typename T>
bool AVLTree<T>::insert(T value) {
   // Check for duplicates
   // Find the leaf
   // Insert left or right child
   // Update heights to the root
}
```

## [Remove](#avl-tree)

```C++
template <typename T>
bool AVLTree<T>::remove(T& value) {
   if (!BinarySearchTree<T>::remove(value)) return false;
   // Update heights
   // Rebalance
   return true;
}
```


--------------------------------------------------------------------------------

## [Other](#avl-tree)

- AVLTreeUpdateHeight - Updates node's height to the max of child subtree heights + 1.
- AVLTreeSetChild - Sets parent's left/right child and updates its height
- AVLTreeReplaceChild - Replaces a child node with a new child node.
- AVLTreeGetBalance - Gets a node's balance factor

- How do you know where to insert.
- Need to know the last insertion/deletion location to rebalance properly.
   - My implementation of having an AVLRebanlaiicing method doesn't work.


- Nodes need to have a parent pointer and a height value


## [Inserting](#avl-tree)
- Insertions may cause the tree to become unbalance, needing 1 or 2 rotations to rebalance.

```C++
// After inserting search up
// Rotate left/right the first parent that has a balance factor of -1
// Rotate left/right the first parent that has a balance factor > 2 or < -2.
```

4 imbalancing cases that result form insertions:
   - Numbers are balance factor

Inserting - Only 1 rotation(single or double) is needed per insertion.
- Searching for the insertion location
- Inserting the new node
- For each node from the inserted node up to the root
   - Update its balance factor
   - If balance factor is 2 or -2, do a single or double rotation based on child's balance factor.
   - After rotation, stop

Inserting is O(log N)

```C++
AVLTreeInsertKey(tree, key) {
   if (BSTContains(tree, key)) {
      return false
   }

   newNode = Allocate new AVL tree node with key
   AVLTreeInsertNode(newNode)
   return true
}

AVLTreeInsertNode(tree, node) {
   if (tree⇢root == null) {
      tree⇢root = node
      node⇢parent = null
      return
   }

   cur = tree⇢root
   while (cur != null) {
      if (node⇢key < cur⇢key) {
         if (cur⇢left == null) {
            cur⇢left = node
            node⇢parent = cur
            cur = null
         }
         else {
            cur = cur⇢left
         }
      }
      else {
         if (cur⇢right == null) {
            cur⇢right = node
            node⇢parent = cur
            cur = null
         }
         else
            cur = cur⇢right
      }
   }

   node = node⇢parent
   while (node != null) {
      AVLTreeRebalance(tree, node)
      node = node⇢parent
   }
}
```

## [Removing](#avl-tree)
- Standard bst remove.
   - What about the root. Find the largest left child or smallest right child.
- Recalculate balance factor from the node deleted to the root.
- Rebalance when you find 2/-2 balance factor.

```C++
AVLTreeRemoveNode(tree, node) {
   if (node == null) {
      return false
   }

   // Parent needed for rebalancing
   parent = node⇢parent
        
   // Case 1: Internal node with 2 children
   if (node⇢left != null && node⇢right != null) {
      // Find successor
      succNode = node⇢right
      while (succNode⇢left != null) {
         succNode = succNode⇢left
      }

      // Copy the key from the successor node
      node⇢key = succNode⇢key
            
      // Recursively remove successor
      AVLTreeRemoveNode(tree, succNode)
            
      // Nothing left to do since the recursive call will have rebalanced
      return true
   }

   // Case 2: Root node (with 1 or 0 children)
   else if (node == tree⇢root) {
      if (node⇢left != null) {
         tree⇢root = node⇢left
      }
      else {
         tree⇢root = node⇢right
      }
      if (tree⇢root != null) {
         tree⇢root⇢parent = null
      }
      return true
   }

   // Case 3: Internal with left child only
   else if (node⇢left != null) {
      AVLTreeReplaceChild(parent, node, node⇢left)
   }
   // Case 4: Internal with right child only OR leaf
   else {
      AVLTreeReplaceChild(parent, node, node⇢right)
   }

   // node is gone. Anything that was below node that has persisted is already correctly
   // balanced, but ancestors of node may need rebalancing.
   node = parent
   while (node != null) {
      AVLTreeRebalance(tree, node)            
      node = node⇢parent
   }
   return true
}
```