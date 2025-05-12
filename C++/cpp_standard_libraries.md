[Home](../README.md#c)

# C++ Standard Libraries
You can find libraries at `https://cplusplus.com/reference/<library>`

The standard libraries are any library that uses namespace std.
- It's assumed that `using std namespace;` is being used.

- std::stack
- Queues
	- std::queue
	- std::priority_queue
- std::bitset
- std::pair
- std::tuple
- std::optional
	- Is this a data type?
- std::Variant

<!-- TOC -->

- [iostream](#iostream)
- [string](#string)
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

|                       |                                                     |
|-----------------------|-----------------------------------------------------|
| `cout << "string";`   | Output to console                                   |
|                       | Floats don't output `.0`. `99` not `99.0`           |
| `cout << endl;`       | Outputs new line. Same as `\n`                      |
| `cin >> var`          | User input from console                             |
|                       | Inputs are separated by white spaces                |
|                       | If user enters an invalid input it returns false    |
|                       | Keeps new lines in the buffer                       |
| `cin >> var1 >> var2` | Multiple inputs on one line                         |
| `.ignore()`           | Ignores the next character                          |
| `.get(ch)`            | Gets the next character in the buffer including new |
| `.clear()`            | Clears the flags include end of file(eof) flag      |

- `.seekg(offset, std::ios_base::beg)`
	- Sets the position of the input pointer for the stream
	- Ex: `file.seekg(0, ios_base::beg);`
- `cin >> ws` discards white spaces

## [string](#c-standard-libraries)

|                                    |                                               |
|------------------------------------|-----------------------------------------------|
| `string str = "str";`              | If not initialized it will be an empty string |
| `getline(cin, str);`               | Gets all remaining text in the current buffer |
|                                    | Gets up to the next new line                  |
|                                    | Doesn't include the new line in str           |
|                                    | Removes the ending new line in the buffer     |
| `str.size()`                       |                                               |
| `str.at(index)`                    | returns char                                  |
| `str.replace(index, length, str2)` | Replaces starting at index                    |
| `str.find(str2)`                   | Gets the starting index of the string         |
|                                    | Returns `string::npos` if nothing was found   |
| `std::string(1, char)`             | Convert char to a string one 1                |

| Converting to other types |                                    |
|---------------------------|------------------------------------|
| `stoi`                    | String to int                      |
| `stoul`                   | String to unsigned int             |
| `stod`                    | String to double                   |
| `to_string`               | Converts an int or float to string |

### [String Stream](#c-standard-libraries)
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