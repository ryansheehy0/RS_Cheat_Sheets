[Home](../README.md#algorithms)

# Sorting Algorithms
- Internal sorting - Requires all data to fit into RAM.
- External sorting - Handles data larger than RAM by using disk storage.
	- The [merging](#merging) algo allows you to merge separate sorted lists into a larger sorted list.

| Sorting algo                      | Best       | Average    | Worst      | Fast | Internal/External |
|-----------------------------------|------------|------------|------------|------|-------------------|
| [Selection sort](#selection-sort) | O(N^2)     | O(N^2)     | O(N^2)     | No   | Internal          |
| [Heap sort](#heap-sort)           | O(N)       | O(N log N) | O(N log N) | Yes  | Internal          |
| [Insertion sort](#insertion-sort) | O(N)       | O(N^2)     | O(N^2)     | No   | Both              |
| [Shell sort](#shell-sort)         | O(N)       | O(N^1.5)   | O(N^2)     | No   | Internal          |
| [Quick sort](#quick-sort)         | O(N log N) | O(N log N) | O(N^2)     | Yes  | Internal          |
| Merge sort                        | O(N log N) | O(N log N) | O(N log N) | Yes  | Both              |
| Radix sort                        | O(N)       | O(N)       | O(N)       | Yes  | Both              |

## Selection sort
Has a sorted and unsorted part. Repeatedly selects the min value from the unsorted part and places it at the beginning of the sorted part.

```C++
int findMinI(int arr[], int size, int startI) {
   int minI = startI;
   for (int i = startI + 1; i < size; i++) {
      if (arr[i] < arr[minI]) minI = i;
   }
   return minI;
}

void selectionSort(int arr[], int size) {
   for (int unsortedI = 0; unsortedI < size; unsortedI++) {
      int minI = findMinI(arr, size, unsortedI);
      // Swap
      int temp = arr[unsortedI];
      arr[unsortedI] = arr[minI];
      arr[minI] = temp;
   }
}
```

### Heap sort
Uses a heap to find the min instead of linear search.

```C++
void heapSort(int arr[], int size) {
   MinHeap h(arr, size); // Creates heap of {key: arr[i], value: i}
   for (int unsortedI = 0; unsortedI < size; unsortedI++) {
      int minI = h.pop().value;
      // Swap
      int temp = arr[unsortedI];
      arr[unsortedI] = arr[minI];
      arr[minI] = temp;
   }
}
```

## Insertion sort
Has a sorted and unsorted part. Repeatedly selects the first element of the unsorted part and places it in the correct location in the unsorted part.

```C++
void insertionSort(int arr[], int size) {
   for (int unsortedI = 1; unsortedI < size; unsortedI++) {
      int key = arr[unsortedI];
      int j;
      for (j = unsortedI - 1; j >= 0; j--) {
         if (arr[j] < key) break;
         // Shift right
         arr[j + 1] = arr[j];
      }
      // Set key's location
      arr[j + 1] = key;
   }
}
```

### Shell sort
Imagine the array as K interleaved subarrays. Perform insertion sort on each subarray individually. Reduce K and repeat until K = 1, then do a final insertion sort on the full array.

- Gap sequences are often built in increasing order and then reversed. There's no single optimal sequence, but here are some common ones:
   - Sedgewick's `4^k + 3 * 2^(k-1) + 1` - 1, 5, 19, 41, 109
   - Knuth's `3k + 1` - 1, 4, 13, 40, 121

```C++
void insertionSortInterleaved(int arr[], int size, int startingIndex, int gap) {
   for (int unsortedI = startingIndex + gap; unsortedI < size; unsortedI += gap) {
      int key = arr[unsortedI];
      int j;
      for (j = unsortedI - gap; j >= 0; j -= gap) {
         if (arr[j] < key) break;
         // Shift right
         arr[j + gap] = arr[j];
      }
      arr[j + gap] = key;
   }
}

void shellSort(int arr[], int size) {
   // Construct gap sequence and reverse it
   vector<int> Ks;
   for (int k = 1; k < size; k = 3*k + 1) {
      Ks.push_back(k);
   }
   reverse(Ks.begin(), Ks.end());
   // For each K
   for (int k : Ks) {
      for (int i = 0; i < k; i++) { // Insertion sort on each interleaved array
         insertionSortInterleaved(arr, size, i, k); // When k = 1, it acts like regular insertion sort
      }
   }
}
```

## Quick sort
Select a pivot value in the array. Move all elements less than to the left and all elements greater than to the right. Recursively repeat for the left and right sub-arrays, not including the pivot.

```C++
void quickSort(int arr[], int size, int startIndex = 0, int endIndex = -1) {
   if (endIndex == -1) endIndex = size;
   if (endIndex <= startIndex) return; // Base case when sub-array size is 0 or 1
   int pivotI = partition(arr, size, startIndex, endIndex);
   quickSort(arr, size, startIndex, pivotI); // Quick sort left half
   quickSort(arr, size, pivotI + 1, endIndex); // Quick sort right half
}

int partition(int arr[], int size, int startIndex, int endIndex) {
   int pivotI = startIndex + (endIndex - startIndex) / 2;
      // (startIndex + endIndex) / 2 also works, but will overflow if size > INT_MAX / 2
   int pivot = arr[pivotI];
   while (true) {
      while (arr[startIndex] < pivot) startIndex++; // Move the start index right until you find an element out of place.
      while (arr[endIndex] > pivot) endIndex--; // Move the end index left until you find an element out of place.
      if (startIndex >= endIndex) break; // They have passed each other or are equal
      // Swap
      int temp = arr[startIndex];
      arr[startIndex] = arr[endIndex];
      arr[endIndex] = temp;
      // Next elements
      startIndex++;
      endIndex--;
   }
   return endIndex;
}
```

## Merging
Algorithm when you need to merge two sorted array.

```C++
int* merge(int arr1[], int size1, int arr2[], int size2) {
   int* returnArr = new int[size1 + size2];
   int i = 0, i1 = 0, i2 = 0;
   // Compare and copy the lesser one
   while (i1 < size1 && i2 < size2) {
      if (arr1[i1] < arr2[i2]) {
         returnArr[i] = arr1[i1];
         i1++;
      } else {
         returnArr[i] = arr2[i2];
         i2++;
      }
      i++;
   }
   // Copy if remaining elements
   while (i1 < size1) {
      returnArr[i] = arr1[i1];
      i++;
      i1++;
   }
   while (i2 < size2) {
      returnArr[i] = arr2[i2];
      i++;
      i2++;
   }

   return returnArr;
}
```