[Home](../README.md)

# Optimizations in C++

- Do division by power of 2s
- X % Y is the same as X - Y * (X / Y)
- Try to prevent branching
	- Make your most probable code in the first if statement
	- Use && to prevent branching
- n/5 is the same as 2^14/5 * n / 2^34
- Multi-threading
- SIMD
- Approximation algorithms

	- What algorithms?
		- CPU optimized neural nets
		- Memory managed hash tables
		- Distinction between my own ideas and already pre-defined ideas.

- 4 * (X/4) + 3 is the same as R | 3
	- x / 4 shifts right by 2
	- 4 * shifts left by 2
	- + 3 adds 11
	- This is the same as bitwize OR with 3

- Modulus
	- `x % y` is the same as `x & (y - 1)`
		- Is that true?

- Branchless programming
- Move things to compile time instead of run time.