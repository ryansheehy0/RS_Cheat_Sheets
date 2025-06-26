# Final Notes

<!-- TOC -->

- [Big O](#big-o)
- [Binary Trees](#binary-trees)
- [Binary Search Trees](#binary-search-trees)
- [Hash Tables](#hash-tables)
- [Heaps](#heaps)
- [Graphs](#graphs)
- [AVL Trees](#avl-trees)
- [Sorting Algos](#sorting-algos)

<!-- /TOC -->

## Big O
- O(1)
- O(log N)    - For loop that increments my multiplying or decs by division.
- O(N)
- O(N log N)  - Linear function is called in a Log N loop or vise versa.
- O(N^2)
- O(N^k)
- O(c^N)
- O(N!)

## Binary Trees
- Breadth First traversal
	- Push root to queue
	- While queue not empty
		 - pop and process
		 - push left child
		 - push right child

- Depth First traversal
	- In order - left, root, right
	- Pre order - root, left, right
	- Post order - left, right, root
	- Reverse swaps the left and right
	- Recursive on root
		 - if not node return
		 - Recursive on left child
		 - Process
		 - Recursive on right child

## Binary Search Trees
- Insert
	- Create new node
	- If empty tree then set as root and return
	- Find correct leaf
	- Add as a new leaf
	- Increment count

- Remove
	- Find parent and node
	- Node is a leaf node
		 - If root then remove
		 - Set parent's left/right to null
	- Node has one child
		 - If root then set child as root
		 - Set parent's left/right to child
	- Node has two children
		 - Find largest from left sub-tree or smallest form right sub-tree
		 - If root then set replacement node to root
		 - Set parent's left/right to replacement node
		 - Set replacement node's children to your children
		 - Remove replacement node from its parent
	- Decrement count

- Search
	- while curNode
		 - if value is curNode return
		 - if value < curNode go left
		 - if value > curNode go right

## Hash Tables
- Collision resolution: Linear probe vs linked list

- Insert
	- Check for duplicates
	- Check if you need to resize
	- Get index
	- Insert into hash table
	- Increment count
- Remove
	- Find element
	- Remove from linked list
	- Decrement count
- Search
	- Get index
	- Search linked list
	- Return
- Resize
	- Find new size, usually prime
	- For each element in the hash table
		- newIndex = hash % newSize
		- Insert into new hash table
	- delete old hash table and set new one

## Heaps
- Convert array to heap
	- Insert each element into heap one by one. O(N log N)
	- Start at (n / 2) - 1 towards 0 reheaping down. O(N)
- ReHeapUp
	- while element is greater than parent swap
- ReHeapDown
	- while element is less than largest child swap
- Inserting
	- Add to the end
	- Reheap up the end
- Removing
	- Return the top
	- Set the tail to the top
	- Reheap down the top
- Indexes
	- Parent = (i - 1) / 2
	- Left   = (2 * i) + 1
	- Right  = (2 * i) + 2

## Graphs
- Adjacency list and adjacency matrix
	- Adjacency list - O(V + E) space
	- Adjacency matrix - O(V^2) space
		- Columns represent nodes coming in.
		- Rows represent nods coming out.

- Depth first search
	- Set each node as not visited
	- Push start onto **stack** and mark as visited
	- While stack isn't empty
		- Pop and process
		- Push non-visited adjacent nodes and mark as visited
- Breadth first search - **Queue**

- Kruskal's algo
	- while there are still edges in this priority queue
		- pop edge from priority queue // An edge has two nodes
		- if both nodes don't belong to any groups
			- create a new group
		- if one node belongs to a group, but the other doesn't
			- add edge to group
		- if each node belongs to the same group
			- continue
		- if each node belongs to different groups
			- add edge to group
			- move all edges from one group onto the other
			- remove the group

- Prim's algo
	- Add smallest edge to the result
	- while all the nodes aren't in the result
		- // Get smallest edge of all the edges adjacent to the result
		- set minEdge to the first adjacent edge
		- for each node in the result
			- for all adjacent edges to that node
				- if the adjacent edge is in the result continue
				- if the adjacent edge weight is less than the minEdge, update minEdge
		- Add minEdge to result

- Dijkstra's shortest path
	- For each node
		- distanceFromStart = inf
		- prevNode = null
		- processed = false
	- Set startNode.distanceFromStart to 0
	- Add start node to the priority queue // Priority queue prioritizes the min distanceFromStart
	- while there is something in the priority queue
		- pop from priority queue
		- set processed to true
		- For each of its adjacent nodes
			- if processed continue
			- if distanceFromStart > edge weight + curNode.distanceFromStart
				- update distanceFromStart and prevNode
				- add to priority queue

## AVL Trees
- Rebalancing cases
	- Left-left   - One rotation right.
	- Right-right - One rotation left.
	- Left-right  - Left rotation on left child, then right rotation.
	- Right-left  - Right rotation on right child, then left rotation.

- Right rotation
	- Set node's left to left's right
	- Set left's right to node
	- Set parents
		 - Left's right parent to node
		 - Node's parent to left
		 - Left's parent to parent

- Inserting
	- Regular BST insert
	- Walk up the node that was inserted towards the root
	- If 2 or -2 balance factor, then rebalance that node and exit.

- Removing
	- Regular BST remove
	- Walk up the node that was removed towards the root.
	- If 2 or -2 balance factor, then rebalance that node.
	- Repeat as you go towards the root.

## Sorting Algos
- Selection sort - O(N^2)
	- Has a sorted and unsorted part. Repeatedly selects the min value from the unsorted part and places it at the end of the sorted part.
	- Heap sort - O(N log N)
- Insertion sort - O(N^2)
	- Has a sorted and unsorted part. Repeatedly selects the first element of the unsorted part and places it in the correct location in the sorted part.
	- Shell sort - O(N^1.5)
		- Imagine the array as K interleaved subarrays. Perform insertion sort on each subarray individually. Reduce K and repeat until K = 1, then do a final insertion sort on the full array.
- Quick sort - O(N log N)
	- Select a pivot value in the array. Move all elements less than to the left and all elements greater than to the right. Recursively repeat for the left and right sub-arrays, not including the pivot.