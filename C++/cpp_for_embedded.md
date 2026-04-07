[Home](../README.md#c)

# C++ for Embedded
- `#progma once` instead of `#ifndef`
- C++98
	- Better casts. Easier to search for.
	- Templates
	- Classes and overloading methods
	- RAII(destructor automatically runs when obj out of scope)
- C++11
	- Compile time checks
	- Enum class insead of enums
	- `constexpr` instead of `#define`
- C++14
	- Binary literals(`0b0101`)
	- Digit separators(`123'456`)

- No excptions(throw/catch)
	- Overload terminate function to catch exceptions.
- Turn off RTTI in compiler options
	- Removes runtime polymorphism
- Overload new and delete so libraries don't use them.
- Use printf instead of cout
	- cout uses a buffer
- 