[Home](../README.md#algorithms)

# Huffman Codes
Optimal loss-less variable length compression algorithm.

- https://www.youtube.com/watch?v=B3y0RsVCyrw

```C++
string hiffmanCode(string value) {

}
```

- string value = "optimal compression scheme";
- Count the number of occurrences for each character skipping over the characters that were already counted.
	- o p t i m a l c r e s n h
	- 3 2 1 2 3 1 1 2 1 2 3 1 1
- Sort from low to high
	- t a l r n h p i c e s o m
	- 1 1 1 1 1 1 2 2 2 2 3 3 3
- Merge the 2 smallest nodes, add their occurrences, and re-insert into the priority queue. Prioritize the nodes that haven't been merged.
	- Iteration 1
		- l r n h p i c e ta s o m
		- 1 1 1 1 2 2 2 2  2 3 3 3
	- Iteration 2
		- l r n h p i c e ta s o m
		- 1 1 1 1 2 2 2 2  2 3 3 3

```
                          23
               /                       \
              9                        14
       /            \              /         \
      4              5            8           |
   /     \         /   \       /     \        |
  2       2       2     |     4       4       6
 / \     / \     / \    |    / \     / \     / \
t   a   l   r   n   h   s   p   i   c   e   o   m
1   1   1   1   1   1   3   2   2   2   2   3   3
```

- Construct the codes from the tree. Left is 0 and right is 1.

```
                          23
               /0
              9                        14
       /0           \              /         \
      4              5            8           |
   /0    \1        /   \       /     \        |
  2       2       2     |     4       4       6
0/ \1    / \     / \    |    / \     / \     / \
t   a   l   r   n   h   s   p   i   c   e   o   m
^

```