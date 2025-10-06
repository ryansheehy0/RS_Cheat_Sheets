[Home](../README.md#c)

# Compile time C++
- type_traits
- decltype
- sizeof
- alignof
- SFINAE/enable_if
- using/typedef
- enum/enum class

| Keywords  | Description                                                                           |
|-----------|---------------------------------------------------------------------------------------|
| constexpr | If available execute at compile time.                                                 |
| consteval | Function has to be executed at compile time.                                          |
| inline    | Function executes at run time, but suggests to the compile to not do a function call. |
| constinit | Variable init at compile time, but not const during run time. |

<!-- TOC -->

- [Templates](#templates)
- [constexpr](#constexpr)
	- [if constexpr](#if-constexpr)
	- [static_assert](#static_assert)

<!-- /TOC -->

## [Templates](#compile-time-c)
Templates are used to allow the same piece of code to use different data types.

```C++
template <typename T>
void print(T value) {
	cout << value << "\n";
}

print(5) // Defined implicitly based upon the type of the argument
print<char>('a') // Defined explicitly
```

- Using `class` is the same as using `typename`
- `= void` makes a template parameter optional.
- When creating a template class, each of the defined member methods needs to also be templates.

```C++
template<typename T>
void Class<T>::method() {}
```
- Non-type template parameters: `template<size_t N>`
- Template specialization: Specific code depending on the type.

```C++
template<int N>
struct Print {
	void print() { cout << N << "\n"; }
}

template<>
struct Print<5> {
	void print() { cout << "five\n"; }
}
```

## [constexpr](#compile-time-c)
- Compile time variable: `constexpr int X = 10;`
- Compile time function if arguments are also defined at compile time.
	- `constexpr int square(int x) { return x * x; }`
	- `constexpr auto square = [](int x){ return x * x; }`
- Compile time objects

```C++
struct Pint {
	int x, y;
	constexpr Point(int x, int y) : x(x), y(y) {}
}

constexpr Point p(1, 1);
```

- When would you need constexpr destructors?

### [if constexpr](#compile-time-c)
Used for conditional checks at compile time. The condition needs to be defined at compile time.

```C++
template<typename T>
void print(T x) {
	if constexpr(std::is_integral_v<T>) cout << "int: " << x;
	else cout << "other: " << x;
}
```

- Common STDs for compile time conditionals.

| type_traits               | Description                                                        |
|---------------------------|--------------------------------------------------------------------|
| `is_integral_v<T>`        | Is T an integer type.                                              |
| `is_floating_point_v<T>`  | Is T a floating type.                                              |
| `is_arithmetic_v<T>`      | Is T integral or floating type.                                    |
| `is_enum_v<T>`            | Is T an enum.                                                      |
| `is_pointer_v<T>`         | Is T a pointer.                                                    |
| `is_reference_v<T>`       | Is T a reference.                                                  |
| `is_array_v<T>`           | Is T an array.                                                     |
| `is_same_v<T, U>`         | Is T and U are the same type.                                      |
| `is_const_v<T>`           | Is T a const.                                                      |
| `is_volatile_v<T>`        | Is T volatile.                                                     |
| `is_trivial_v<T>`         | Does T have no constructors, destructors, or copy/move operations. |
| `is_standard_layout_v<T>` | Does T have a standard memory layout so memcopy would work.        |

| utility | Description |
|-|-|
| | |

| concepts | Description |
|-|-|
| | |

### [static_assert](#compile-time-c)
`static_assert` checks a condition at compile time and triggers a compilation error if it’s false.

```C++
template <size_t N>
struct Array {
	static_assert(N >= 0, "Array size must be positive or zero.");
	int data[N];
}
```