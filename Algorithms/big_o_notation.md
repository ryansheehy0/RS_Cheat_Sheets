[Home](../README.md#algorithms)

# Big O notation
An algorithm can run faster on a faster process. Therefore, to compare algorithms, the number of constant time operations, an operation that always executes in the same amount of time, is used. These are expressed in terms of the length of the input N.
- Small inputs are likely to result in fast running times so efficiency is less of a concern.

Big O notation focuses on the dominant term, describing how a function behaves as n approaches infinity.

- Code in sequence, the runtimes add, but for Big O, take the dominant term.

The order of big O complexity from most efficient to least.

| Big O      | Name                   | Description                                                  | Example          |
|------------|------------------------|--------------------------------------------------------------|------------------|
| O(1)       | Constant               | Doesn't depend on N.                                         | If statements    |
| O(log N)   | Logarithmic            | For loop that increments my multiplying or decs by division. | Binary search    |
| O(N)       | Linear                 | For loops based on N.                                        | Linear search    |
| O(N log N) | Linear Logarithmic     | Linear function is called in a Log N loop or vise versa.     | Merge sort       |
| O(N^2)     | Quadratic              | 2 nested for loops based on N.                               | Selection sort   |
| O(N^k)     | Polynomial when k > 2  | The power depends on how many nestings.                      |                  |
| O(c^N)     | Exponential when c > 1 |                                                              | Fibonacci number |
| O(N!)      | Factorial              |                                                              |                  |

**NP-Complete problems** - Problems where no known polynomial runtime algo is known, but no one has proven that it doesn't exist.
	- Many NP-Complete problems are similar, to where if one is found to have an efficient algorithm, then many others will also have one.

## Recursion
- Binary search is T(N) = k + T(N/2) which is O(log N)
- If it calls 2 recursive calls with T(N/2) then it's O(N log N)
- T(N) = constant + T(N-1) has O(N)