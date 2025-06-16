[Home](../README.md#data-structures)

# Heaps
Heaps are complete binary trees that are stored in arrays. They can either be maxHeaps(parent larger than its children) or minHeaps(parent smaller than its children). They can find the max/min of an array in O(1) time.

```
          10
        /    \
      4       9  ->  10, 4, 9, 3, 1, 7
     / \     /
    3   1   7
The root is always at index 0.
```

<!-- TOC -->

- [Heapify constructor](#heapify-constructor)
- [reHeap Up](#reheap-up)
- [reHeap Down](#reheap-down)
- [Inserting/Push](#insertingpush)
- [Removing/Pop](#removingpop)
- [Use cases](#use-cases)

<!-- /TOC -->

- Change to Templates
- Rename to push and pop
- Change indexes to unsigned ints.
- Add resizing heaps

```C++
template <typename T>
class Heap {
    protected:
        virtual bool _compare(const T& value1, const T& value2) const = 0; // If value1 should be prioritized over value2
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
        void _resize();

    public:
        Heap() { _count = 0; _arrSize = 3; _heapArr = new T[_arrSize]; }
        Heap(T[] array);
        ~Heap() { delete[] _heapArr; }

        // Getters
        int getCount() const { return _count; }
        int getSize() const { return _arrSize; }
        bool isEmpty() const { return _count == 0; }
        bool isFull()  const { return _count == _arrSize; }

        // Insert and remove
        void push(T data);
        T pop();
        T peak() const { return _heapArr[0]; }
};

// Max and Min heaps
template <typename T>
class MaxHeap : public Heap<T> {
	private:
		bool _compare(const T& value1, const T& value2) const override {
            return value1 > value2;
		}
};

template <typename T>
class MinHeap : public Heap<T> {
	private:
		bool _compare(const T& value1, const T& value2) const override {
            return value1 < value2;
		}
};
```

## Heapify constructor
Convert an ordinary array to a heap. O(N).

```C++
template <typename T>
Heap<T>::Heap(T[] array, int arraySize) {
    _count = arraySize; _arrSize = arraySize; _heapArr = new T[arraySize];
    // Move all elements from array into the heap array
    for (int i = 0; i < arraySize; i++) {
        _heapArr[i] = array[i];
    }
    // Start from n/2 - 1 and move towards the root, heaping down each element.
        // Don't need to heap down the leaves
    for (int i = (arraySize/2) - 1; i >= 0; i--) {
        _reHeapDown(i);
    }
}
```

## reHeap Up

```C++
template <typename T>
void Heap<T>::_reHeapUp(int index) {
    int childI = index;
    int parentI = _findParent(childI);
    while (parentI != -1 && compare(_heapArr[childI], _heapArr[parentI])) {
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
template <typename T>
void Heap<T>::_reHeapDown(int index) {
    int parentI = index;
    while (true) {
        // Check for children
        int leftI = _findLeftChild(parentI);
        int rightI = _findRightChild(parentI);
        if (leftI == -1 && rightI == -1) break; // No children

        // Get preferred child index
        int preferredChildI;
        if (leftI == -1) {
            preferredChildI = rightI;
        } else if (rightI == -1) {
            preferredChildI = leftI;
        } else { // Has both children
            if (compare(heapAry[rightI], heapAry[leftI])) {
                preferredChildI = rightI;
            } else {
                preferredChildI = leftI;
            }
        }

        // Check largest child against parent
        if (compare(heapAry[preferredChildI], heapAry[parentI])) {
            // Swap
            int temp = heapAry[preferredChildI];
            heapAry[preferredChildI] = heapAry[parentI];
            heapAry[parentI] = temp;

            parentI = preferredChildI;
            continue;
        }
        break;
    }
}
```

## Inserting/Push
New nodes are always added as leafs/at the end of the array. Then that leaf is reHeapedUp. The worst case is O(log N).
- Need to add resizing

```C++
template <typename T>
void Heap<T>::push(T data) {
	if (isFull()) _resize();
    heapAry[count] = data; // Insert item at the end
    _reHeapUp(count); // Re heap up the new item
	count++;
}
```

## Removing/Pop
Popping always removes the root. It swaps the last element for the root and reHeapsDown the root. The worst case is O(log N).

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
- Heap sort - A sorting algorithm like selection sort, but uses a heap to quickly find the max element. It sorts in O(N log N).
- Priority queues
- Huffman encoding algorithm