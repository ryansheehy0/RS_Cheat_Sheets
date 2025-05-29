[Home](../README.md#data-structures)

# Graphs
A data structure where you have vertices/nodes connected by edges.

- Terms
	- Path - Sequence of edges leading from a source to a destination
		- Path length - Num of edges in the path
		- Distance - Shortest path from one node to another.
	- Connected - Graph contains a path between every pair of vertices
	- Sparse graph - Far fewer edges than the max.

<!-- TOC -->

- [Different ways of storing them in memory](#different-ways-of-storing-them-in-memory)
	- [Adjacency list](#adjacency-list)
	- [Adjacency matrix](#adjacency-matrix)
- [Traversals](#traversals)
	- [Breadth first search](#breadth-first-search)
	- [Depth first search](#depth-first-search)
- [Directional graphs](#directional-graphs)
- [Graphs with weights](#graphs-with-weights)
	- [Kruskal's minimum spanning tree algorithm](#kruskals-minimum-spanning-tree-algorithm)
	- [Dijkstra's shortest path](#dijkstras-shortest-path)
- [Use cases](#use-cases)

<!-- /TOC -->

## Different ways of storing them in memory
Each of these use this example graph:

```
A---B
| / |
C   D
```

### Adjacency list
- A table of the vertex and which other vertices are adjacent to it.
- Time complexity: Good for sparse graphs. O(V) to determine adjacency if not sparse.
- Space complexity: O(V + E)

| Vertex | Adjacent Vertices |
|--------|-------------------|
| A      | B C               |
| B      | A C D             |
| C      | A B               |
| D      | B                 |

### Adjacency matrix
- Each vertex is in a row and column and edges correspond to 1/true for the row and column.
- Time complexity: O(1) determine adjacency.
- Space complexity: O(V^2). Bad for sparse graphs because most cells will be 0s.

|   | A | B | C | D |
|---|---|---|---|---|
| A |   | 1 | 1 |   |
| B | 1 |   | 1 | 1 |
| C | 1 | 1 |   |   |
| D |   | 1 |   |   |

## Traversals
### Breadth first search
Process the starting vertex, then all vertices of distance 1, then of distance 2, etc. without visiting a vertex twice.

```
- Create a hash table of visited nodes equal to the size of the graph.
- Push starting vertex in a queue.
- Add starting vertex to hash table.
- While the queue isn't empty
	- Pop from queue
	- Process the popped node
	- Push the popped node's adjacent nodes that haven't been visited on to the queue
	- Add the popped node's adjacent nodes to the hash table to mark them as visited
```

### Depth first search
Process the starting vertex, then as far down a path as possible, then backtracking until to find a new unvisited path.

```
- Create a hash table of visited nodes equal to the size of the graph.
- Push starting vertex on a stack.
- Add starting vertex to hash table.
- While the stack isn't empty
	- Pop from stack
	- If vertex hasn't been visited
		- Process vertex
		- Add vertex to hash table.
		- Push adjacent vertices onto the stack.
```

## Directional graphs

- Arc/directed edge - Directional edges.
	- This means the adjacency matrix isn' symmetrical.
	- Adjacency means it points to the adjacency node, not that it gets pointed to.
- Path - Sequence of directed edges from a starting vertex to a destination vertex.
- Cycle - A path that starts and ends at the same vertex
	- Cyclic - Directional graph that contains a cycle. Acyclic - Doesn't contain a cycle.
- Degree - Number of incoming and outgoing edges

- Exs: Links between web pages, airline connections between cities, college course prerequisites.

## Graphs with weights
Each edge has a weight/cost associated with it.
- Path length - Sum of weights in the path.
- Cycle length - Sum of weights in a cycle.
	- There is no shortest path for a negative edge weight cycle because it continually decreases the cycle length depending on ho many loops.
- Minimum spanning tree - Subset of edges that connect all vertices with the minimum sum of edge weights.
	- Connected - Contains a path between every pair of vertices.

### Kruskal's minimum spanning tree algorithm
. Space: O(E+V) and Time: O(E log E)

- edgeQueue - Priority queue of edges by edge weights, initially containing all graph edges
- result - Edges of the minimum spanning tree, initially empty
- vertexSets - Each set represents vertexes connected by edges in result, initially contains one set for each vertex.
- while edgeQueue has at least one edge
	- The edge with the lowest weight is removed from the edge queue
	- If the removed edge connects 2 different vertex sets
		- edge is added to the result
		- two vertex sets are merged

### Dijkstra's shortest path
Can be used for for unweighted graphs with an edge weight of 1, but shouldn't be used if edge weights are negative.

```
- For each vertex
	- distanceFromStart = inf
	- predecessorPtr = nullptr
- startingVertex.distance = 0
- unvisitedQueue = all nodes // Priority queue based on min distance from start.
- while unvisitedQueue isn't empty
	- curNode = unvisitedQueue.pop()
	- for each vertex adjacent to curNode
		- if curNode.distanceFromStart + weightToAdjacent < adjacent.distanceFromStart
			- adjacent.distanceFromStart = curNode.distanceFromStart + weightToAdjacent
			- adjacent.predecessorPtr = curNode
- if destination.predecessorPtr == nullptr
	- shortest path doesn't exist
- else
	- The shortest path is gotten by following destination.predecessorPtr until you reach start node.
```

## Use cases
- Friendship groups - People represent nodes.
	- Recommend new connections starting at distance 2 using BFS.
- Maps
	- Flight - Airports represent nodes and the weight is flight duration.
	- Roads - Road intersections represent nodes and weights are length of travel or estimated time.
		- Nodes can be created for specific start and ending locations.
- Products to recommend - Products are nodes and edges are which products are associated with one another.
- Peer to peer networks
	- Download the most from the closest computers who have the file you want using BFS.