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

## Use cases
- Friendship groups - People represent nodes.
- Maps
	- Flight - Airports represent nodes and the weight is flight duration.
	- Roads - Road intersections represent nodes and weights are length of travel or estimated time.
		- Nodes can be created for specific start and ending locations.
- Products to recommend - Products are nodes and edges are which products are associated with one another.