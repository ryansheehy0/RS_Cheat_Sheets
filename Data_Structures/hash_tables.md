[Home](../README.md#data-structures)

# Hash Tables
Hash tables use a lot of memory for faster operations, best case O(1).


## [Resizing](#hash-tables)

## [Collision handling](#hash-tables)

## [Common hash functions](#hash-tables)


- All keys are stores in the range Ex: [0-9].
- Can use a fixed size array to store elements.
- Searching takes O(1) time assuming there are no more than one element in the cell

- Hash tables store unordered items by mapping/hashing each item to a location called a bucket.
- A hash map is an implementation of a map ADT using a hash table.
	- What is a map adt? Key value pairs.

- hashCode = hash(key/value/data)
- index = hashCode % arraySize

- Collision - 2 different keys map to the same bucket index.
	- Chaining - Each bucket has a list of items
	- Open addressing - Looking for an empty bucket elsewhere.
		- Linear probing
			- If there's a collision when inserting, then linear search down until you find an empty bucket.
			- If not found at the correct index when searching, then linear searching down the buckets until you find the element or an empty from start bucket or reached the starting index again.
				- When searching, loop back to the top.
			- Empty buckets need to be labeled empty since start or empty after removal.
				- Over time, all empty buckets will be empty after removal.
		- Quadratic probing - Spreads out bullets more evenly compared to linear probing.
			- nextIndex = (hash(value) + c1 * i + c2 * i^2) % arraySize
				- c1 and c2 are constants. c1 = 1 and c2 = 1 often works well.

- Resizing - New array is created, usually to the size of the next prime number.
	- All elements are then inserted into this new array in O(N) time.
	- Load factors = numOfFilledBuckets / numOfBuckets; Used to decide when to resize.
		- Load factor cannot exceed 1 for open addressing.
	- When chaining, the size of a bucket's largest linked list.

- A perfect hash function can be created if the number of items and all possible keys are known beforehand.

- Common hash functions
	- Modulo: value % arraySize
	- Mid-square: extractMiddleDigits(value^2) % arraySize
	- Multiplicative string: Multiplies each character of a string by a multiplier and mods at the end.
		- Good for short english strings

```C++
int hashMiddleSquare(int value) {
	const int numOfBits = 24;
	int square = value * value;

	int lowBitsToRemove = (sizeof(int) - numOfBits) / 2;

	// This is usually done in binary instead of decimal due to the simplification
	int middleBits = value >> lowBitsToRemove; // Shift off lower bits
	middleBits = middleBits & (~0 >> (32 - numOfBits));

	return middleBits;
}
```

```C++
// index = (a * key + b) % size
	// a, b, and size are all prime
int hashMultiplicative(string value) {
	int hash = 5381;
	const int multiplier = 33; // Usually prime
	for (int i = 0; i < value.size(); i++) {
		char c = value.at(i);
		hash = (hash * multiplier) + c;
	}
	return hash;
}
```

- Add up all ascii characters % size
	- Square or cube before adding for larger index.

- Hash table of linked lists, with each linked list having a sentinel.
	- Takes up more mem.

- Synonyms - In linked list collision resolution, synonyms are keys that hash to the same index and are chained together.

- Common hash methods
	- midsquare
	- direct
	- rotation
	- folding
	- digit extraction
	- modulo division
	- subtraction

- Trades memory space for faster loopups.

- I prefer linked list chaining for two main reasons.
- First, when a collision occurs, the new item is added to a list at the original index, rather than taking up a spot that could belong to a different key.
- Linear probing can lead to a chain reaction where multiple items are moved out of their original index, decreasing efficiency.
- Second, collisions are supposed to be rare in a good hash function, meaning chains tend to be short, and thus linear searching shouldn't take long.
- Whereas, the worst case for linear probing is having to search through the whole table, O(n).

- The linked lists should be sorted so you can exit early if your item is greater than the current one you're searching.