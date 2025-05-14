[Home](../README.md#algorithms)

# Search Algorithms
Search algorithms find the index of a specific value in an array. If the value is not found, they return -1.

<!-- TOC -->

- [Linear Search](#linear-search)
- [Binary Search](#binary-search)
- [Interpolation Search](#interpolation-search)
- [Integral Search](#integral-search)

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
- O(log n) specifically floor(log2(n)) + 1
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

## [Integral Search](#search-algorithms)
Imagine you're trying to guess a number someone is thinking of from 1 to 10. You could use binary search, where you guess in the middle(5), and keep repeating until you find the number. However, this doesn't take into account the probability distribution of how people think of numbers. It assumes that all numbers are equally likely to be thought of. Instead, if you have the distribution, you should guess which number balances each side's area under the curve(integral). This increases the odds of guessing the number someone has thought of.

```
            |                        ___
Probability |        ___            |   |___
            |    ___|   |___     ___|       |___
            |___|           |___|               |___
            |
            +---------------------------------------
              1   2   3   4   5   6   7   8   9   10
```

```
Integral Search

1st guess: 6
  2nd guess low: 3
    3rd guess low: 2
      4th guess: 1 // The 4th guesses are the least likely to be chosen.
    3rd guess high: 4
      4th guess: 5
  2nd guess high: 8
    3rd guess low: 7 // The guaranteed 3rd guess is the most likely to be chosen.
    3rd guess high: 9
      4th guess: 10
```

```
Binary Search

1st guess: 5
  2nd guess low: 2
    3rd guess low: 1
    3rd guess high: 3
      4th guess: 4
  2nd guess high: 8
    3rd guess low: 6
      4th guess: 7
    3rd guess high: 9
      4th guess: 10
```