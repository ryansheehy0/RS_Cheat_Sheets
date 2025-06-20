[Home](../README.md#data-structures)

# AVL Tree
AVL trees are binary search trees, but they keep their tree balanced as you insert and remove. The heights of the subtrees differ no more than 1 which results in operations still being O(log N).

- **Balance factor** = left subtree's height - right subtree's height
   - Non-existent left or right subtree's height is -1.

- Nodes can store their height, allowing the heightBalance to be calculated in O(N) time.
   - When inserting or removing, these heights have to be updated.
- In an avl tree, keys must be unique. You cannot put duplicate keys to the right.
   - You could have a count or store a list of the duplicates with keys.

<!-- TOC -->

- [Rebalancing](#rebalancing)
	- [Left-Left](#left-left)
	- [Right-Right](#right-right)
	- [Left-Right](#left-right)
	- [Right of Left](#right-of-left)
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
class AVLTree : public BinarySearchTree {
   public:
      bool insert(T value) override;
      bool remove(T value) override;
   private:
      void rebalance(Node* node);
         void leftRotate(Node* node);
         void rightRotate(Node* node);
};
```

## Rebalancing
There are 4 rebalancing scenarios based on first child–second child directions. The direction, left or right, is determined by which child of the unbalanced node has the larger height.

- Simple - Rotation involves a node and its immediate child, without affecting other subtrees.
- Complex - Rotation involves a node and its child's subtree.

### Left-Left
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

### Right-Right
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

### Left-Right
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

### Right of Left
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

## Rotations
### Left rotation
### Right rotation

## Insert
## Remove


--------------------------------------------------------------------------------

## Other

- AVLTreeUpdateHeight - Updates node's height to the max of child subtree heights + 1.
- AVLTreeSetChild - Sets parent's left/right child and updates its height
- AVLTreeReplaceChild - Replaces a child node with a new child node.
- AVLTreeGetBalance - Gets a node's balance factor

- How do you know where to insert.
- Need to know the last insertion/deletion location to rebalance properly.
   - My implementation of having an AVLRebanlaiicing method doesn't work.

```C++
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

- Nodes need to have a parent pointer and a height value

```C++
void AVLTreeRebalance(Node* node) {
   AVLTreeUpdateHeight(node) // Shouldn't this happen at insertion? Maybe this method is called at insertion.
   if (AVLTreeGetBalance(node) == -2) {
      if (AVLTreeGetBalance(node⇢right) == 1) {
         // Double rotation case.
         AVLTreeRotateRight(tree, node⇢right)
      }
      return AVLTreeRotateLeft(tree, node)
   }
   else if (AVLTreeGetBalance(node) == 2) {
      if (AVLTreeGetBalance(node⇢left) == -1) {
         // Double rotation case.
         AVLTreeRotateLeft(tree, node⇢left)
      }
      return AVLTreeRotateRight(tree, node)
   }
   return node
}
```

## Inserting
- Insertions may cause the tree to become unbalance, needing 1 or 2 rotations to rebalance.

```C++
// After inserting search up
// Rotate left/right the first parent that has a balance factor of -1
// Rotate left/right the first parent that has a balance factor > 2 or < -2.
```

4 imbalancing cases that result form insertions:
   - Numbers are balance factor
```
1 rotation right:
    A(2)
   /                            B
  B(1) -- Right rotation A ->  / \
 /                            C   A
C
```

```
2 rotations, left then right:
  A(2)                          A
 /                             /                           B
B(-1) -- Left rotation B ->   B   -- Right rotation A ->  / \
 \                           /                           C   A
  C                         C
```

```
1 rotation left:
C(-2)
 \                              B
  B(-1) -- Left rotation C ->  / \
   \                          C   A
    A
```

```
2 rotations, right then left:
C(-2)                         C
 \                             \                            B
  B(1) -- Right rotation B ->   B   -- Left rotation C ->  / \
 /                               \                        C   A
A                                 A
```

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

## Removing
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