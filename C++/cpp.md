[Home](../README.md#c)

# C++
My personal C++ notes.

<!-- TOC -->

- [To Do](#to-do)
- [main](#main)
- [Data Types](#data-types)
	- [Int based data types](#int-based-data-types)
	- [Float based data types](#float-based-data-types)
	- [Data type notes](#data-type-notes)
		- [Truthy and Falsy](#truthy-and-falsy)
		- [Multiple variables on one line](#multiple-variables-on-one-line)
		- [Variable names/Identifiers](#variable-namesidentifiers)
		- [Assigning values](#assigning-values)
		- [Int vs Float Division](#int-vs-float-division)
		- [Dividing by zero](#dividing-by-zero)
		- [Int vs Float Modulus](#int-vs-float-modulus)
		- [post-fix vs pre-fix increment](#post-fix-vs-pre-fix-increment)
	- [Const](#const)
	- [Auto](#auto)
- [Headers](#headers)
- [Namespaces](#namespaces)
- [Character escapes](#character-escapes)
- [Pointers and references](#pointers-and-references)
	- [Function pointers](#function-pointers)
	- [Arrays](#arrays)
		- [Two dimensional arrays](#two-dimensional-arrays)
- [Order of operations](#order-of-operations)
- [Loops and Conditions](#loops-and-conditions)
	- [Switch](#switch)
	- [Do While loops](#do-while-loops)
	- [Single line conditions](#single-line-conditions)
	- [Range based for loop](#range-based-for-loop)
- [Functions](#functions)
	- [Types of functions](#types-of-functions)
	- [Pass by value or reference](#pass-by-value-or-reference)
	- [Optional arguments](#optional-arguments)
	- [Function overloading](#function-overloading)
	- [Lambda functions](#lambda-functions)
- [Global and static variables](#global-and-static-variables)
- [Exception/Error handling](#exceptionerror-handling)
- [Templates](#templates)
- [new and delete](#new-and-delete)
- [Enums](#enums)
- [Structs](#structs)
- [Classes](#classes)
	- [Database classes](#database-classes)
	- [Constructors](#constructors)
		- [The most vexing parse](#the-most-vexing-parse)
	- [Using heap memory in classes](#using-heap-memory-in-classes)
	- [Operator overloading](#operator-overloading)
		- [Comparison operator overloading](#comparison-operator-overloading)
		- [Overloading <<](#overloading-)
	- [Inheritance](#inheritance)
		- [Virtual and Override](#virtual-and-override)
			- [Abstract classes](#abstract-classes)
		- [Composition vs Inheritance](#composition-vs-inheritance)
		- [Friend](#friend)
		- [Changing access of parent members](#changing-access-of-parent-members)
	- [Inline functions](#inline-functions)

<!-- /TOC -->

## To Do
- cassert for testing
- openssl
- casting
- How the linker works
	- dynamic vs static linking
- Variadic functions
- thrown error types
- typedef
- friend and operator keywords?
- Singletons
- Regex in C++
- typeid
- Multi-threading
- Modules?
	- `import` how does this effect header files

## [main](#c)
The main function is the entry point of a program.
- function signature
	- `int main()` - Doesn't take in command line arguments.
	- `int main(int argc, char *argv[])` - Allows command line arguments.
		- `argc` is the number of arguments
		- `argv` is an array of strings for the arguments. This includes the program name.
- Return type
	- `return 0;` - return without any errors
	- `return 1;` - return with an error

## [Data Types](#c)
The smallest memory unit is 1 byte(8 bits).

### [Int based data types](#c)

| Name      | Bytes  | Notes                                        |
|-----------|--------|----------------------------------------------|
| bool      | 1      | Can use `true` or `false` keywords           |
| char      | 1      | Uses `''`s                                   |
| wchar_t   | 2 or 4 | Larger char encoding standards like unicode. |
| short     | 2      | Same as `short int`                          |
| int       | 2 or 4 | Bytes depends on the platform                |
| long long | 8      | Same as `long long int`                      |

- When you want the size to be clearly defined
	- int8_t, int16_t, int32_t, int64_t
	- uint8_t, uint16_t, uint32_t, uint64_t
- `""`s return a `const char*` array that has a null terminating character.

### [Float based data types](#c)

| Name        | Bytes |
|-------------|-------|
| float       | 4     |
| double      | 8     |
| long double | 12    |

### [Data type notes](#c)

#### [Truthy and Falsy](#c)
- Anything positive or negative is truthy and `0` is falsy.
- `(x = #)` returns `x` not `#`
	- Ex: `x = 10` returns `10`
	- Ex: `x = 0` returns `0`
	- Ex: `int32_t x = 2'147'483'648` returns `-2147483648`

#### [Multiple variables on one line](#c)
- Declaring multiple variables on one line
	- `int x, y;`
- Setting multiple variables on one line
	- `int x = 10, y = 20;`
- Assigning multiple variables on one line
	- `x = y = 20;`
	- `x` and `y` will both be equal to `20`
- Command equals multiple variables
	- `x += x + 3;` is the same as `x = x + x + 3;`

#### [Variable names/Identifiers](#c)
- Variable names can only use letters, underscores, and digits, and cannot start with digits.
	- Ex: `_this_is_a_valid_variable_name`
- Variable names are case sensitive

#### [Assigning values](#c)
- You can use `'` to separate very long numbers.
	- Ex: `1'999'999`
- You can assign floats using scientific notation.
	- `6.08e2` = `6.08 x 10^2` = `608`
	- `6.08e-2` = `0.0608`
- It is recommended to start floats with `0` instead of a `.`

#### [Int vs Float Division](#c)
- Integer division is truncated
- In order to get float division, either the numerator or denominator has to be a float/double.
	- `1/2` will return `0`
	- `1.0/2` will return `0.5`
	- `1/2.0` will return `0.5`
	- `1.0/2.0` will return `0.5`

#### [Dividing by zero](#c)
- Dividing by zero in integer division gives a runtime error
- Float division
	- `0.0/0.0` outputs not a number(nan)
	- `1.0/0.0` outputs inf
	- `-1.0/0.0` outputs -inf

#### [Int vs Float Modulus](#c)
- Compiler error if you use modulus with floats/doubles.
- Modulus can only work with int data types

#### [post-fix vs pre-fix increment](#c)
- `x++` returns `x` then increments it by 1
- `++x` increments `x` then returns `x`

### [Const](#c)
- By convention use SCREAMING_CASE
- By convention declare before any other variables
- Use `const` over `#define`
	- Modern compilers do the same thing as `#define`
	- `const` has type checking and syntax checking
	- `const` is known to debuggers
	- `const` can be scoped to the block
- A function returning a `const` means that the returned value cannot be modified, but this only really applies to references or pointers.

### [Auto](#c)
`auto` tells the compiler to determine the variable's type by the initial value given.
- Ex: `auto x = "apple";` gets assigned const char*
- Ex: `auto x = 0.01;` gets assigned double
- Ex: `auto x` gives an error

## [Headers](#c)
The purpose of header files is to allow you to separate the declaration(.h) and the definitions(.cpp). The declarations(.h) can be shared across multiple files. This has a couple of benefits:
- It separates the interface(.h) and the implementation(.cpp), so that when using the code you just have to worry about what you can use.
- If you only change the implementation(.cpp) and not the interface(.h), then the compiler only has to re-compile that implementation(.cpp) and not other implementations(.cpp).
- If you only change the .cpp file and not the .h file, then the compiler only has to re-compile the .cpp file and not the other .cpp files. Because the interface(.h) didn't change, only the implementation(.cpp).

```C++
// .h
#pragma once

class Class {
	private:
		int _x = 0;
	public:
		void print();
};
```

```C++
// .cpp
#include "Class.h"
#include <iostream>

Class::print() {
	std::cout << _x << "\n";
}
```

- Prevent multiple header file inclusions to prevent multiple declarations.
	- `#pragma once` - This is newer and is recommended
	- Or you can use header guards
	```C++
	#ifndef __CLASS_NAME_H__
	#define __CLASS_NAME_H__
	// Header file
	#endif
	```

- Do not write `using namespace std;` in the header as that may cause naming conflicts.
	- Instead write `using std::string;`, etc.

## [Namespaces](#c)
Namespaces define a region/scope used to prevent naming conflicts

```C++
namespace namespaceName {
	int x;
}

namespaceName::x = 10;
```

- You can have namespaces automatically used with `using namespace namespaceName`.
	- This isn't recommended because it can result in naming conflicts.
- You can use `{}` to define a new scope.

## [Character escapes](#c)

| Character | Description                       |
|-----------|-----------------------------------|
| `\'`      |                                   |
| `\"`      |                                   |
| `\\`      | backslash                         |
| `\a`      | audible bell                      |
| `\b`      | backspace                         |
| `\f`      | form feed - new page              |
| `\n`      | new line                          |
| `\r`      | carriage return                   |
| `\t`      | horizontal tab                    |
| `\v`      | vertical tab                      |
| `\o##`    | octal output                      |
| `\x##`    | hexadecimal output                |
| `\u####`  | prints unicode. Only works on g++ |
| `\Nname`  | unicode character from name       |
| `\0`      | Null                              |

## [Pointers and references](#c)

| Code                    | Description                                                         |
|-------------------------|---------------------------------------------------------------------|
| `int* ptr;`             | Creates a pointer pointing to an int. Enough memory for an address. |
| `*ptr`                  | Dereferences the ptr                                                |
| `int& x = y;`           | `x` is a reference to `y`. `x` and `y` always have the same value.  |
| `&ptr`                  | Gets address of ptr.                                                |
| `ptr`                   | Gets the value in ptr. The address it points to.                    |
| `ptr->`                 | Is the same as `(*ptr).`                                            |
| `const int* xPtr = &x;` | Pointer to a const int. Can't change the dereference.               |
| `int* const xPtr = &x;` | Pointer to an int, but the pointer cannot change.                   |
%MCEPASTEBIN%
- `++` has higher precedence than dereferencing a pointer.
	- Ex: `(*ptr)++` instead of `*ptr++`

### [Function pointers](#c)

```C++
void (*func)(int, int);
```

You can also use `#include <functional>` and `function<void(int, int)> func;`

### [Arrays](#c)
Arrays in C++ store a sequences of variables in contiguous memory. The array is a pointer to the first element of the array. Accessing an element with `arr[index]` is equivalent to dereferencing the pointer at the memory location `*(arrPtr + index)`.
- Define with random data
	- Ex: `int arr[3];`
- Initialize with zeros
	- Ex: `int arr[3] = {1};` initializes with 1, 0, 0
	- Ex 2: `int arr[3] = {};` initializes with 0, 0, 0
- You don't have to specify the size
	- Ex: `int arr[] = {0, 0, 0};` the size is 3

#### [Two dimensional arrays](#c)
Since arrays are stored in continuous memory, a two dimensional array(or more dimensions) can also be represented with a one dimensional array.
- `int twoDArr[row][col]` or `int oneDArr[row * col]` - Creates a 2d array.
- `arr[row][col]` or `arr[(cols * row) + col]` - Access an element in the 2d array.

Each of these array may contain the same memory, but their data types are different.
- `int twoDArr[row][col]` type is `int *[col]`
- `int oneDArr[row * col]` type is `int *`

## [Order of operations](#c)
Operations with the same precedence are executed according to their associativity, left to right or right to left.

| Precedence | Operation                    | Associativity |
|------------|------------------------------|---------------|
| 1          | :: - scope                   | Left to right |
| 2          | x++, x--                     | Left to right |
|            | type() - functional case     |               |
|            | func(), arr[]                |               |
|            | ., ->                        |               |
| 3          | ++x, --x                     | Right to left |
|            | +x, -x, !, ~                 |               |
|            | (type) - C-style case        |               |
|            | *ptr, &var, sizeof           |               |
|            | new, new[], delete, delete[] |               |
| 4          | .*, ->*                      | Left to right |
| 5          | x*y, x/y, x%y                | Left to right |
| 6          | x+y, x-y                     | Left to right |
| 7          | <<, >>                       | Left to right |
| 8          | <, <=, >, >=                 | Left to right |
| 9          | ==, !=                       | Left to right |
| 10         | &                            | Left to right |
| 11         | ^                            | Left to right |
| 12         | \|                           | Left to right |
| 13         | &&                           | Left to right |
| 14         | \|\|                         | Left to right |
| 15         | x?y:z, throw, =              | Right to left |
|            | +=, -=, *=, /=, %=, <<=, >>= |               |
|            | &=, ^=, \|=                  |               |
| 16         | ,                            | Left to right |

## [Loops and Conditions](#c)

### [Switch](#c)
- Cannot be used with strings or floats.

```c++
switch (x) {
	case 0:
		break;
	case 1:
	case 2:
		// 1 or 2
		break;
	default:
		break;
}
```

### [Do While loops](#c)

```c++
do {
} while (true);
```

### [Single line conditions](#c)

```c++
if (true) cout << "true" << endl;

if (true)
	cout << "true" << endl;
else
	cout << "false" << endl;

for (int i = 0; i < 10; i++)
	cout << i << endl;

while (true)
  cout << "infinity ";
```

### [Range based for loop](#c)
- The list has to have an iterator in order to work.

```c++
std::vector<int> arr = {1, 2, 3, 4};

for (int num : arr) {
}
// This is the same as
for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
	int num = *it;
}
```

- If const is used as the data type then `::const_iterator` is used instead.

## [Functions](#c)
- Functions cannot be declared within other functions.

| Term           | Example              |
|----------------|----------------------|
| prototype      | `void func(int);`    |
| header         | `void func(int arg)` |
| implementation | `{ /* body */ }`       |

- The purpose of putting a function's prototype at the top is to allow the function to be used before it is implemented.

### [Types of functions](#c)

|                          |                                                                             |
|--------------------------|-----------------------------------------------------------------------------|
| `constexpr void func();` | A function can be evaluated at compile time if possible.                    |
| `inline void func();`    | Compiler searches and replaces. Speed up performance, but uses more memory. |

### [Pass by value or reference](#c)
- If you don't want to change the argument
	- If the argument is less than 64bits/8bytes
		- Pass by value `void func(int x)`
	- Else
		- Pass by const reference - `void func(const Class& x)`
- If you do want to change the argument
	- Pass by pointer - `void func(Class* x)`

Following these rules makes it clear that an object is being modified by a function because you have to specify the address when passing it as an argument.
- For an array you want to change use `int (*arr)[]`
- For an array you don't want to change use `const int arr[]`

### [Optional arguments](#c)
- Any argument after an optional argument must also be an optional argument.

```c++
int test(int a, int b = 4, int c = 10){}

test(1, 2, 3);
test(1, 2);
test(1);
```

- If you have a function prototype, you can only put the default values in the prototype and not the function header.

### [Function overloading](#c)
- Function overloading are multiple functions with the same name, but different argument types.
	- The compiler determines which function to call based on the argument types.
- Functions that return different types don't overload.

### [Lambda functions](#c)
Lambda functions allow you to easily pass small functions into another function. They take the form of `[capture list](arguments){function body}`. You can also specify a return type with `[]() -> type {}`
- The capture list specifies what variables are accessible from the outside scope.
	- You can use `[&]` to have access to all the variables in the outside scope as pass by reference.
	- You can use `[=]` to have access to all the variables in the outside scope as pass by value.

## [Global and static variables](#c)
- Static variable have their memory persist across function calls. They are scoped to the function they are defined in.
- Global variables are defined outside any function and can be used by any function.
	- They are automatically set to 0 if not given a value.
	- Usually global variables are constants in order to prevent these side effects.

## [Exception/Error handling](#c)
- If you want to exit your program from anywhere you can do `exit(1);`
- The purpose of throwing errors
	- When the return type doesn't support errors.
		- Ex: For the func `int add(int x, int y)` you can't return -1 as an error because it could be a legitimate value.
	- When you need to bubble up errors through many functions.
		- You don't have to check for an error and return it. You can just call the function.

```C++
void func1() {
	throw "String error";
}

void func2() {
	func1();
}

void func3() {
	try {
		func2();
	} catch (const char* error) {
		// handle error
	}
}
```

- `catch (...)` allows you to catch all errors regardless of their type
- `throw;` allows you to throw the previously thrown error
- There is a hierarchy of C++ errors.
	- std::exception
		- std::bad_alloc - When memory allocation fails
		- std::bad_cast - When failing to dynamically cast using `dynamic_cast`
		- etc.
		- std::logic_error
			- std::domain_error - When a function receives an arg outside its domain.(Like `sqrt` receiving a negative num.)
			- std::invalid_argument - When the arguments to a function are invalid
			- std::length_error - When an operation exceeds the allocated size
			- std::out_of_range - When trying to access an element outside the valid range.
		- std::runtime_error
			- std::range_error - When a computation results in a value outside the valid range. Function expects to return in a certain range, but the computation is outside of that range.
			- std::overflow_error - When an arithmetic operation results in an overflow.
			- std::underflow_error - When an arithmetic operation results in an underflow.
			- std::ios_base::failure - When the input/output operations fail. Common if a file can't read or write.

## [Templates](#c)
Templates are used to allow the same piece of code to use different data types.

```C++
template <typename T>
void print(T value) {
	std::cout << value << "\n";
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

## [new and delete](#c)
Heap memory is used when teh size is only known at run time.
- `new` allocates memory on the heap and returns its address.
- `delete` frees the allocated memory.
	- Deleting a nullptr does nothing.

```C++
int* ptr = new int;
delete ptr;
// With arrays
int* arr = new int[10];
delete[] arr;
```

## [Enums](#c)
Enums define a variable's allowed values by restricting it to a predefined set of named constants, improving code clarity and reducing invalid inputs.
- Enums automatically count up from 0, but they can be changed by assigning them.
	- Ex: `enum Num {ONE = 1, TWO, THREE}`

```C++
enum Shape {CIRCLE, SQUARE, TRIANGLE};
enum class Color {RED, GREEN, BLUE};

Shape s = CIRCLE;
Color c = Color::RED;
```

- The values in regular enums are treated as ints, by default, but the values in enum classes are treated as their own types.
	- Ex: `CIRCLE == 0` is true while `Color::RED == 0` is false.
- You can change the default enum type by doing `enum Color : char {RED, GREEN, BLUE};`

## [Structs](#c)
The only difference between structs and classes is that by default structs' members are public. However, the convention is to only use Structs to group variables together.
- Use the member access operator `.` to get each element in the struct.

```C++
struct Point {
	int x;
	int y = 10; // Default value
};

Point pt = {10, 20};
	// Or
Point pt;
pt.x = 10;
pt.y = 20;
	// Or
Point pt = {.x=10, .y=20};
```

## [Classes](#c)
Classes are used to combine data and functions that handel that data.

```C++
// Declarations
	// These are usually in .h files
class Point {
	private:
		double _x = 0, _y = 0;
	public:
		double x() const {return _x;}
		double y() const {return _y;}
		double distance(const Point& pt) const;
};
// Definitions
	// These are usually in .cpp files
double Point::distance(const Point& pt) const {
	double a = _x - pt.x();
	double b = _y - pt.y();
	return std::sqrt(a * a + b * b);
}
```

- `const` after the methods means that the method doesn't change any of the internal members for the class.
	- This allows the method to be called on a const objects.
- Classes can have `static` members which belong to the class itself rather than any specific object. They can be accessed by using `Class::staticMember`
	- `static` variables are shared across all instances of the class.
	- `static` methods can only access `static` variables.
- The `this` keyword is a pointer to the object itself.
	- `this` is often used to differentiate between local and member variables. Ex: `this->memberVar`
	- It is a common pattern for a method to have a return type of `Point&` and then `return *this;`. This allows methods to be chained together.
		- Ex: `pt.method1().method2();`

### [Database classes](#c)
A common pattern is to have one class represent what you want to store and another class hold the database(like vector or linked list) of the units.
- This stores a list of pointers to heap memory of the data you want to store.
- These classes typically have 3 methods used to get, update, remove, and add.

```C++
class Points {
	private:
		std::vector<Point*> _points;
	public:
		~Points();
		Point*& at(int index) const; // Used to get and update
		void remove(int index);
		void add(int index, Point* pt);
};
```

### [Constructors](#c)
Constructors are used to initialize the member variables of an object. Constructors have the same name as the class itself, but do not have a return type.

```C++
Point::Point(int x, int y) {
	_x = x;
	_y = y;
}
```

If member variables have default values, they are initialized with those defaults before the constructor runs. The constructor then overrides them, which is often unnecessary. Additionally, if the default value involves dynamic memory allocation, it can lead to a memory leak. Using an initializer list allows the constructor to directly initialize the values, bypassing the default initialization and avoiding potential inefficiencies or leaks.
- This is also often used to call the parent class's constructor(inheritance), ensuring that the base class has its parent class's member variables set properly.

```C++
Point::Point(int x, int y) : _x(x), _y(y) {}
// Formatting if there are a lot of member variables
Point::Point(int x, int y)
	: _x(x),
	  _y(y)
{}
```

The default constructor is automatically generated by the compiler if no other constructors are defined. It allows you to create an object without providing any arguments, such as `Point pt;`
- If you define any constructor, the compiler does not generate a default constructor automatically. To explicitly declare a default constructor in such cases, you can use `Class() = default;`, which reinstates the default constructor.
- It is better to have default values for constructor arguments, then to assign the member variables directly.

#### [The most vexing parse](#c)
There are only a few ways to create object.

```C++
// Uses teh default constructor
Point pt;
Point pt = Point();
Point pt{};
// The most vexing parse
Point pt();
	// This defines a function called pt which returns a Point. This doesn't create an object.
```

### [Using heap memory in classes](#c)
When using heap memory(`new`) in a class, it is recommended to follow the "Rule of Three":
1. Destructor - The destructor deletes any heap memory that was allocated by the object.
- The destructor can never have any arguments.
- If the object is created on the stack(not using `new`), then the destructor is called when the object goes out of scope. If the object is created on the heap(using `new`), then the destructor is only called when the object is deleted with `delete`.

```C++
Class::~Class() {
	// Deletes all the heap memory in the class
	for (int* element : _arr) {
		delete element;
	}
}
```

2. Overloading the assignment operator
If an object has member variables that are pointers, assigning one object to another copies the pointers themselves, not the underlying data they point to. If those pointers refer to heap-allocated memory, this can lead to a memory leak. Overloading the assignment operator allows you to handle this situation by:
- Deleting the existing heap memory to prevent a memory leak.
- Allocating new heap memory and copying the data from the right hand side(rhs).

```C++
Class& Class::operator=(const Class& rhs) {
	if (this == &rhs) return *this; // Avoid self assignment
	// Assign any non pointer member variables
	_var = rhs.var();
	// Delete your old heap
	delete _heap;
	// Create new heap
	_heap = new int;
	// Assign value from rhs to new heap
	*_heap = rhs.value();
	return *this;
}
```

3. Copy constructor
The copy constructor is similar to overloading the assignment operator, but there is no need to check for self-assignment or delete any old heap memory, as the object is being created for the first time.

```C++
Class::Class(const Class& rhs) {
	// Assign any non pointer member variables
	_var = rhs.var();
	// Create new heap
	_heap = new int;
	// Assign value from rhs to new heap
	*_heap = rhs.value();
}
```

### [Operator overloading](#c)
Left hand side(lhs) means that it can be assigned to, like a variable. The right hand side(rhs) means that i cannot be assigned to, like a literal.
- Operator overloading allows you to change the operators for an object. The argument is the right hand side, with the left hand side being the object itself.

```C++
// This is what most operator overloading looks like
Point Point::operator+(const Point& rhs) const {
	Point result;
	result.x() = _x + rhs.x();
	result.y() = _y + rhs.y();
	return result;
}
```

#### [Comparison operator overloading](#c)
These compare the left and right hand side and return a bool.

```C++
bool Point::operator==(const Point& rhs) const {
	return _x == rhs.x() && _y == rhs.y();
}

bool Point::operator<(const Point& rhs) const {
    if (_x == rhs.x()) {
        return _y < rhs.y();
    }
    return _x < rhs.x();
}
```

You can define all the other comparisons from just these two(`==` and `<`).
- `bool operator!=(const Point& rhs) { return !(*this == rhs); }`
- `bool operator>(const Point& rhs)  { return rhs < *this; }`
- `bool operator<=(const Point& rhs) { return !(*this > rhs); }`
- `bool operator>=(const Point& rhs) { return !(*this < rhs); }`

#### [Overloading <<](#c)

```C++
#include <iostream>
using std::ostream, std::cout;

class Date {
	private:
		int month, day, year;
	public:
		Date(int m, int d, int y) : month(m), day(d), year(y) {}

		friend ostream& operator<<(ostream& os, const Date& dt);
};

ostream& operator<<(ostream& os, const Date& dt) {
	os << dt.month << '/' << dt.day << '/' << dt.year;
	return os;
}

int main() {
	Date date(5, 22, 2002);
	cout << date;
}
```

### [Inheritance](#c)
Inheritance allows one class to acquire the members of another class. This decreases the amount of code needed because different classes can share the same code.
- Child/derived/sub classes inherit their parent/base/super class.

```C++
class Shape {
	protected:
		Point _center = Point(0, 0);
		double _length = 1;
	public:
		Point& center() const {return _center;}
};

class Circle : public Shape {
	public:
		double diameter() const {return _length * 2;}
};
```

- `protected:` allows the child class to access it, but it's private to any instance of the class.
	- In order to access protected members from the child class you need to do `this->var`
- When inheriting you can use `: public Parent`, `: private Parent`, or `protected Parent`
	- public - public members of the parent class are public, and protected members of the parent class are protected.
	- protected - public members of the parent class are protected, and protected members of the parent class are protected.
	- private - all members of the parent class are private
	- This allows a child class to control the access level of its inherited parent class's members, which is especially important if the child class is further inherited by another class.

#### [Virtual and Override](#c)
Runtime polymorphism allows an object of a child class to be treated as an object of its parent class.
- When you call a method on a parent class instance, it could either execute the parent class's implementation or the child class's overridden implementation.
	- If the `virtual` keyword is used on the parent's method and the child class overrides that method, then when the parent's instance calls that method, then the child's implementation is used.
		- It isn't required, but highly recommend that the child method uses the `override` keyword when doing this. Ex: `void method() override;`
	- If the `virtual` keyword isn't used the child class can still override, but when the parent's instance calls that method, then the parent's implementation is used.
		- Don't use the `override` keyword in this case.

```C++
class Shape {
	public:
		virtual void draw() const { std::cout << "Shape\n"; }
		void draw2() const { std::cout << "Shape\n"; }
};

class Circle : public Shape {
	public:
		void draw() const override { std::cout << "Circle\n"; }
		void draw2() const { std::cout << "Circle\n"; }
};

class Rectangle : public Shape {
	public:
		void draw() const override { std::cout << "Rectangle\n"; }
		void draw2() const { std::cout << "Rectangle\n"; }
};

int main() {
	Shape shape;
	Circle circle;
	Rectangle rectangle;

	std::vector<Shape*> shapes;
	shapes.push_back(&shape);
	shapes.push_back(&circle);
	shapes.push_back(&rectangle);

	for (Shape* shape : shapes) {
		shape->draw();
	}
	/* virtual
	Shape
	Circle
	Rectangle
	*/

	for (Shape* shape : shapes) {
		shape->draw2();
	}
	/* non-virtual
	Shape
	Shape
	Shape
	*/
}
```

##### [Abstract classes](#c)
An abstract class is a class that contains at least one pure virtual method, which must be overridden by any concrete child class.
- Ex: `virtual void print() const = 0;`
- You cannot create an instance of an abstract class.
- A class that only has pure virtual methods is called an interface.
- A concrete class is a class that is not abstract and can be instantiated.
- If an abstract class inherits from another abstract class, it does not need to override the pure virtual method, provided a concrete class in the inheritance chain eventually overrides it.

#### [Composition vs Inheritance](#c)
Composition is used when you have a "has a" relationship between classes. Inheritance is used when you have a "is a" relationship.
- Composition is having an instance of one class as a member of another class.
	- Ex: A car has a engine so you should use composition.
	- Ex: A truck is a car so you should use inheritance.

#### [Friend](#c)
A friend function is allowed to access the private and protected members of its arguments, as long as the arguments are objects of the class that declared the friend function.

```C++
class Queue {
	// Other queue members
	friend void concatenate(Queue& q1, Queue& q2);
}

void concatenate(Queue& q1, Queue& q2) { // Has to be defined outside the class.
	// Prevents the need for popping q2 and pushing onto q1.
	if (!q2.head) return;
	if (!q1.tail) {
		q1.head = q2.head;
		q1.tail = q2.tail;
	} else {
		q1.tail->next = q2.head;
		q1.tail = q2.tail;
	}
	q2.head = nullptr;
	q2.tail = nullptr;
}
```

#### [Changing access of parent members](#c)
Making parent class members public. This can also be done with private and protected.

```C++
template <typename T>
class Stack : private SinglyLinkedList<T> {
	public:
		using SinglyLinkedList::popFront;
		using SinglyLinkedLIst::pushFront;
}
```

### [Inline functions](#c)
Methods that are defined inside a class declaration are automatically `inline`.

Ex: These functions are the same

```C++
Class {
	public:
		void func() {return 1;}
		inline void func2() {return 1;}
}
```