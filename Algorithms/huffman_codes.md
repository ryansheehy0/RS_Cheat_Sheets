[Home](../README.md#algorithms)

# Huffman Codes
Optimal(min bits) loss-less variable length compression algorithm.

```
  +-------+                                         +-----+
  | Alice | --------------------------------------> | Bob |
  +-------+                                         +-----+
  1. Generate Huffman codes from message            1. Decode message using codes
  2. Encode message using codes
  3. Send codes, then encoded message
```

| Operation                | Big O      |
|--------------------------|------------|
| Generating huffman codes | O(n log n) |
| Encoding                 | O(n)       |
| Decoding                 | O(n)       |

<!-- TOC -->

- [Algorithm](#algorithm)
- [Code](#code)
	- [Generating huffman codes](#generating-huffman-codes)
	- [Encoding](#encoding)
	- [Decoding](#decoding)
- [Huffman codes for english](#huffman-codes-for-english)

<!-- /TOC -->

## [Algorithm](#huffman-codes)
Example message: optimal compression scheme
1. Count the occurrences of each character.

```
o p t i m a l c r e s n h
3 2 1 2 3 1 1 2 1 2 3 1 1
```

2. Sort from low to high

```
t a l r n h p i c e s o m
1 1 1 1 1 1 2 2 2 2 3 3 3
```

3. Merge two smallest nodes, add their occurrences, and re-insert. Do this until there's only one node left.

```
Iteration 1:
   l r n h p i c e ta s o m
   1 1 1 1 2 2 2 2  2 3 3 3
Iteration 2:
   n h p i c e ta lr s o m
   1 1 2 2 2 2  2  2 3 3 3
Iteration 3:
   p i c e ta lr nh s o m
   2 2 2 2  2  2  2 3 3 3
Iteration 4:
   c e ta lr nh s o m pi
   2 2  2  2  2 3 3 3  4
Iteration 5:
   ta lr nh s o m pi ce
    2  2  2 3 3 3  4  4
Iteration 6:
   nh s o m pi ce talr
    2 3 3 3  4  4    4
Iteration 7:
   o m pi ce talr nhs
   3 3  4  4    4   5
Iteration 8:
   pi ce talr nhs om
    4  4    4   5  6
Iteration 9:
   talr nhs om pice
      4   5  6    8
Iteration 10:
   om pice talrnhs
    6    8       9
Iteration 11:
   talrnhs ompice
         9     14
Iteration 12:
   talrnhsompice
              23
```

4. This creates a binary tree which the codes are constructed from. Left is 0 and right is 1.


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

5. Encode/Decode

```
o   p    t    i    m   a    l    c    o   m   p    r    e    s   s   i    o   n
110 1000 0000 1001 111 0001 0010 1010 110 111 1000 0011 1011 011 011 1001 110 0100
```

- **Canonical Huffman** is a common variant where it adjusts Huffman codes so only the bit lengths for each character must be sent to the decoder.

## [Code](#huffman-codes)

### [Generating huffman codes](#huffman-codes)
- Is there a way to get a node from a binary search tree and re-construct a binary search tree?
	- Maybe you just create your own node struct.

```C++
unordered_map<char, string> huffmanCodes(string_view message) {
   unordered_map<char, string> codes;

   // Count the occurrences of each letter
   unordered_map<char, int> occurrences;
   for (char c : occurrences) {
      occurrences[c]++;
   }

   /*
		struct Node {
			T data;
			Node* left = nullptr;
			Node* right = nullptr;
		}
   */

   // Create and fill priority queue
   priority_queue<BinaryTree::Node<pair<string, int>>*> nodeQueue;

   for (pair<char, int> character : occurrences) {
      BinaryTree::Node* node = new BinaryTree::Node<pair<string, int>>;
      node->data.first = character.first; // Set string name
      node->data.second = character.second; // Set occurrences count
      nodeQueue.push_back(node);
   }

   // Create binary tree
   while (nodeQueue.size() > 1) {
      BinaryTree::Node<pair<string, int>>* firstNode = nodeQueue.pop();
      BinaryTree::Node<pair<string, int>>* secondNode = nodeQueue.pop();
      // Combine nodes
      BinaryTree::Node* newNode = new BinaryTree::Node<pair<string, int>>;
      newNode->data.first = firstNode->data.first + secondNode->data.first;
      newNode->data.second = firstNode->data.second + secondNode->data.second;
      newNode->left = firstNode;
      newNode->right = secondNode;
      // Push combined node back into priority queue
      nodeQueue.push(newNode);
   }

   // Create codes from binary tree
   BinaryTree::Node<pair<string, int>>* parent = nullptr;
   BinaryTree::Node<pair<string, int>>* root = nodeQueue.pop();
   BinaryTree::Node<pair<string, int>>* curRoot = root;
   string curCode = "";
   while (true) { // Something to do with curRoot == root?
      if (curRoot->left) {
         parent = curRoot;
         curRoot = curRoot->left;
         curCode += "0";
         continue;
      }
      if (curRoot->right) {
         
      }
      char character = curRoot->data.first[0];
      codes[character] = curCode;
   }
   // if left child
   // if right child
      // set parent
      // set new root
   // Get string of 1/0s
   // Add to output

   // Free memory? or does this happen when they go out of scope?
}
```

### [Encoding](#huffman-codes)

```C++
string huffmanEncode(unordered_map<char, int>, string message);
```

### [Decoding](#huffman-codes)

```C++
string huffmanDecode(unordered_map<char, int>, string message);
```

## [Huffman codes for english](#huffman-codes)

| char  | Code        |
|-------|-------------|
| space | 111         |
| e     | 010         |
| t     | 1101        |
| a     | 1011        |
| o     | 1001        |
| i     | 1000        |
| n     | 0111        |
| s     | 0011        |
| h     | 0010        |
| r     | 0001        |
| l     | 10101       |
| d     | 01101       |
| c     | 00001       |
| u     | 00000       |
| f     | 110011      |
| m     | 110010      |
| w     | 110001      |
| y     | 101001      |
| p     | 101000      |
| g     | 011001      |
| b     | 011000      |
| v     | 1100000     |
| k     | 11000011    |
| x     | 110000100   |
| j     | 1100001011  |
| q     | 11000010101 |
| z     | 11000010100 |

Using english Huffman Codes is more efficient for short messages because you don't need to send the codes along with the message. It's only worth encoding a message with its own Huffman codes if `custom encoding length + custom codes length < english encoding length`