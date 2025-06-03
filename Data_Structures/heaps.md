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

```
Algorithm insert( item )
    if (heap is full)
        return false
    end if
    last = last + 1
    heap[last] = item
    reheapUp(last)
    return true
end guess
// O(log N)
```

- Root is always index 0
- Formula to find parent: `floor((i - 1) / 2)`
- Formula for left child: `2i + 1`
- Formula for right child: `2i + 2`
- Always remove the root
	- Swap root for right most leaf
	- Remove right most leaf
	- re-heap root down
- Insert always as a leaf
	- Insert as a leaf
	- Re-heap up
- Converting array to heap
	- O(n)


- The unsorted array can be viewed as an unsorted binary tree.
- In order to sort one branch of the tree, it requires O(log N) for shift up.
- You have to sort all branches of this tree which is O(N).
- Therefore, it's O(N log N).
- However, there's a more efficient algorithm.
- Start from the last non-leaf node and move backward to the root.
- For each of those nodes, perform a shift down operation.
- Since it's a tree, nodes closer to the leaves require less work to shift down.
- This results in an overall time complexity of O(N).

https://www.youtube.com/shorts/4NYk5vW_5yc