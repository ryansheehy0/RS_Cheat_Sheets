[Home](../README.md#algorithms)

# Huffman Codes
Optimal loss-less variable length compression algorithm.

Encoding: O(n log n)
Decoding: O(n)

- https://www.youtube.com/watch?v=B3y0RsVCyrw


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
               0/                       \1
               9                        14
       0/            \1            0/         \1
       4              5            8           |
   0/     \1       0/   \1     0/     \1       |
   2       2       2     |     4       4       6
 0/ \1   0/ \1   0/ \1   |   0/ \1   0/ \1   0/ \1
 t   a   l   r   n   h   s   p   i   c   e   o   m
 ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
0000 |   |   |   |   |   |   |   |   |   |   |   |
    0001 |   |   |   |   |   |   |   |   |   |   |
        0010 |   |   |   |   |   |   |   |   |   |
            0011 |   |   |   |   |   |   |   |   |
                0100 |   |   |   |   |   |   |   |
                    0101 |   |   |   |   |   |   |
                        011  |   |   |   |   |   |
                            1000 |   |   |   |   |
                                1001 |   |   |   |
                                    1010 |   |   |
                                        1011 |   |
                                            110  |
                                                111
```

- Compress the original value.
   - o   p    t    i    m   a    l    c    o   m   p    r    e    s   s   i    o   n
   - 110 1000 0000 1001 111 0001 0010 1010 110 111 1000 0011 1011 011 011 1001 110 0100

- Decode
   - Start at the root and go left with a $0$ and right with a $1$.

## Downside
- The coding table must be stored with the docuemnt to uncompress it
   - Eats into space savings for short documents
- Only exploit non-uniform sybol distibition
   - Can't recognize patters like 01010101...

## Code

```C++
string_view huffmanCode(string_view value, BinaryTree& bt) {
   // Count the occurrences of each letter
   unordered_map<char, int> occurrences;
   for (char c : occurrences) {
      occurrences[c]++;
   }

   // Create priority queue

   priority_queue<pair<string, int>> occurrences;

   for (char c : value) {
      if () // c is in occurences
         // +1 to occurences
      else {
         pair<string, int> newOccurrence(c, 1);
         occurrences.push_back(newOccurrence);
      }
   }

   // Create binary tree

   // Encode
}
```