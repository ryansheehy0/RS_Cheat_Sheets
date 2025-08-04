[Home](../README.md#c)

# C++ Standard Libraries
- `using std namespace;` is assumed for these libraries.


- std::pair - key value pair
- std::tuple - Fixed size collection of values of potentially different types.
	- Useful for returning multiple values form a function. You don't have to define a struct.
- std::optional
- std::Variant
- std::initializer_list

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
- [characters functions](#characters-functions)

<!-- /TOC -->

## [iostream](#c-standard-libraries)
Used for reading user input data from the terminal and outputting to the terminal.

- `#include <iostream>`

| Method                                   | Description                                                                         |
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
`#include <sstream>`

Used to treat a string as a stream. The underlying string doesn't change.

- using namespace std

|                           |                                                                    |
|---------------------------|--------------------------------------------------------------------|
| `ostringstream`           | Output string stream. Used for `<<`s                               |
| `istringstream`           | Input string stream. Used for `>>`s.                               |
| `stringstream`            | Input and Output string stream                                     |
| `stringstream ss(string)` | Opens string stream                                                |
| `ss << "string";`         | Concatenates to the string stream, but not the constructor string. |
| `ss >> str;`              | Puts the next word into str. Words are separated by spaces.        |

## [cmath](#c-standard-libraries)
- Floating point math operations

|                       |                                    |
|-----------------------|------------------------------------|
| `pow(base, exponent)` |                                    |
| `sqrt(x)`             |                                    |
| `fabs(x)`             | absolute value                     |
| `ceil(x)`             | Round up                           |
| `floor(x)`            | Round down                         |
| `rand()`              | Random int from `0` and `RAND_MAX` |
| `M_PI`                |                                    |

### [ctime](#c-standard-libraries)
- `#include <ctime>`
- `srand(time(0));`
	- Sets the seed for random number

## [cstdlib](#c-standard-libraries)
- Integer math operations

|          |                        |
|----------|------------------------|
| `abs()`  |                        |
| `atoi()` | Converts string to int |

## [iomanip](#c-standard-libraries)

|                             |                                              |
|-----------------------------|----------------------------------------------|
| `cout << fixed`             | `setprecision` counts after decimal point    |
| `cout << setprecision(num)` | Limits float digits                          |
|                             | Continually active                           |
|                             | Rounds the output                            |
| `cout << setw(10)`          | Sets width of output                         |
|                             | Only valid for the value directly after `<<` |
|                             | Aligns output to the right side              |
|                             | Value larger than `setw` then it ignored     |
| `cout << right;`            | Justify right                                |
| `cout << left;`             | Justify left                                 |

- `cout << setprecision(2) << 9.99999;`
	- Ex: `10`
- `cout << fixed << setprecision(2) << 9.99999;`
	- Ex: `10.00`
- If no fixed and exceeds bounds of `setprecision`, then it's outputted in scientific notation
	- Ex: `cout << setprecision(2) << 146.789;` outputs `1.5e+02`

## [typeinfo](#c-standard-libraries)
- `typeid(var).name()` gives a string of the type of variable.

| returned | Type     |
|----------|----------|
| `d`      | double   |
| `c`      | char     |
| `i`      | integer  |
| `P`      | pointer  |
| `K`      | constant |

## [fstream](#c-standard-libraries)
- Reading and writing to files

|                             |                                             |
|-----------------------------|---------------------------------------------|
| `ifstream`                  | Reading file                                |
| `ofstream`                  | Writing file. Opens a new one if not found. |
| `fstream`                   | Reading and writing                         |
| `fstream file("name.txt");` | Open file                                   |
| `file.open("name.txt");`    | Also opens the file                         |
| `file.close();`             | Closes a file                               |
| `file.is_open()` and `file` | Checks if it opened                         |

- A file acts like a regular buffer
	- `file << "concatenate";`
	- `file >> input;`
	- `getline(file, line);`

## [optional](#c-standard-libraries)
Optional is used when there is the possiility that you cannot get any code back?

```C++
optional<string> openFile(string fileName) {
	fstream file(fileName);
	if (!file) return {} // No data

	string contents;
	stringstream contents_stream;
	contents_stream << file.rdbuf();
	contents = contents_stream.str();
	file.close();

	return contents;
}

int main() {
	optional<fstream> file = openFile("test.cpp");
	if (!file){
		cout << "Error opening test.cpp" << endl;
		return 1;
	}
}
```

- `.emplace(constructor args)` - used to construct a new object of the optional type.

- There's the `optionalVar.value_or(value)` which returns the value in optionalVar if it's there or the value inside the `()`s if it's not.

## [characters functions](#c-standard-libraries)
`#include <cctype>`
- All of these functions take in char arguments.

| Function        | Description                                            |
|-----------------|--------------------------------------------------------|
| `std::toupper`  | Convert to upper case                                  |
| `std::tolower`  | Convert to lower case                                  |
| `std::isxdigit` | Is hexadecimal numeric character                       |
| `std::isupper`  | Is upper case character                                |
| `std::isspace`  | Is a whitespace character. Spaces, tabs, and new lines |
| `std::ispunct`  | Is a punctuation/special character                     |
| `std::islower`  | Is lower case character                                |
| `std::isdigit`  | Is a digit                                             |
| `std::isblank`  | Is a space or tab                                      |
| `std::isalpha`  | Is lower or upper case letter                          |
| `std::isalnum`  | Is lower, upper, or number                             |
