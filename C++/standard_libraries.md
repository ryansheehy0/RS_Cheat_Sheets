[Home](../README.md#c)

# C++ Standard Libraries
`using std namespace;` is assumed for these libraries.

<!-- TOC -->

- [iostream](#iostream)
- [String Stream](#string-stream)
- [cmath](#cmath)
- [ctime](#ctime)
- [cstdlib](#cstdlib)
- [iomanip](#iomanip)
- [typeinfo](#typeinfo)
- [fstream](#fstream)
- [optional](#optional)
- [cctype](#cctype)
- [pair](#pair)
- [tuple](#tuple)
- [algorithm](#algorithm)

<!-- /TOC -->

## [iostream](#c-standard-libraries)
Used for reading user input data from the terminal and outputting to the terminal.

- `#include <iostream>`

| Functions                                | Description                                                                         |
|------------------------------------------|-------------------------------------------------------------------------------------|
| `istream& cin`                           | Input stream                                                                        |
| `ostream& cout`                          | Output stream. Buffered by default.                                                 |
| `ostream& cerr`                          | Unbuffered(write to console immediately) error stream                               |
| `ostream& clog`                          | Buffered error stream                                                               |
| `ostream& operator<<(ostream&, constT&)` | Outputs value to stream.                                                            |
| `istream& operator>>(istream&, T&)`      | Inputs value split by whitespace, returns false if invalid, newline stays in buffer |
| `endl`                                   | `\n` and flushes the stream                                                         |
| `int istream.get()`                      | Gets the next char from the buffer or -1 for EOF                                    |
| `ostream& ostream.put(char)`             | Writes one character                                                                |
| `istream& istream.ignore()`              | Ignores the next character                                                          |
| `int istream.peek()`                     | Returns the next character without indexing.                                        |
| `bool eof()`                             | Checks end of file                                                                  |
| `bool fail()`                            | Stream operation fail not from EOF like imputing the wrong type of character        |
| `void istream.clear()`                   | Clears flags including EOF flag                                                     |
| `ostream& ostream.flush()`               | Forces any buffered output to be writhen to the console.                            |
| `istream& istream.seekg(offset, pos)`    | Moves input pointer to new pos. `ios::beg, cur, end` are common pos                 |

- Floats output `99` not `99.0`
- Can do multiple in one line: `cin >> var1 >> var2`
- Discards white spaces: `cin >> ws`

## [String Stream](#c-standard-libraries)
Used to treat a string as a stream.

- `#include <sstream>`

| Functions                 | Description                                                        |
|---------------------------|--------------------------------------------------------------------|
| `ostringstream`           | Output string stream. Used for `<<`s                               |
| `istringstream`           | Input string stream. Used for `>>`s.                               |
| `stringstream`            | Input and Output string stream                                     |
| `stringstream ss(string)` | Creates a string stream                                            |
| `ss << "string";`         | Concatenates to the string stream, but not the constructor string. |
| `ss >> str;`              | Puts the next word into str. Words are separated by spaces.        |

## [cmath](#c-standard-libraries)
Floating point math operations.

- `#include <cmath>`

| Functions                       | Description                   |
|---------------------------------|-------------------------------|
| `pow(base, exponent)`           |                               |
| `sqrt(x)`                       |                               |
| `fabs(x)`                       | absolute value                |
| `ceil(x)`                       | Round up                      |
| `floor(x)`                      | Round down                    |
| `sin(x)`, `cos(x)`, `tan(x)`    |                               |
| `asin(x)`, `acos(x)`, `atan(x)` | Inverse trig function.        |
| `log(x)`, `log10(x)`            | Natural and base 10 log       |
| `exp(x)`                        | e to the power of x           |
| `fmod(x, y)`                    | x % y with the same sign as x |
| `hypot(x, y)`                   | $\sqrt(x^2 + y^2)$            |

## [ctime](#c-standard-libraries)
Time function.

- `#include <ctime>`

| Function                  | Description                          |
|---------------------------|--------------------------------------|
| `time_t time(t)`          | Current time in seconds since epoch  |
| `double difftime(t1, t2)` | Difference in seconds                |
| `char* ctime(&t)`         | Converts time_t to readable string   |
| `tm* localtime(&t)`       | Converts time_t to local time struct |
| `tm* gmtime(&t)`          | Converts time_t to UTC time struct   |
| `time_t mktime(&tm)`      | Converts tm struct to time_t         |

## [cstdlib](#c-standard-libraries)
Integer math operations.

- `#include <cstdlib>`

| Functions           | Description                                        |
|---------------------|----------------------------------------------------|
| `int abs(x)`        |                                                    |
| `void srand(seed)`  | Seeds random number generator                      |
| `int rand()`        | Random int from `0` to `RAND_MAX`                  |
| `void exit(status)` | Terminates the program with status code. 1 - error |

## [iomanip](#c-standard-libraries)
Stream input and output formatting.

- `#include <iomanip>`

| Function          | Description                                                     |
|-------------------|-----------------------------------------------------------------|
| `setw(n)`         | Sets width of next input/output. ANy values larger are ignored. |
| `setprecision(n)` | Number of digits for floats.                                    |
| `fixed`           | `setprecision` counts after decimal point                       |
| `setfill(char)`   | Sets extra characters for overflow with `setw(n)`               |
| `right`          | Justify right                                                   |
| `left`           | Justify left                                                    |

- Examples:
	- `cout << setprecision(2) << 9.99999;` Outputs: `10`
	- `cout << fixed << setprecision(2) << 9.99999;` Outputs: `10.00`
	- `cout << setprecision(2) << 146.789;` Outputs: `1.5e+02`

## [typeinfo](#c-standard-libraries)
Gets type of variable.

- `#include <typeinfo>`
- `typeid(var).name()` gives a string of the type of variable.

| Returned | Type     |
|----------|----------|
| `d`      | double   |
| `c`      | char     |
| `i`      | integer  |
| `P`      | pointer  |
| `K`      | constant |

## [fstream](#c-standard-libraries)
Reading and writing to files.

- `#include <fstream>`

| Function                    | Description                                      |
|-----------------------------|--------------------------------------------------|
| `ifstream`                  | Reading from a file                              |
| `ofstream`                  | Writing to a file. Opens a new one if not found. |
| `fstream`                   | Reading and writing.                             |
| `fstream file("name.txt");` | Opens file                                       |
| `file.open("name.txt");`    | Also opens the file                              |
| `file.close();`             | Closes a file                                    |
| `file.is_open()`            | Checks if it opened                              |

- A file acts like a regular buffer
	- `file << "concatenate";`
	- `file >> input;`
	- `getline(file, line);`

## [optional](#c-standard-libraries)
Value that may or may not be present. Helps avoid using null pointers or sentinel values(Ex: End of file).

- `#include <optional>`

| Function                         | Description                             |
|----------------------------------|-----------------------------------------|
| `bool has_value()`               | Checks if value exists.                 |
| `const T& value()`               | Gets value. Throws if empty.            |
| `T value_or(default)`            | Returns the value or a default if empty |
| `void reset()`                   | Makes value empty                       |
| `std::nullopt`                   | Empty value                             |
| `optional<int> x = 10;`          | Assigns value                           |
| `T& emplace(ConstructorArgs...)` | Constructs a new value in place.        |

## [cctype](#c-standard-libraries)
Character functions.

- `#include <cctype>`

| Function              | Description                                            |
|-----------------------|--------------------------------------------------------|
| `char toupper(char)`  | Upper case                                             |
| `char tolower(char)`  | Lower case                                             |
| `bool isxdigit(char)` | Is hexadecimal numeric character                       |
| `bool isupper(char)`  | Is upper case character                                |
| `bool isspace(char)`  | Is a whitespace character. Spaces, tabs, and new lines |
| `bool ispunct(char)`  | Is a punctuation/special character                     |
| `bool islower(char)`  | Is lower case character                                |
| `bool isdigit(char)`  | Is a digit                                             |
| `bool isblank(char)`  | Is a space or tab                                      |
| `bool isalpha(char)`  | Is lower or upper case letter                          |
| `bool isalnum(char)`  | Is lower, upper, or number                             |

## [pair](#c-standard-libraries)
Key value pair.

- `#include <utility>`

| Function                         | Description                           |
|----------------------------------|---------------------------------------|
| `.first`                         | Get or update first value             |
| `.second`                        | Get or update second value            |
| `pair<T1, T2> make_pair(T1, T2)` | Creates a pair by inferring the type. |

## [tuple](#c-standard-libraries)
Fixed size collection of values. Useful for returning multiple values from a function instead of using a struct.

- `#include <tuple>`

| Function                                    | Description                             |
|---------------------------------------------|-----------------------------------------|
| `size_t tuple_size<decltype(tuple)>::value` | Number of elements in a tuple           |
| `tuple<...> tuple_cat(t1, t2, ...)`         | Concatenates tuple2 onto tuple          |
| `T& get<I>(tuple)`                          | Get and set element at index `I`        |
| `std::tie(v1, v2, ...) = tuple;`            | Creates references of each tuple value. |
| `tuple<...> make_tuple(T1, T2, ...)`        | Creates a tuple by inferring the types. |

## [algorithm](#c-standard-libraries)
Algorithms that use iterators.

- `#include <algorithm>`

| Function                                                        | Description                               |
|-----------------------------------------------------------------|-------------------------------------------|
| `void fill(iterator first, iterator last, value)`               | Fills range with values.                  |
| `void sort(iterator first, iterator last)`                      | Sorts range in ascending order.           |
| `OutputIt copy(InputIt first, InputIt last, OutputIt outFirst)` | Copies range to another. Returns outLast. |
| `iterator find(iterator first, iterator last, value)`           | Finds the first occurrence of value.      |
| `size_t count(iterator first, iterator last, value)`            | Counts occurrences of value.              |
| `void reverse(iterator first, iterator last)`                   | Reverses elements in range.               |
