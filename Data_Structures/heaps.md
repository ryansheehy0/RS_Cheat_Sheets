[Home](../README.md#data-structures)

# Heaps
- Binary tree in an array
- root, left, right, left left, left right, right left, right right, etc.
	- if no left/right, then leave a gap.
	- more levels means more space between nodes.
		- If levels change often, then heaps are bad.
		- If tree close to complete(only gaps on the bottom level) tree, then array is good
- Heaps are complete trees
- maxheap - root contains the largest. Each sub-tree is also a maxheap
- minheap - 

- no search function
- isFull()
- 

```C++
template <typename T>
class Heap {
	private:
		heapAry
		heapSize
		int count = 0;
	public:
		getCount
		getSize
		isEmpty
		isFull
		insert();
		pop();
	private:

};
```

## Constructor

- Convert array to heap
	- O(N log N)
	- 

## Insert
- New node always added as a leaf. At the end of the array.
	- What if it's the largest/smallest
	- Worst case O(Log n)

```C++
template <type>

if (parent > value)
	// do nothing
else
	// swap for parent
	// Repeat for the next parent
```

## pop
- Remove larges, and the 2nd largest will be updates
	- Updating is O(log N) time.
- Removes the root
	- Move the end leaf to the root
	- Remove the last leaf
	- Swap root for the greater of the 2 children(reheapDown)
	- Recursively apply this until you get to the end

## Use cases
- Can find max/min of an array in O(1) time.
- heap sort - O(N log N)
	- Selection sort, but with a heap instead of an array
- Priority queues
	- key  = priority * 10 + 
- Huffman encoding algo