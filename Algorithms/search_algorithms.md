[Home](../README.md)

# Search Algorithms
Search algorithms find the index of a specific value in an array. If the value is not found, they return -1.

<!-- TOC -->

- [Linear Search](#linear-search)
- [Binary Search](#binary-search)
- [Interpolation Search](#interpolation-search)

<!-- /TOC -->

## [Linear Search](#search-algorithms)
Linear search goes through each element and checks to see if it's the value.
- O(n) linear time
  - Slow for large input sizes
  - Good for small/medium input sizes
- Input doesn't need to be sorted
- Good for inputs that don't allow random access like linked lists

```javascript
function linearSearch(arr, value){
  for(let i = 0; i < arr.length; i++){
    if(arr[i] === value) return i
  }
  return -1
}
```

## [Binary Search](#search-algorithms)
Binary search splits the search space in half depending if the middle of the array is less than or grater than the value. This repeats until the middle equals the value.
- O(log n) specifically log(n)/log(2) + 1
  - Slow for small input sizes
  - Fast for large input sizes
- Input needs to be sorted
- Input data structure needs to support random access like arrays

```javascript
function binarySearch(arr, value){
  let left = 0
  let right = arr.length - 1

  while(left <= right){
    const mid = Math.floor((left + right) / 2)
    const midValue = arr[mid]

    if(midValue === value) return mid

    if(midValue < value){
      left = mid + 1
    }else{
      right = mid - 1
    }
  }
  return -1
}
```

## [Interpolation Search](#search-algorithms)
Interpolation search is binary search, but instead of checking the center it makes an educated guess(probe) where the value would be in the input.

This best guess(probe) is gotten by using linear interpolation.
- The Y is the indexes of the array. The X is the values in the array.
  - $y_1$ = left, $x_1$ = arr[left]
  - $y_2$ = right, $x_2$ = arr[right]
  - $x$ = value, $y$ = probeIndex
- First, find the slope. $m = \frac{y_1 - y_2}{x_1 - x_2}$
- Second, make a line from the slope. $y = y_1 + m(x-x_1)$
- The equation for a slope and the line are combined to form the equation for probe.

Linear interpolation is best used for uniformly distributed inputs.
- Average case: O(log(log n))
- Worst case: O(n)
- Input needs to be sorted
- Input data structure needs to support random access like arrays

```javascript
function interpolationSearch(arr, value){
  let left = 0
  let right = arr.length - 1

  while(left <= right){
    const y1 = left, x1 = arr[left]
    const y2 = right, x2 = arr[right]
    const m = (y1 - y2)/(x1 - x2)
    const probeIndex = y1 + m * (value - x1)
    const probeValue = arr[probeIndex]

    if(probeValue === value) return probeIndex

    if(probeValue < value){
      left = probeIndex + 1
    }else{
      right = probeIndex - 1
    }
  }
  return -1
}
```

- If the pattern of the array follows something other than a line, you can use other equations besides linear interpolation.