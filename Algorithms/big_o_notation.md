[Home](../README.md)

# Big O notation
- Algo efficiency defined based on the number of inputs.
- Big O notation focuses on the dominant term, describing how a function behaves as n approaches infinity.

- How fast and how much memory

- Algo with a polynomial runtime is efficient.
- NP-complete problems - Set of problems which no known efficient algo exists.
	- No efficient algo has been found.
	- No one has proven than an efficient algo is impossible.
	- If an efficient alo exists for one NP problem, then all NP problems can be solved efficiently.

- Code in sequence, the runtimes add, but for Big O, take the dominant term.

- O(1) - Constant. Doesn't depend on n.
- O(log n) - Log
	- Instead of incrementing by 1, you multiply by a positive, non-one, constant.
- O(n) - Linear
	- Non-nested for loops based on n
- O(n log n) - linear log
	- A O(n) function is called in a log n loop.
- O(n^2) - Quadratic
	- Square matrixes, nested for loops based on n.
- O(n^k) - Polynomial when k > 2
	- Nested for loops based on n. Power depends on how many nestings.
- O(c^n) - Exponential when c > 1
- O(n!) - Factorial