[Home](../README.md#data-structures)

# Graphs
Graphs are a data structure consisting of **nodes/vertices** connected by **edges**.

- Path - Sequence of edges from a source to a destination.
	- Path length - Number of edges in the path.
	- Distance - Length of the shortest path between two nodes.
- Connected - Graph has a path between every pair of vertices. No islands.
- Sparse graph - Contains far fewer edges than the maximum possible.
- Adjacency - Describes which nodes are directly connected by an edge.

<!-- TOC -->

- [Storing graphs in memory](#storing-graphs-in-memory)
	- [Adjacency list](#adjacency-list)
	- [Adjacency matrix](#adjacency-matrix)
- [Traversals](#traversals)
	- [Breadth first search](#breadth-first-search)
	- [Depth first search](#depth-first-search)
- [Directional graphs](#directional-graphs)
- [Graphs with weights](#graphs-with-weights)
	- [Minimum spanning trees](#minimum-spanning-trees)
		- [Kruskal's algo](#kruskals-algo)
		- [Prim's algo](#prims-algo)
	- [Dijkstra's shortest path](#dijkstras-shortest-path)
- [Use cases](#use-cases)

<!-- /TOC -->

## Storing graphs in memory
Each of these use this example graph:

```
A---B
| / |
C   D
```

### Adjacency list
A table of nodes with a list of the adjacent nodes.
- Time complexity: Good for sparse graphs, but O(V) to determine adjacency if not sparse.
- Space complexity: O(V + E)

| Vertex | Adjacent Vertices |
|--------|-------------------|
| A      | B C               |
| B      | A C D             |
| C      | A B               |
| D      | B                 |

### Adjacency matrix
Each node is in a row and column and edges correspond to 1/true for the row and column.
- Time complexity: O(1) determine adjacency.
- Space complexity: O(V^2). Bad for sparse graphs because most cells will be 0s. Also not good if the graph changes a lot.

|   | A | B | C | D |
|---|---|---|---|---|
| A |   | 1 | 1 |   |
| B | 1 |   | 1 | 1 |
| C | 1 | 1 |   |   |
| D |   | 1 |   |   |

- Columns represent nodes coming in.
- Rows represent nods coming out.

## Traversals
### Breadth first search
Process the starting vertex, then all vertices of distance 1, then of distance 2, etc. without visiting a vertex twice.
- Create a hash table of visited nodes or set each node to not visited.
- Push starting vertex in a **queue** and mark starting vertex as visited.
- While the queue isn't empty
	- Process the pop from the queue
	- Push all adjacent nodes that haven't been visited
	- Mark adjacent nodes as visited

Useful to find the shortest path between two nodes.

### Depth first search
Process the starting vertex, then as far down a path as possible, then backtracking until to find a new unvisited path.
- Create a hash table of visited nodes or set each node to not visited.
- Push starting vertex in a **stack** and mark starting vertex as visited.
- While the stack isn't empty
	- Process the pop from the stack
	- Push all adjacent nodes that haven't been visited
	- Mark adjacent nodes as visited

Useful for solving mazes.

## Directional graphs
Edges can only go in one direction.

- Arc/Directed Edge - An edge with a direction from one vertex to another.
	- The adjacency matrix is not symmetrical.
	- A node is adjacent if it is pointed to by the current node.
- Path - A sequence of directed edges from a starting vertex to a destination.
- Cycle - A path that starts and ends at the same vertex.
	- Cyclic - Graph contains at least one cycle. Acyclic - No cycles present.
- Degree - The number of incoming (in-degree) and outgoing (out-degree) edges for a vertex.

Useful for links between web pages, airline connections between cities, college course prerequisites.

## Graphs with weights
Each edge has a weight/cost associated with it.

- Path length - The sum of edge weights along a path.
- Cycle length - The total weight of edges in a cycle.
	- No shortest path exists for a negative-weight cycle because repeatedly looping reduces the total length indefinitely.

### Minimum spanning trees
A minimum spanning tree (MST) is a subset of edges that connects all nodes with the minimum total edge weight and no cycles.

- Has V nodes and V-1 edges.
- The graph must be connected, meaning there’s a path between every pair of nodes.
- Ex: Connecting islands with bridges while minimizing total construction cost.

#### Kruskal's algo
Time complexity is O(E log E) and space complexity is O(E + V).

- Put all edges in a priority queue prioritized by the minimum weight.
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

```
Example:

    A -5- B
	 /     /
	1     2
 /     /
E -2- D ---2-- H
|    / \      /
1   5   11   1
|  /     \  /
 F ---7-- G

Iteration 0:
	Prio Q: E-A, E-F, G-H, E-D, D-H, D-B, F-D, A-B, D-G
	Groups:
Iteration 1:
	Prio Q: E-F, G-H, E-D, D-H, D-B, F-D, A-B, D-G
	Groups: 0: E-A
Iteration 2:
	Prio Q: G-H, E-D, D-H, D-B, F-D, A-B, D-G
	Groups: 0: E-A, E-F
Iteration 3:
	Prio Q: E-D, D-H, D-B, F-D, A-B, D-G
	Groups: 0: E-A, E-F
	        1: G-H
Iteration 4:
	Prio Q: D-H, D-B, F-D, A-B, D-G
	Groups: 0: E-A, E-F, E-D
	        1: G-H
Iteration 5:
	Prio Q: D-B, F-D, A-B, D-G
	Groups: 0: E-A, E-F, E-D, D-H, G-H
Iteration 6:
	Prio Q: F-D, A-B, D-G
	Groups: 0: E-A, E-F, E-D, D-H, G-H, D-B
Iteration 7:
	Prio Q: A-B, D-G
	Groups: 0: E-A, E-F, E-D, D-H, G-H, D-B
Iteration 8:
	Prio Q: D-G
	Groups: 0: E-A, E-F, E-D, D-H, G-H, D-B
Iteration 9:
	Prio Q:
	Groups: 0: E-A, E-F, E-D, D-H, G-H, D-B

Result:

    A     B
	 /     /
	1     2
 /     /
E -2- D ---2-- H
|             /
1            1
|           /
 F        G
```


#### Prim's algo
Time Complexity is O((V + E) log V) and space complexity is O(V + E).

- Add smallest edge to the result
- while all the nodes aren't in the result
	- // Get smallest edge of all the edges adjacent to the result
	- set minEdge to the first adjacent edge
	- for each node in the result
		- for all adjacent edges to that node
			- if the adjacent edge is in the result continue
			- if the adjacent edge weight is less than the minEdge, update minEdge
	- Add minEdge to result

```
Example:

    A -5- B
	 /     /
	1     2
 /     /
E -2- D ---2-- H
|    / \      /
1   5   11   1
|  /     \  /
 F ---7-- G

Ad eds - The adjacent edges to the result nodes that aren't already in the result.

Iteration 0:
	Result: E-A
	Ad eds: E-F, E-D, A-B
Iteration 1:
	Result: E-A, E-F
	Ad eds: F-G, F-D, E-D, A-B
Iteration 2:
	Result: E-A, E-F, E-D
	Ad eds: F-G, F-D, D-G, D-H, D-B, A-B
Iteration 3:
	Result: E-A, E-F, E-D, D-H
	Ad eds: F-G, F-D, D-G, G-H, D-B, A-B
Iteration 3:
	Result: E-A, E-F, E-D, D-H, G-H
	Ad eds: F-G, F-D, D-G, D-B, A-B
Iteration 4:
	Result: E-A, E-F, E-D, D-H, G-H, D-B
```

### Dijkstra's shortest path
The shortest path is found by tracing backward from the destination to the start through its prevNodes.

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

```Example
|   | A  | B  | C  | D  | E  |
|---|----|----|----|----|----|
| A | 0  | 90 | 10 | 0  | 50 |
| B | 90 | 0  | 0  | 30 | 0  |
| C | 10 | 0  | 0  | 40 | 20 |
| D | 0  | 30 | 40 | 0  | 10 |
| E | 50 | 0  | 20 | 10 | 0  |

Iteration 0:
	| Nodes             | A | B   | C   | D   | E   |
	|-------------------|---|-----|-----|-----|-----|
	| distanceFromStart | 0 | inf | inf | inf | inf |
	| prevNode          | 0 | 0   | 0   | 0   | 0   |
	| processed         | 0 | 0   | 0   | 0   | 0   |
Iteration 1:
	| Nodes             | A | B  | C  | D   | E  |
	|-------------------|---|----|----|-----|----|
	| distanceFromStart | 0 | 90 | 10 | inf | 50 |
	| prevNode          | 0 | A  | A  | 0   | A  |
	| processed         | 1 | 0  | 0  | 0   | 0  |
Iteration 2:
	| Nodes             | A | B  | C  | D  | E  |
	|-------------------|---|----|----|----|----|
	| distanceFromStart | 0 | 90 | 10 | 40 | 30 |
	| prevNode          | 0 | A  | A  | C  | C  |
	| processed         | 1 | 0  | 1  | 0  | 0  |
Iteration 3:
	| Nodes             | A | B  | C  | D  | E  |
	|-------------------|---|----|----|----|----|
	| distanceFromStart | 0 | 90 | 10 | 40 | 30 |
	| prevNode          | 0 | A  | A  | C  | C  |
	| processed         | 1 | 0  | 1  | 0  | 1  |
Iteration 4:
	| Nodes             | A | B  | C  | D  | E  |
	|-------------------|---|----|----|----|----|
	| distanceFromStart | 0 | 70 | 10 | 40 | 30 |
	| prevNode          | 0 | D  | A  | C  | C  |
	| processed         | 1 | 0  | 1  | 1  | 1  |
Backtrack from B to A.
B-D-C-A with total weight of 70
```

Can also be used for for unweighted graphs with an edge weight of 1, but shouldn't be used if edge weights are negative.

## Use cases
- Friendship groups - People represent nodes. You can recommend new friends starting at a distance of 2.
- Maps
	- Flights - Airports represent nodes and the weight is flight duration.
	- Roads - Road intersections represent nodes and weights are length of travel or estimated time. New nodes can be added for the origin and destination.
- Peer to peer computer networks
- Traveling sales man problem - What is the shortest possible path that goes through each node once and returns to the starting node. O(V!)
	- The shortest Hamilton cycle.
- Euler circuit - Path the goes through all edges, but can't go through an edge twice.
- Floyd's algo - Shortest paths between all pairs of nodes. O(V^3)