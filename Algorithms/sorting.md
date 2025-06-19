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
- Sorted part and unsorted part
- Repeatedly selects the min value from unsorted to the end of the sorted.
- O(N^2)
- Internal sorting

### Heap sort
- More advanced for of selection sort

## Insertion sort
- Sorted part and unsorted part
- Repeatedly inserts the next unsorted into the sorted section.
- O(N^2) and O(N) for nearly sorted lists.
- 2 types: swapping vs shifting. Shifting is preferred.
	- Swapping - Store right into temp. Assign right with left. Assign left with temp.
	- Shifting - Store unsorted into temp. Assign right with left.
		- Save an operation by not needing to assign left with temp.
- External sorting

- i - current position of next unsorted element(starts at 1)
- j - current position of element being inserted(j=i then counts down to 0)

### Shell sort
- More advanced for of insertion sort
- Input as a collection of interleaved arrays, and sorts each array individually.
- gap value/K - positive int representing the distance between elements in an interleaved array.
	- Next element of interleaved array is at i + gap value.
- Finishes with a standard insertion sort on the entire array, merging the interleaved arrays.

InsertionSortInterleaved(array, arrSize, startingIndex, gapValue)
	- Sorts one interleaved array.
	- Have to call the # of times for each gapValue and increment startingIndex each time
- Ex: gapValue = 2
InsertionSortInterleaved(array, arrSize, 0, 2)
InsertionSortInterleaved(array, arrSize, 1, 2)
Then insertionSort for the whole array to get the final sorted array.

- K is initially large, insertionSortInterleaved is run on K-separated elements, then K is decreased and the process repeats.
- Insertion sort when k == 1
- What is the optimal decreasing rate of k?
	- Powers of 2 minus 1. Ex: n = 100. K = 63, 31, 15, 7, 3, 1. O(N^3/2) worst case.
	- There is no optimal decreasing rate of k, but Knuth(k = 2^n - 1/2) is good.

```C++
InsertionSortInterleaved(numbers, numbersSize, startIndex, gap) {
   i = 0
   j = 0
   temp = 0  // Temporary variable for swap

   for (i = startIndex + gap; i < numbersSize; i = i + gap) {
      j = i
      while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
         temp = numbers[j]
         numbers[j] = numbers[j - gap]
         numbers[j - gap] = temp
         j = j - gap
      }
   }
}

ShellSort(numbers, numbersSize, gapValues) {
   for each (gapValue in gapValues) {
      for (i = 0; i < gapValue; i++) {
         InsertionSortInterleaved(numbers, numbersSize, i, gapValue)
      }
   }
}
```

## Quick sort
- Repeatedly partitions the input into low and high parts, and then recursively sorts each part.
- Pivot - Element that divides the data into low and high parts.
	- Can be any index, but is usually the middle.
- All values in the low partition are less than or equal to the pivot value.
- All values in the high partition are greater than or equal to the pivot value.
- 2 index variables. Low and high
	- Low starts at 0 and increments to the center
	- High starts at length-1 and decrements to the center
- Worst case is O(N^2), but average and best case is O(N log N).
- The pivot is not included in the recursive calls.

```C++
Partition(numbers, lowIndex, highIndex) {
   // Pick middle element as pivot
   midpoint = lowIndex + (highIndex - lowIndex) / 2
   pivot = numbers[midpoint]

   while (true) {
      while (numbers[lowIndex] < pivot) lowIndex++;
      while (pivot < numbers[highIndex]) highIndex--;
      if (lowIndex >= highIndex) break;
			// Swap numbers[lowIndex] and numbers[highIndex]
			temp = numbers[lowIndex]
			numbers[lowIndex] = numbers[highIndex]
			numbers[highIndex] = temp

			// Update lowIndex and highIndex
			lowIndex++;
			highIndex--;
   }
   return highIndex
}

Quicksort(numbers, lowIndex, highIndex) {
   if (highIndex <= lowIndex) return;
   lowEndIndex = Partition(numbers, lowIndex, highIndex)
   Quicksort(numbers, lowIndex, lowEndIndex)
   Quicksort(numbers, lowEndIndex + 1, highIndex)
}
```

## Merging