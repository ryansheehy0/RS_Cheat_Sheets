[Home](../README.md#data-structures)

# Heaps
Heaps are complete binary trees that are stored in arrays. They can either be maxHeaps(parent larger than its children) or minHeaps(parent smaller than its children).

```
          10
        /    \
      4       9  ->  10, 4, 9, 3, 1, 7
     / \     /
    3   1   7
```

<!-- TOC -->

- [reHeap Up](#reheap-up)
- [reHeap Down](#reheap-down)
- [Insert](#insert)
- [pop](#pop)
- [Use cases](#use-cases)
- [Heapify algo](#heapify-algo)

<!-- /TOC -->

- Change to Templates
- Rename to push and pop
- Add constructor with array argument
- Change to work with max and min heaps.
	- Heap is an abstract class. maxHeap and minHeap inherit Heap and overload the compare method
- Change indexes to unsigned ints.
- Add method to increase the heap size.

```C++
template <typename T>
class Heap {
    protected:
        virtual bool compare(const T& value1, const T& value2) const = 0; // If value1 should be prioritized over value2
    private:
        T* _heapArr;
        int _arrSize;
        int _count;

        void _reHeapUp(int index);
        void _reHeapDown(int index);
        int _findParent(int index) { return (index <= 0) ? (-1) : (index - 1) / 2; }
        int _findLeftChild(int index) { return (2 * index + 1 >= count) ? (-1) : (2 * index + 1); }
        int _findRightChild(int index) { return (2 * index + 2 >= count) ? (-1) : (2 * index + 2); }
        int _getLevel(unsigned int index) { return }

    public:
        Heap() { count = 0; heapSize = 128; heapAry = new int[heapSize]; }
        Heap(int n) { count = 0; heapSize = n;	heapAry = new int[heapSize]; }
        ~Heap() { delete[] heapAry; }

        int getCount() const { return count; }
        int getSize() const { return heapSize; }
        bool isEmpty() const { return count == 0; }
        bool isFull()  const { return count == heapSize; }
        bool insertHeap(int itemIn);
        bool deleteHeap(int &itemOut);
};

template <typename T>
class MaxHeap : public Heap<T> {
	private:
		bool compare(const T& value1, const T& value2) const override {
            return value1 > value2;
		}
};


template <typename T>
class MinHeap : public Heap<T> {
	private:
		bool compare(const T& value1, const T& value2) const override {
            return value1 < value2;
		}
};
```

## reHeap Up

```C++
template <typename T>
void Heap<T>::_reHeapUp(int index) {
    int childI = index;
    int parentI = _findParent(childI);
    while (childI && compare(_heapArr[childI], _heapArr[parentI])) {
        // Swap the values
        T temp = _heapArr[childI];
        _heapArr[childI] = _heapArr[parentI];
        _heapArr[parentI] = temp;
        // Next row
        childI = parentI;
        parentI = _findParent(parentI);
    }
}
```

## reHeap Down

```C++
void Heap::_reHeapDown(int rootdex) {
    int parentI = rootdex;
    while (true) {
        // Check for children
        int leftI = _findLeftChild(parentI);
        int rightI = _findRightChild(parentI);
        if (leftI == -1 && rightI == -1) break; // No children

        // Get largest child
        int largestChildI; // preferredChildI
        if (leftI == -1) {
            largestChildI = rightI;
        } else if (rightI == -1) {
            largestChildI = leftI;
        } else { // Has both children
            if (heapAry[rightI] > heapAry[leftI]) {
                largestChildI = rightI;
            } else {
                largestChildI = leftI;
            }
        }

        // Check largest child against parent
        if (heapAry[largestChildI] > heapAry[parentI]) {
            // Swap
            int temp = heapAry[largestChildI];
            heapAry[largestChildI] = heapAry[parentI];
            heapAry[parentI] = temp;

            parentI = largestChildI;
            continue;
        }
        break;
    }
}
```

## Insert
New nodes are always added as leafs/at the end of the array. Then the last element is reHeapedUp.
- Worst case O(Log n)
- Need to add resizing

```C++
bool Heap::insertHeap(int newItem) {
	if (isFull()) return false;
	// Insert item at the end
    heapAry[count] = newItem;
    // Reheap up the new item
    _reHeapUp(count);
	count++;
	return true;
}
```

## pop
- Remove larges, and the 2nd largest will be updates
	- Updating is O(log N) time.
- Removes the root
	- Move the end leaf to the root
	- Remove the last leaf
	- Swap root for the greater of the 2 children(reheapDown)
	- Recursively apply this until you get to the end

```C++
bool Heap::deleteHeap(int &returnItem) {
	if (isEmpty()) return false;
    // Set return Item with the root
    returnItem = heapAry[0];
	// Put the last element to the root
    heapAry[0] = heapAry[count - 1];
    count--;
    // Set the last element to -1
    heapAry[count] = -1;
    // Reheap the rood down
    _reHeapDown(0);
	return true;
}
```

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

- Heapify algo
	- 

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
    - Don't include linear time.

https://www.youtube.com/shorts/4NYk5vW_5yc