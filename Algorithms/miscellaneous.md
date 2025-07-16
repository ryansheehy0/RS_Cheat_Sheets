[Home](../README.md#algorithms)

# Miscellaneous Algorithms

<!-- TOC -->

- [Unique Permutations](#unique-permutations)
- [Greatest Common Denominator](#greatest-common-denominator)
- [Testing prime](#testing-prime)

<!-- /TOC -->

## [Unique Permutations](#miscellaneous-algorithms)
Algorithm to get all the unique permutations of an array.

```
            ___________0,1,2___________
           /             |             \
        0,1,2          1,0,2          2,1,0
       /     \        /     \        /     \
    0,1,2   0,2,1  1,0,2   1,2,0  2,1,0   2,0,1
```

```C++
void uniquePermutations(string remainingChars, string pickedChars) {
	static string curPermutation;
	if (remainingChars.size() == 0) {
		// Print all picked chars
		for (int i = 0; i < pickedChars.size(); i++) {
			cout << pickedChars.at(i);
		}
		cout << "\n";
	} else {
		for (int i = 0; i < remainingChars.size(); i++) {
			char picked = remainingChars.at(i); // Choose the next picked element
			// Create the new remaining chars by removing the element that was picked
			string newRemainingChars = remainingChars;
			newRemainingChars.erase(newRemainingChars.begin() + i);
			uniquePermutations(newRemainingChars, pickedChars + picked);
		}
	}
}
```

remainingChars: 012   pickedChars:
	i: 0
		picked: 0
		remainingChars: 12   pickedChars: 0
			i: 0
				picked: 1
				remainingChars: 2   pickedChars: 01
					i: 0
						picked: 2
						remainingChars:   pickedChars: 012
							print: 012
					i: 1 end loop
			i: 1
				picked: 2
				remainingChars: 1   pickedChars: 02
					i: 0
						picked: 1
						remainingChars:   pickedChars: 021
							print: 021
			i: 2 end loop
	i: 1
		picked: 1
		etc

## [Greatest Common Denominator](#miscellaneous-algorithms)
The greatest common denominator is that largest number that can evenly divide into two other numbers.

1. Subtract the smaller number from the larger.
2. Keep repeating with the smaller of the 2 inputs.

- Ex: GCD(12, 8)
	- 12 - 8 = 4
	- 8 - 4 = 4
	- 4 - 4 = 0, they are the same so the GCD is 4.

- Ex2: GCD(84, 14)
	- 84 - 14 = 70
	- 70 - 14 = 56
	- 56 - 14 = 42
	- 42 - 14 = 28
	- 28 - 14 = 14
	- 14 - 14 = 0, they are the same so the GCD is 14

## [Testing prime](#miscellaneous-algorithms)

```C++
bool isLikelyPrime(unsigned int x) {
	switch (x) {
		case 0:
		case 1:
		case 4:
		case 6:
		case 8:
		case 9:
		case 10:
			return false;
		case 2:
		case 3:
		case 5:
		case 7:
		case 11:
			return true;
	}
	// Fermat's little theorem: a - random number between 2 and x
		// If a^(x-1) mod x is not 1, then it's not prime
		// else it is most likely prime, but do more tests to increase probability
	const int tests = 1;
	for (int i = 0; i < tests; i++) {
		int a = rand() % (x - 3) + 2; // between 2 and x
		if (powerMod(a, x - 1, x) != 1) return false;
	}
	return true;
}

int powerMod(int base, int exponent, int mod) const { // O(log exponent)
	// https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
	// Ex:
		// 3^5 % 6 =
		// (3^4 * 3^1) % 6 =
		// ((3 * 3 % 6) * (3 * 3 % 6)) * (3^1 % 6) =
	int64_t result = 1;
	base %= mod;
	while (exponent) {
		if (exponent & 1) result = (result * base) % mod;
		base = (base * base) % mod;
		exponent >>= 1;
	}
	return result;
}
```