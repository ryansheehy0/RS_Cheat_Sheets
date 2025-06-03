[Home](../README.md#data-structures)

# AVL Tree
- Height balance property
   - The height of the node's left and right subtrees differ by only 1 or 1.
   - Balance factor - left subtree's height - right subtree's height
   - Non-existent left or right subtree;s height is -1.
- Their heights aren't exactly the minimum BST, but they are close(1.5x), still allowing for O(log N).
- Nodes can store their height, allowing the heightBalance to be calculated in O(N) time.
   - When inserting or removing, these heights have to be updated.

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