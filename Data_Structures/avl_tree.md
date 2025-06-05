[Home](../README.md#data-structures)

# AVL Tree
- Height balance property
   - The height of the node's left and right subtrees differ by only 1 or 1.
   - Balance factor = left subtree's height - right subtree's height
   - Non-existent left or right subtree;s height is -1.
- Their heights aren't exactly the minimum BST, but they are close(1.5x), still allowing for O(log N).
- Nodes can store their height, allowing the heightBalance to be calculated in O(N) time.
   - When inserting or removing, these heights have to be updated.

## Other

- Rotations are local rearrangements used to maintain the BST ordering while rebalancing the tree.

```
    A
   /                                        B
  B     ---Rotation right on node A--->    / \
 /                                        C   A
C

```

Example 2:
```
    A                                       B
   /                                       / \
  B     ---Rotation right on node A--->   C   A
 / \                                         /
C   D                                       D
```

Example 3:
```
     C                                             A
   /   \                                        /     \
  A     E     <---Rotation left on node A---   B       C
 / \     \                                           /   \
B   D     F                                         D     E
                                                           \
                                                            F
```

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
- Standard bst remove
- For each node from the parent to the root are rebalanced.

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