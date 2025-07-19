[Home](../README.md#algorithms)

# Miscellaneous Algorithms

<!-- TOC -->

- [Unique Permutations](#unique-permutations)
- [Greatest Common Divisor](#greatest-common-divisor)
	- [Least common multiple](#least-common-multiple)
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

## [Greatest Common Divisor](#miscellaneous-algorithms)
The largest integer that divides two integers. Useful for simplifying fractions.

```c++
int gcd(int a, int b) { // Euclidean algorithm
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	if (a == 0) return -1; // Both a and b are 0
	return a;
}
```

Example: gcd(330, 156)
- 330 % 156 = 18
- 156 % 18 = 12
- 18 % 12 = 6
- 12 % 6 = 0
- gcd(330, 156) = 6

### [Least common multiple](#miscellaneous-algorithms)
The smallest integer that is a multiple of two integers.

lcm(a, b) = (a / gcd(a, b)) * b

Example: lcm(3, 4)
- 3, 6, 9, 12, 15, 18
- 4, 8, 12, 16, 20, 24
- lcm(3, 4) = 12

 Useful for giving fractions that same base.
 - Example: lcm(48, 36) = 144
- $144 / 48 = 3$ and $144 / 36 = 4$
- $\frac{1}{48} + \frac{1}{36} = \frac{1}{48} * \frac{3}{3} + \frac{1}{36} * \frac{4}{4} = \frac{3}{144} + \frac{4}{144} = \frac{7}{144}$

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