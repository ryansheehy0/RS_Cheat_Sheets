[Home](../README.md)

# Unique Permutations
Algorithm to get all the unique permutations of an array.

```
            ___________0,1,2___________
           /             |             \
        0,1,2          1,0,2          2,1,0
       /     \        /     \        /     \
    0,1,2   0,2,1  1,0,2   1,2,0  2,1,0   2,0,1
```

```javascript
let arr = ["0", "1", "2"]

function getUniquePermutations(arr){
	let uniquePermutations = []

	function recursivePermutations(arr, unswappedIndex){
		if(unswappedIndex === arr.length - 1){
			uniquePermutations.push([...arr])
			return
		}
		for(let i = unswappedIndex; i < arr.length; i++){
			// Swap
			let temp = arr[unswappedIndex]
			arr[unswappedIndex] = arr[i]
			arr[i] = temp
			recursivePermutations(arr, unswappedIndex + 1)
			// Unswap
			temp = arr[unswappedIndex]
			arr[unswappedIndex] = arr[i]
			arr[i] = temp
		}
	}

	recursivePermutations(arr, 0)
	return uniquePermutations
}

console.log(getUniquePermutations(arr))

/*
[
  [ '0', '1', '2' ],
  [ '0', '2', '1' ],
  [ '1', '0', '2' ],
  [ '1', '2', '0' ],
  [ '2', '1', '0' ],
  [ '2', '0', '1' ]
]
*/
```