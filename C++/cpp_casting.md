[Home](../README.md#c)

# C++ Casting
The purpose of casting is to convert one data type to another.
- Data. Protocols are applied to data in order to extract information.
	- When you cast you are changing the protocol.
	- You can either change the data so the information is the same between different protocols.
	- Or you can keep the data the same and the information is likely to change.


- What's the purpose of casting?
	- How is it different from converting variables?
- C-Style casting
- static_cast
- dynamic_cast
- const_cast
+ reinterpret_cast
- boost::lexical_cast

## Const Cast
`const_cast` is used to add or remove const from a variable.
- Modify or access an object that was originally declares as const, but only if the object wasn't declared as const at the time of creation.
	- What?
	- What is truly const mean?

`const_cast` can be used to add or remove const from a pointer or reference.
- If the pointer points to a const variable, `const_cast` cannot remove that const.

```C++
// This doesn't work because the underlying type is const.
#include <iostream>

const double PI = 3.141;

int main() {
	*const_cast<double *>(&PI) = 3.1415;
	std::cout << PI << "\n";
}
```

## Static casting
Tries to cast withing the bounds of the language.
- Ex: Casting to another class uses the constructor of that class.
- Ex: Casting an int to a double does the normal thing in C++.

Used to convert between compatible types at compile time.
- The compiler checks at compile if the conversion is possible.

- It isn't always done at compile time.

- What do you mean a type safe way to convert?
- Does static cast fail for variables that aren't known until run time?

- Do conversion within the semantics of the language.
- Done at compile time.
- Changes the underlying data. Ex: converting from a float to an int

## Dynamic casting
Casting with inheritance.
Done at run time.

## Reinterpret cast
`reinterpret_cast` just changes the type the compiler thinks the variable is, but doesn't change the underlying bits. This only works to convert between pointers.

```C++
#include <iostream>

int main() {
	float f = 0.5;
	std::cout << *reinterpret_cast<int*>(&f) << "\n";
}
```

## C style casts
Has the best syntax

1. const_cast
2. static_cast, but doesn't respect access specifiers
3. static_cast*, then const_cast
4. reinterpret_cast
5. reinterpret_cast, then const_cast


### [Casting](#c)
- Casting is done at compiler time so it's up to the programmer to make sure they are casting correctly
- `static_cast<data type>(variable)`
- When a float gets cast to an int the decimal is truncated. `1.9 -> 1`
