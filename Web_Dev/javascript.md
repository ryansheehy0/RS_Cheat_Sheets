[Home](../README.md)

# JavaScript
JavaScript is the only language that can be run in the browser.

<!-- TOC -->

- [Comments](#comments)
- [Primitive Data Types](#primitive-data-types)
- [Sets](#sets)
- [Variables](#variables)
- [Strings](#strings)
	- [String Functions](#string-functions)
	- [Concatenation with numbers](#concatenation-with-numbers)
- [Arrays](#arrays)
	- [Array Functions](#array-functions)
	- [For of](#for-of)
- [Equality Operators](#equality-operators)
- [Switch Block](#switch-block)
- [Functions](#functions)
	- [This Keyword](#this-keyword)
	- [Tagged Templates](#tagged-templates)
- [Logical Or for Fallbacks](#logical-or-for-fallbacks)
- [&& and ?? for Assignment](#-and--for-assignment)
	- [Logical and for Assignment](#logical-and-for-assignment)
	- [Nullish coalescing operator ??](#nullish-coalescing-operator-)
- [Useful Functions](#useful-functions)
- [Printing with color](#printing-with-color)
- [Sending requests](#sending-requests)
	- [XMLHttpRequest](#xmlhttprequest)
	- [Fetch](#fetch)
		- [Optional Fetch Argument](#optional-fetch-argument)
	- [Axios](#axios)
- [Objects](#objects)
	- [Updating values in Object](#updating-values-in-object)
	- [For In](#for-in)
	- [JavaScript Object NotationJSON](#javascript-object-notationjson)
	- [Spread Operator](#spread-operator)
	- [Object to Array](#object-to-array)
	- [Optional Chaining](#optional-chaining)
- [Template Literals](#template-literals)
- [Import and Export](#import-and-export)
- [Errors](#errors)
	- [Error Handling/Try Catch](#error-handlingtry-catch)
	- [Throwing Errors](#throwing-errors)
- [Promises](#promises)
	- [Promise.all, Promise.race, Promise.allSettled, Promise.any](#promiseall-promiserace-promiseallsettled-promiseany)
- [Async/Await](#asyncawait)
- [DOM Manipulation](#dom-manipulation)
	- [Accessing Elements](#accessing-elements)
	- [Modifying Elements](#modifying-elements)
	- [Creating and Appending Elements](#creating-and-appending-elements)
		- [Insert Adjacent Element](#insert-adjacent-element)
	- [Event Handling](#event-handling)
		- [Commonly Used Events](#commonly-used-events)
		- [Default Events](#default-events)
		- [Custom Events](#custom-events)
			- [Sending Custom Event](#sending-custom-event)
			- [Receiving Custom Event](#receiving-custom-event)
	- [Traversing the DOM](#traversing-the-dom)
- [This](#this)
- [Timing](#timing)
- [+/-/++/-- Operators](#----operators)
- [Local/Session Storage](#localsession-storage)
- [Common APIs](#common-apis)
	- [Dayjs](#dayjs)
- [URL of Webpage](#url-of-webpage)
	- [Redirect URL](#redirect-url)
	- [Reload page](#reload-page)
- [Regex](#regex)
- [Object Oriented](#object-oriented)
	- [Class Constructors](#class-constructors)
	- [Prototype](#prototype)
- [Debugging](#debugging)
- [Labels](#labels)
- [Symbols](#symbols)
- [Symbol.iterator](#symboliterator)
	- [Adding Symbol.iterator to object](#adding-symboliterator-to-object)
- [Generator functions](#generator-functions)
- [Async iterators](#async-iterators)
- [UUIDs](#uuids)

<!-- /TOC -->

## [Comments](#javascript)

```javascript
// Inline comment
/*
    Multi-line comment
    No nested multi-line comments
*/
```

## [Primitive Data Types](#javascript)
- Dynamically typed. A variable can be assigned to multiple types.
- By default all objects and array are pass by reference. In order to do a pass by value you have to use the spread operator.`[...array]`. However, getting one element is pass by value. `array[0]` is pass by value.
- `typeof operand` can be used to get a string of the type
    - undefined
        - Is an uninitialized value
    - boolean
        - Includes true or false
        - Something is false if it has the values of 0, -0, On, "", null, undefined, NaN, or false.
        - Often start with the words is, has, or should.
        - To convert regular values to boolean you can use `!!value`
    - string
    - number
        - Includes ints, floats, NaN, and Infinity
    - object
        - null. The absence of an object.
        - key-value pairs
        - Object types: object, date, array, string, number, boolean.
    - function
    - symbol
        - `Symbol()` or `Symbol("description")`
        - Unique(Symbols cannot equal anything else) and immutable.
    - bigints
        - Support integers of arbitrary size
        - `123n` or `BigInt(123)`

## [Sets](#javascript)
- Only can store unique values. If you attempt to add a duplicate it will be ignored.
- There is no specific ordering.
- `new Set()`
- `set.add(value)`, `set.delete(value)`, `set.has(value)`, `set.size`, `set.clear()`

This is useful to get ride of duplicates in an array.
```javascript
const array = [1, 2, 3, 4, 1, 2]
const removedDuplicates = [...new Set(array)]
```

## [Variables](#javascript)
`var` - Can be used through your whole function or program if declared outside a function.

`let` - Only used within the scope of where you declared it

`const` - Variable that can never change. Block-scope
    - You can still do array functions like `.pop` or `.push`

- A refresh in the browser clears all variables.
- camelCase is most commonly used

```javascript
function example() {
  var x = 10; // function scope
  let y = 20; // block scope

  if (true) {
    var x = 30; // same variable, modifies the outer x
    let y = 40; // different variable, block-scoped
    console.log(x); // 30
    console.log(y); // 40
  }

  console.log(x); // 30
  console.log(y); // 20 (outer y, unchanged)
}

example();
```

Var allows for hoisting which isn't recommended

```javascript
console.log(a)
var a = 1
// This won't throw an error

// This is the same as
var a
console.log(a) // undefined
a = 1
```

## [Strings](#javascript)
Strings can start with "s, 's, or `s

Escape sequences: \\", \\', \\`, \\ \\
- \b backspaces
- \f form feed
- \n new line
- \r Carriage return
- \t tab
- \v vertical tab

+s can be used to concatenate strings

Strings are immutable. Once a string is created its value cannot be changed. If the value is changed what is happening is that a new string is being made and assigned.

### [String Functions](#javascript)
- `.length`
    - Size of the string
- `.slice(start, end)` or `.slice(start)`
    - Extracts part of a string.
    - The index of the string starts at 0.
    - The start is inclusive while the end is not.
    - Ex: `let text = "Apple, Banana, Kiwi"; let part = text.slice(7,13); //part is "Banana"`
    - slice allows for negative numbers. The last character is -1.
    - If only the start is specified then the rest of the string is sliced out.
- `.substr(start, length)` or `.substr(start)`
    - Extracts part of a string from the start(inclusive) to the length
    - Negative numbers can be used.
- `.replace(/regex/, replaced_string)` or `.replace(searching_string, replaced_string)`
    - /regex/g can be used to replace multiple times instead of just once
- `.toUpperCase()` or `.toLowerCase()`
- `.trim()` or `.trimStart()` or `.trimEnd()`
    - Used to remove the white space from start and/or end of a string
- `.split(string)` or `.split(/regex/)`
    - Converts a string to an array by splitting along the string arg. Doesn't include the splitting string arg.
- `.charAt(index)`
    - Gets the character at that index. If there is no character there then it returns an empty string.
    - Cannot take negative numbers.
- `.includes("substring")`
    - Is the substring included in the string?

### [Concatenation with numbers](#javascript)
When you use the `+` keyword with a string and a number, the number is converted to a string and they are concatenated.

```javascript
10 + '10' // '1010'
'10' + 10 // '1010
```

## [Arrays](#javascript)
Arrays allow you to store several pieces of data in the same place. Elements can be any data type and arrays are mutable.

### [Array Functions](#javascript)
- `.length`
- `.join(string_separator)`
    - Converts an array to a string with the string separators between each element.
- `.pop()`
    - Removes the last element and returns what was popped.
- `.push(value)`
    - Adds the value to the end of the array.
- `.shift()`
    - Removes the first element and shifts the array to the left by one. Returns what was shifted out.
- `.unshift(value)`
    - Adds the value to the beginning of the array.
- `.concat(array)`
    - Creates a new array by merging the adding the array arg to the array that was called upon.
- `.flat()`
    - Reducing a multi-dimensional array to one array.
    - Ex: [[1,2],[3,4]] -> [1,2,3,4]
- `.splice(index where new elements should be added, how many elements should be removed, new elements to be added)`
    - Elements are added before the index specified
    - Can be used to remove elements in an array

```javascript
const fruits = ["Banana", "Orange", "Apple", "Mango"]
fruits.splice(2, 0, "Lemon", "Kiwi")
console.log(fruits)
//Outputs: [ "Banana", "Orange", "Lemon", "Kiwi", "Apple", "Mango" ]

// Removes 1 element from an array
fruits = ["Banana", "Orange", "Apple", "Mango"]
fruits.splice(1, 1)
console.log(fruits)
//Outputs: [ "Banana", "Apple", "Mango" ]
```

- `.forEach((element, index, array) => {})`
    - Runs the function for each element in the array.
    - The args that forEach passes are value/element, key/index, and array
    - You cannot use the keyword `break` in a forEach loop
    - If you return in a forEach loop it goes to the next iteration. It doesn't return a value
- `.map((element, index, array) => {})`
    - Performs a function for each element in an array, then stores the returned values in a new array.
    - The args that forEach passes are value/element, key/index, and array
    - Map always returns an array of the same length
- `.filter((element, index, array) => {})`
    - Filter loops through and array and allows you to remove elements
    - If the function returns false for that element then it gets removed.

```javascript
// Keeps all the even numbers
let numbers = [1, 3, 4, 5, 5, 2]
numbers = numbers.filter((element) => {
    return element % 2 === 0
})
console.log(numbers)
```

- `.slice(start, end)` or `.slice(start)`
    - Slices out a piece of an array into a new array without modifying the existing the array.
    - Start is inclusive while end is exclusive. `array.slice(0, array.length)` selects the whole array.
- `.reduce((accumulator, currentValue, index, array) => {}, startingValue)`
    - Takes an array and reduces it to 1 value
    - The accumulator is set to the startingValue when starting to go through the function.
    - Whatever is returned from the function is what is set to the total for the next iteration

```javascript
const prices = [10, 20, 30, 40]
const totalPrice = prices.reduce((total, price) => {
    return total + price
}, 0)
console.log(totalPrice)

// As apposed to using a forEach
let totalPrice = 0
prices.forEach(price => {
    totalPrice += price
})
console.log(totalPrice)
```

- `.find((element, index, array) => {})`
    - Used to find the first element that satisfies the given function.
    - If the function returns true on that element then `.find` will return that element.
- `.findIndex((element, index, array) => {})`
    - Used to find the index of the first element that satisfies the given function.
    - If the function returns true on that element then `.findIndex` will get it's index.
- `.sort((a, b) => a - b)`
    - If the function returns a negative number "a" is sorted before "b"
    - If the function returns a positive number "b" is sorted before "a"

```javascript
const numbers = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]

// Sorts least to greatest
numbers.sort((a, b) => a - b)
console.log(numbers); // Output: [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]

// Sorts greatest to least
numbers.sort((a, b) => b - a)
console.log(numbers); // Output: [9, 6, 5, 5, 5, 4, 3, 3, 2, 1, 1]
```

- `.includes(value)`
  - If the array includes value it returns true
- `.some(function(currentValue, index, array))`
  - Tests whether at least one element in the array passes the provided function.

```javascript
const numbers = [1, 2, 3, 4, 5]
const hasEven = numbers.some((number) => {
  return number % 2 === 0
})
```

- `.at(index)`
    - This is the same as using the `[]` syntax, but also allows for negative numbers.
    - Instead of `array[array.length - 1]` you can instead use `array.at(-1)`

### [For of](#javascript)
Used to loop through each element in an array.

This is better than using `.forEach` because this still allows you to break and return from the loop.

```javascript
const myArray = [1, 2, 3, 4, 5]

for(const value of myArray){
  console.log(value)
}
```

In order to get the index you have to use `.entries()`

```javascript
const myArray = [1, 2, 3, 4, 5]

for(const [i, value] of myArray.entries()){
  console.log(i, value)
}
```

## [Equality Operators](#javascript)
- `===` `!==` strict operator
    - Doesn't do the type conversion
- `==` `!=`
    - Attempts to convert both values to a common type. Allows type coercion.
    - <, >, <=, >= attempts to convert values

```javascript
3 === 3 // true
3 === '3' // false
3 == 3 // true
3 == '3' // true
```

## [Switch Block](#javascript)

```javascript
let x = 10
switch(x) {
    case 1:
        console.log("This is a 1.")
        break
    case 2:
        console.log("This is a 2.")
        break
    case 3: {//New scope
        console.log("This is a 3.")
        break
    }
    default:
        console.log("This is greater than 2.")
        break
}
```

You can create a new scope in a case block using '{}'s which will prevent variable naming conflicts.

## [Functions](#javascript)
- If you don't return anything then the return value is undefined
    - Can be declared below their use. This is called hoisting and is unique to JS.
```javascript
func() // Prints out Test
function func() {
    console.log("Test")
}
```

```javascript
function func_name1(arg1, arg2) {}

const func_name2 = function(arg1, arg2) {}

const func_name3 = (arg1, arg2) => {}

const func_name4 = arg1 => {}

// Rest operator. Used to allow a function to have a variable number of args.
const func_name4 = (...args) => {
    console.log(args[0], args[1])
}
```

You can put default arguments into function

```javascript
function func_name(array = [], max = Math.max(...arg1)){
    // Default arguments
}
```

You can directly return results with the arrow function. You don't need the `{}`s as long as its on the same line.

```javascript
const test = () => 5 // function returns 5
```

### [This Keyword](#javascript)

```javascript
function regularFunction(){
    console.log(this)
}

const pointerFunction = () => {
    console.log(this)
}

const obj = {
    regular: regularFunction,
    pointer: pointerFunction,
    pointerHere: () => {
        console.log(this)
    },
    regularHere: function(){
        console.log(this)
    }
}

obj.regular() // "this" refers to "obj"
obj.regularHere() // "this" refers to "obj"
regularFunction() // "this" refers to "window"

obj.pointer() // "this" refers to "window"
obj.pointerHere() // "this" refers to "window"
pointerFunction() // "this" refers to "window"
```

Pointer functions inherit `this` from their surroundings when they are created/defined.

The function keyword inherits `this` when it is called.

- You can run a function immediately by doing

```javascript
(function() {
    console.log("Function that ran immediately")
})()
```

### [Tagged Templates](#javascript)
You can pass template literals into functions without the need of ()s

```javascript
function myFunction(string, values){
  console.log(string) // An array with ["Hello, ", "!"]
  console.log(values) // The value of "World"
}

const name = "World"
myFunction`Hello, ${name}!`
```

## [Logical Or for Fallbacks](#javascript)
You can have fallback values incase your first value is falsy(null, undefined, 0, empty string, etc).

```javascript
// Setting a variable
const variable = A || B || C
// Arguments into functions
func(A || B || C)
/*
If A is falsy then use B
If B is falsy then use C
*/
```

## [&& and ?? for Assignment](#javascript)

### [Logical and for Assignment](#javascript)
The Logical And can be used to conditionally assign a variable based upon the condition.

If the condition is true it assigns the variable to the valueIfTrue.

If the condition is falsy it assigns the variable to the value of condition.

```javascript
const valueIfTrue = "value"

const condition = true
const variable = condition && valueIfTrue
consol.log(accessLevel) // "value"

const condition = false
const variable = condition && valueIfTrue
consol.log(accessLevel) // false

const condition = undefined
const variable = condition && valueIfTrue
consol.log(accessLevel) // undefined
```

### [Nullish coalescing operator ??](#javascript)
If the nullish coalescing operator is the opposite of &&.

If the condition is null or undefined it assigns the variable to the valueIfFalse.

If the condition is not null or undefined it assigns the condition.

```javascript
const valueIfNullOrUndefined = "value"

const condition = "truthy condition"
const variable = condition ?? valueIfNullOrUndefined
consol.log(accessLevel) // "truthy condition"

const condition = false
const variable = condition ?? valueIfNullOrUndefined
consol.log(accessLevel) // "value"
```

## [Useful Functions](#javascript)

|                                          |                                                                                   |
|------------------------------------------|-----------------------------------------------------------------------------------|
| console.log("x is " + x)                 | Prints to the console.                                                            |
| console.log("x is", x)                   | Prints to the console. "x is x"                                                   |
| prompt("Message")                        | Shows a pop up with message and allowing user input.                              |
| alert("Message")                         | Shows an alert to the user. No user input.                                        |
| confirm("Message")                       | Shows message to user and takes user input as true or false.                      |
| Math.PI                                  | 3.141592653589793                                                                 |
| Math.abs(num)                            | Absolute value                                                                    |
| Math.random()                            | Returns a random floating point num between 0 and 1. Can return a 0, but not a 1. |
| Math.floor(num)                          | Rounds down to the nearest whole number                                           |
| Math.floor(Math.random() * (num + 1))    | Picks a random integer from 0 to num.                                             |
| Math.ceil(num)                           | Rounds up to the nearest whole number                                             |
| .toFixed(number of decimal places)       | Rounds to the number of decimal places.                                           |
| parseInt(str) or parseInt(str, base num) | Converts a string to an int. If it can't then it returns NaN                      |
| .toString()                              | Convert a data type to a string.                                                  |
| Math.pow(A, B) or A ** B                 | A to the power of B. A^B                                                          |

## [Printing with color](#javascript)

- Adds these strings to the console log.
    - Ex: `console.log("\x1b[31mRED")` prints RED in red

| Name       | String      |
|------------|-------------|
| Reset      | `\x1b[0m`   |
| Bright     | `\x1b[1m`   |
| Dim        | `\x1b[2m`   |
| Underscore | `\x1b[4m`   |
| Blink      | `\x1b[5m`   |
| Reverse    | `\x1b[7m`   |
| Hidden     | `\x1b[8m`   |
| FgBlack    | `\x1b[30m`  |
| FgRed      | `\x1b[31m`  |
| FgGreen    | `\x1b[32m`  |
| FgYellow   | `\x1b[33m`  |
| FgBlue     | `\x1b[34m`  |
| FgMagenta  | `\x1b[35m`  |
| FgCyan     | `\x1b[36m`  |
| FgWhite    | `\x1b[37m`  |
| FgGray     | `\x1b[90m`  |
| BgBlack    | `\x1b[40m`  |
| BgRed      | `\x1b[41m`  |
| BgGreen    | `\x1b[42m`  |
| BgYellow   | `\x1b[43m`  |
| BgBlue     | `\x1b[44m`  |
| BgMagenta  | `\x1b[45m`  |
| BgCyan     | `\x1b[46m`  |
| BgWhite    | `\x1b[47m`  |
| BgGray     | `\x1b[100m` |

## [Sending requests](#javascript)

### [XMLHttpRequest](#javascript)
```javascript
const req = XMLHttpRequest()
req.open("GET"/*HTTP Method*/, "http://test.com"/*URL */) // Prepares an http request to be sent
req.withCredentials = true // Include cookies, authorization headers, or TLS client certificates
req.onload = () => {
    console.log(req.response)
    // Probably need to convert JSON to obj
}
req.send()
```

### [Fetch](#javascript)
Used to fetch data from a server. Returns a promise of the response.

```javascript
fetch("URL")
.then(response => response.json()) // asynchronously returns an object from the json string
.then(data => {
    console.log(data)
})
.catch(error => {
    console.log(error)
})
```

You can specify the headers that fetch uses.

```javascript
fetch("URL", {
    method: "POST",
    headers: {
        "Content-Type": "application/json"
    },
    body: JSON.stringify({ key1: "value1", key2: "value2"})
})
    .then(response => response.json()) // asynchronously returns an object from the json string
    .then(data => {
        console.log(data)
    })
    .catch(error => {
        console.log(error)
    })
```

#### [Optional Fetch Argument](#javascript)

| method: | Description                     |
|---------|---------------------------------|
| GET     | Gets data from the server.      |
| PUT     | Updates data in the server.     |
| POST    | Creates new data in the server. |
| DELETE  | Deletes data in the server.     |

| credentials: | Description                                                 |
|--------------|-------------------------------------------------------------|
| same-origin  | Cookies/credentials only in request when same origin.       |
| include      | Cookies/credentials stored in request regardless of origin. |
| omit         | Excludes cookies and credentials                            |

Origin means the same URL, protocol, domain(.com, .net, etc), and port.

| cache: | Description                                         |
|--------|-----------------------------------------------------|
| reload | Stop caching of data by the browser for that fetch. |

| redirect: | Description                      |
|-----------|----------------------------------|
| follow    | Automatically follows redirects. |
| manual    | Can manually handle redirects.   |
| error     | Error when there are redirects.  |

`headers:` are used to send additional information.

```javascript
headers: {
    'Content-Type': 'application/json'
}
```

`body:` is where the data you want to send is stored such as JSON.

Example:

```javascript
fetch('api/request', {
    method: 'POST',
    headers: {
        'Content-Type': 'application/json',
    },
    body: JSON.stringify(json),
})
```

### [Axios](#javascript)
Axios is a library which builds off of XMLHttpRequest to make it more convenient to use.

## [Objects](#javascript)
Objects are used to store an unordered list of properties to describe one thing.

Literal object notation is an object created with key-value pairs.

```javascript
let dynamicKey = "key"

let testObj = {
    "A food": "hamburger",
    "drink": "water",
    [dynamicKey]: "value"
}

let test2Obj = {
    food: "hamburger",
    drink: "water",
}

console.log(testObj.drink) // water
// if the key contains a space then you must use this syntax
console.log(testObj["A food"]) // hamburger
```

- You can delete a property from an object
    - Ex: `delete testObj.drink`
- You can check if an object has a property with `.hasOwnProperty("property")`
    - Ex: `testObj.hasOwnProperty("A food")`
- Objects can have functions. Methods are functions inside objects.

```javascript
// Both of these syntaxes work
let obj = {
    function1: function(){},
    function2(){}
}
```

- Object.values(object) converts an object to an array where the keys are replaced with indices.
- Object.keys(object) gets an array of the keys of that object
- You can do object shorthand if the key and value are the same

```javascript
const object = {
    test1: test1,
    test2: test2,
}
// Shorthand form
const object = {
    test1,
    test2,
}
```

- To get specific values from an object or array you can use this notation

```javascript
const object = {
    key1: "value1",
    key2: "value2"
}
const array = ["ele1", "ele2"]

const { key1, key2 } = object
// or
const { key1: value1, key2: value2} = object
const [ var1, var2 ] = array

console.log(key1) // value1
console.log(key2) // value2
console.log(value1) // value1
console.log(value2) // value2
console.log(var1) // ele1
console.log(var2) // ele2
```

### [Updating values in Object](#javascript)

```javascript
let obj = {
    key1: "value1",
    key2: "value2",
    key3: "value3"
}

function updateObj(obj, key, value){
    return {...obj, [key]: value}
    // this is equivalant to
    const newObj = {...obj}
    newObj.[key] = value
    return newObj
}

console.log(updateObj(obj, "key3", "valueThree"))
/*
Output:
{
    key1: "value1",
    key2: "value2",
    key3: "valueThree"
}
*/
```

### [For In](#javascript)
- You need to do [] when referencing properties in a for in loop in case the property has a space in it.

```javascript
const object = { a: 1, b: 2, c: 3 }

for (const property in object) {
  console.log(property + ": " + object[property])
}
// "a: 1"
// "b: 2"
// "c: 3"
```

### [JavaScript Object Notation(JSON)](#javascript)
- The last key-value pair cannot end with ,s
- Convert JSON to an object
    - `JSON.parse(json)`
    - You can convert asynchronously with `json.json()`

```javascript
const json = '{"first name": "Ryan", "last name": "Sheehy"}'
const obj = JSON.parse(json, (key, value) => {
    if(key === "last name"){
        return "Mr. " + value
    }
    return value
})
console.log(obj) // "first name": "Ryan", "last name": "Mr. Sheehy"
```

- Convert an object to JSON
    - `JSON.stringify(obj)`
    - stringify has optional arguments for formatting.
        - `JSON.stringify(obj, null, 2)`
        - the 2nd argument is like running a map function before making the json
        - the 3rd argument specifies the space for indentation. In this case it is 2 spaces.

### [Spread Operator](#javascript)
- Used to spread out an array or an object

```javascript
const numbersOne = [1, 2, 3]
const numbersTwo = [4, 5, 6]
const numbersCombined = [...numbersOne, ...numbersTwo] // [1, 2, 3, 4, 5, 6]

const numbers = [1, 2, 3, 4, 5, 6]
const [one, two, ...rest] = numbers
console.log(one) // 1
console.log(two) // 2
console.log(rest) // 3, 4, 5, 6

const obj1 = {
  firstName: "Ryan",
  lastName: "Sheehy",
}
const obj2 = {
  firstName: "Ryan",
  lastName: "Sheehy",
}
const obj3 = {...obj1, ...obj2}
```

It can be used to create an array from something that isn't an array. `[...nonArray]`

### [Object to Array](#javascript)
`Object.values(obj)` converts the obj to an array with their values in the array.

### [Optional Chaining](#javascript)
Optionals chaining allows you to only access a field if the previous field is there. Otherwise it will return undefined.

```javascript
let car = {
  make: "Toyota",
  model: "Camry",
  engine: {
    type: "V6",
    horsepower: 270
  }
}

let horsepower = car?.engine?.horsepower
// If there is a car value then get the engine field
    // If there is an engine field get the horsepower field in that engine object
// If any of these are false then return undefined
```

## [Template Literals](#javascript)
Used to make complete string with embedded JS.
- Starts with \`s
- It allows you to have multi-line strings with a newline inserted.

```javascript
let person = {
    name: "Ryan Sheehy",
    age: "21",
}
console.log(`Hello, my name is ${person.name}!
I am ${person.age} years old.`)
```

## [Import and Export](#javascript)
Use `export` to export the var/function
    - Ex: `export const name = "Ryan Sheehy"`
    - There can be a default export for a file. There can only be 1 default export.

```javascript
import { name } from "./filepath"
// If it is a .js file you don't have to put .js at the end

//Import everything
import * as objectName from "./filepath"

let x = 10
default export x

// In order to import the default export you use
import Name from "./filepath"
```

In the browser you can send info via the `window` global variable.

```javascript
// Exporting
function test(){console.log("Test")}
window.test = test

// Importing
window.test()
```

## [Errors](#javascript)

### [Error Handling/Try Catch](#javascript)
Error handling is used to keep the code running even when there is an error.

```javascript
try{
    // Code that may throw an error
    if( variable ){
        throw "Custom error message." // The "Custom error message." is in error and not error.name or error.message
        throw new Error("A new error") // This error gets caught by the catch block
    }
}catch(error) {
    // These are the only 2 keys in an error
    console.log(error.name)
    console.log(error.message)
}finally{
    // Code that runs after the try catch regardless of what the try catch does
}
```

### [Throwing Errors](#javascript)
Errors stop the execution of the code. You can throw a custom error by doing

`throw new Error("Name of error")`

## [Promises](#javascript)
Used to handle asynchronous(code can be run in parallel) operations. Can only return either a resolve or a reject.

Returning a new promise is most commonly used to convert a async callback function to an async/await.

- You need a promise or else the function would return nothing.

```javascript
async function promise(){
    let x = true
    return new Promise((resolve, reject) => {
        setTimeout(() => {/*Callback function*/
            if(x){
                resolve("Success")
            }else{
                reject("Failed")
            }
        }, 1000)
    })
}

promise().then((message) => {
    // then runs if the promise returns a resolve
    console.log(message) // "Success"
}).catch((message) => {
    // catch runs if the promise returns a reject
    console.log(message) // "Failed"
})
```

### [Promise.all, Promise.race, Promise.allSettled, Promise.any](#javascript)
`Promise.all` type of functions allow you to run async function in parallel instead of 1 at a time. This makes things faster.

Short circuiting is .

```javascript
const response1 = await promise1()
const response2 = await promise2()
const response3 = await promise3()
// These are ran synchronously and take a long time.

const responses = await Promise.all([promise1(), promise2(), promise3()])
console.log(responses) // this returns an array of all the responses. The promises are ran in parallel

// It is recommended to use Promise.allSettled and then manually check if any of the resolves were rejected
const responses = await Promise.allSettled([promise1(), promise2(), promise3()])
console.log(responses) // Returns an array of objects with fields of status and value/reason.
// { status: "fulfilled", value: "result" }
// { status: "rejected", reason: "Reason for the error" }
const errors = responses.filter((r) => r.status === "rejected")
const successes = responses.filter((r) => r.status === "fulfilled").map((r) => r.value)
```

Short circuit just means it returns the result.

| Name               | Description                                                                                             |
|--------------------|---------------------------------------------------------------------------------------------------------|
| Promise.allSettled | Returns all the results even if they were rejected                                                      |
| Promise.all        | If any of the input values are rejected it throws an error and doesn't return any of the other results. |
| Promise.race       | When the first input value is settled(resolved or rejected) it returns the result.                      |
| Promise.any        | When the first input value is resolved it returns the result.                                           |

## [Async/Await](#javascript)
Used to make promises easier to work with. Only works with asynchronous functions. Await waits for the Promise to resolve.

All async function return a promise. It is recommended that if you manually return a new promise then you put it in an async function.

If a child function returns a promise and you are calling the parent function that you want to await then you have to make both the child and the parent async.

```javascript
function childFunction() {
  let x = true
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if(x){
        resolve("Sub-function resolved");
      }else{
        reject("Sub-function resolved");
      }
    }, 1000);
  });
}

async function parentFunction() {
  await subFunction();
}

async function main(){
  await parentFunction()
}

mainFunction().then(() => {
  console.log("Main function completed");
});


async func_name = () => {
    try{
        let variable = await promise_function()
        // The code will wait until the promise_function returns.
        let variable2 = await promise_function2()
    }catch(error){
        // If either promise_function or promise_function2 returns an error
    }
}
```

If a sub function returns a promise and you want to await it you have to make all functions async.

## [DOM Manipulation](#javascript)
The DOM is the Document Object Model.

The `window` is an object that have internal functions and data that can be accessed. `document` is an object part of the window and is the DOM. `document` allows JavaScript to access different elements of the HTML page.

### [Accessing Elements](#javascript)

|                                          |                                                            |
|------------------------------------------|------------------------------------------------------------|
| document.getElementById('id')            | Returns element with the id                                |
| document.getElementsByClassName('class') | Returns a collection of elements with the class            |
| document.getElementsByTagName('tag')     | Returns a collection of elements with the tag/element name |
| document.querySelector('selector')       | Returns the first element with the CSS selector            |
| document.querySelectorAll('selector')    | Returns a collection of element with the CSS selector      |

The selector in querySelector cannot start with a number therefore ids and classes should preferably start with letters.

You can use `:scope` to reference the current element that you are querying on

```javascript
const div = document.querySelector("div")
const divDirectChild = div.querySelectorAll(":scope > *") // Gets any direct children of the div
```

### [Modifying Elements](#javascript)

|                                            |                                                                           |
|--------------------------------------------|---------------------------------------------------------------------------|
| element.textContent = 'text'               | Sets text content of the element                                          |
| element.innerHTML = 'html'                 | Sets the html content of the element                                      |
| element.value = 'value'                    | Sets the value content of the element                                     |
| element.setAttribute('attribute', 'value') | Sets the attribute of the element                                         |
| element.getAttribute('attribute')          | Gets the attribute of the element                                         |
| element.style.property = 'value'           | Sets the CSS style property of the element                                |
| element.classList.add('class')             | Adds a CSS class to the element                                           |
| element.classList.remove('class')          | Removes a CSS class on the element                                        |
| element.classList.toggle('class')          | Toggles the presence of a CSS class on the element                        |
| element.dataset.name = "name"              | Searches the html attributes for data-name and sets its contents to name. |

### [Creating and Appending Elements](#javascript)

|                                                      |                                                                     |
|------------------------------------------------------|---------------------------------------------------------------------|
| document.createElement('tag')                        | Creates a new element with the specified tag. Tag shoudn't have <>s |
| element.appendChild(newChild)                        | Appends a new child element to the given parent element             |
| element.append(child)                                | Appends a new child element. Very similar to appendChild            |
| parentElement.insertBefore(newChild, referenceChild) | Inserts a new child element before a specified reference element    |
| parentElement.removeChild(childElement)              | Removes a specified child element from its parent                   |
| element.remove()                                     | Removes that element form the dom.                                  |

#### [Insert Adjacent Element](#javascript)
`element.insertAdjacentElement("position", newElement)` or `element.insertAdjacentHTML("position", "html")`

| Position Name | Description    |
|---------------|----------------|
| afterbegin    | First child    |
| afterend      | After element  |
| beforebegin   | Before element |
| beforeend     | Last child     |

### [Event Handling](#javascript)

|                                                     |                                                                                          |
|-----------------------------------------------------|------------------------------------------------------------------------------------------|
| element.addEventListener('event', eventFunction)    | Attaches an event listener to the element                                                |
| element.removeEventListener('event', eventFunction) | Removes an event listener from the element                                               |
| event.preventDefault()                              | Prevents the default event for an element. Certain elements have default events.         |
| event.stopPropagation()                             | Only have to worry if you have clickable elements inside clickable elements in the html. |
| event.target                                        | Get the dom element which called the event.                                              |
| event.target.tagName                                | Get the HTML type of dom element. This is in all caps. Ex: `"TEXTAREA"`                  |

```javascript
// To dynamically add listeners to dynamically added elements.
    // You cannot get the element when the element isn't created in the DOM
  document.querySelector("element already created by the dom").addEventListener("click", function(event){
    if(event.target.className.includes("dynamically created element's class")){
      //You can also use ids
      //Your event code here
    }
  })
```

#### [Commonly Used Events](#javascript)

| Event         | Description                                                                                   |
|---------------|-----------------------------------------------------------------------------------------------|
| click         | Element is clicked.                                                                           |
| dblclick      | Element is double clicked.                                                                    |
| load          | Fires when a resource and its dependent resources have finished loading.                      |
| mouseover     | Triggered when the mouse pointer enters an element.                                           |
| mouseout      | Triggered when the mouse pointer leaves an element.                                           |
| keydown       | Fired when a key is pressed down. eventFunction should have an event and the key is event.key |
| keyup         | Fired when a key is released. eventFunction should have an event and the key is event.key     |
| submit        | Fired when a form is submitted. Button needs type="submit" Also submits with the enter key.   |
| change        | Triggered when the value of an element changes.                                               |
| resize        | Triggered when the browser window is resized.                                                 |
| input         | Fired when the value of an input element changes.                                             |
| contextmenu   | Triggered when the right mouse button is pressed.                                             |
| transitionend | Triggered when a CSS transition ends.                                                         |
| error         | Triggered when an error occurs during loading of an external file.                            |

#### [Default Events](#javascript)

- click <a>
    - Automatically changes the URL and goes to that URL.
- submit <form>
    - Refreshes the screen by sending a request to the URL specified in the action attribute of the form.
    - Clears form inputs
    - Changes URL

#### [Custom Events](#javascript)

##### [Sending Custom Event](#javascript)

```javascript
const customEvent = new CustomEvent("customEvent", {
    detail: {
        key: "value"
    }
})

document.dispatchEvent(customEvent)
```

##### [Receiving Custom Event](#javascript)

```javascript
document.addEventListener("customEvent", (event) => {
    console.log(event.detail.key)
})
```

### [Traversing the DOM](#javascript)

|                         |                                                            |
|-------------------------|------------------------------------------------------------|
| element.parentNode      | Returns the parent element of the current element          |
| element.childNodes      | Returns a collection of child nodes of the current element |
| element.firstChild      | Returns the first child element of the current element     |
| element.lastChild       | Returns the last child element of the current element      |
| element.nextSibling     | Returns the next sibling element of the current element    |
| element.previousSibling | Returns the previous sibling element of the current element|
| element.children[index] | Gets the child of the element at the index.                |

## [This](#javascript)
The `this` keyword is used to refer to the current object.

- By default the `this` keyword is in the window object.

```javascript
console.log(this) // This will print the window
let planet = {
    name = "Earth",
    printName = () => {
        console.log(this.name) // Earth
    },
}
```

## [Timing](#javascript)

|                                          |                                                                                               |
|------------------------------------------|-----------------------------------------------------------------------------------------------|
| setTimeout(function, ms)                 | The function runs after the delay time in milliseconds. Other code can run in the background. |
| let interval = setInterval(function, ms) | Runs the function every milliseconds. Other code can run in the background.                   |
| clearInterval(interval)                  | Stops the interval.                                                                           |


1000 Milliseconds = 1 Second

## [+/-/++/-- Operators](#javascript)

```javascript
let variable = 5
let result1 = ++variable // variable becomes 6 and result1 becomes 6
let result2 = --variable // variable becomes 5 and result2 becomes 5
let result3 = variable++ // result3 become 5 and then variable becomes 6
let result4 = variable-- // result4 becomes 6 and then variable becomes 5
```

```javascript
console.log(+"3" + +"5") // 8
    // The +s in front of the string converts it to a num and then those numbers are added together
console.log(-"3" - -"5") // 2
    // The -s in front of the string converts it to a num, but negates it and then those numbers are subtracted from one another.
console.log(-"-3" + -"5") // -2
```

## [Local/Session Storage](#javascript)
Local storage is information stored locally on the browser.

Session storage is information stored locally to that tab.

In incognito/private window it creates a new localStorage and removes it when the window is deleted.

5megabytes max for local storage.

```javascript
localStorage.setItem("key", "value")

localStorage.getItem("key")
    // Returns null if nothing is found

localStorage.removeItem("key")

localStorage.clear()
    // Removes all local storage for your site
```
- Never store passwords, even hashed passwords, in the local storage or session storage.

## [Common APIs](#javascript)

|           |                                                                                                    |
|-----------|----------------------------------------------------------------------------------------------------|
| jQuery    | Makes HTML document traversal and manipulation, event handling, animation, and Ajax easier to use. |
| [day.js](https://day.js.org/docs/en/display/format)    | Dates and Calendars                                                                                          |
| bootstrap | Front-end framework.                                                                               |
| jQuery UI | Makes manipulating things easier. Can work with bootstrap. |
| [Axios](https://axios-http.com/docs/intro)     | ajax in jQuery, but without the jQuery. |

### [Dayjs](#javascript)

Provides more powerful formatting than the inbuilt Date() in JS

```javascript
var today = dayjs()
today.format('MMM D, YYYY')
today.format('[This is the day: ] ddd')
```

Unix time is the number of seconds from Jan 1st, 1970(epoch time).

## [URL of Webpage](#javascript)
Use `document.location` to get properties of the current webpage's URL.

You can get everything after the ? in the URL(query string) by doing `document.location.search`

### [Redirect URL](#javascript)
`document.location.href = newURL`

```javascript
document.location.href = "/new-page"
// or
document.location.href = "https://www.newwebsite.com"
```

### [Reload page](#javascript)
`location.reload()`

## [Regex](#javascript)
Used to match patterns.

```javascript
function validate(input){
    // Does string start with the word regex
        const pattern = /^(regex).*/gm
    if(input.match(pattern)){
        // Matches the regex
    }else{
        // Doesn't match the regex
    }
}
```

or

```javascript
function validate(input){
    const pattern = new RegExp("^(regex).*")
    if(pattern.test(input)){
        // Matches the regex
    }else{
        // Doesn't match the regex
    }
}
```

## [Object Oriented](#javascript)

### [Class Constructors](#javascript)
You can create objects with object literals or using the `new` keyword on classes/constructor functions

- Constructors tend to start with capital letters as JS convention.
- Make things public through the `this` keyword

```javascript
class Vehicle {
    #private_var
    constructor(name, private){
        this.name = name
        this.#private_var = private
    }

    get private_var(){
        return this.#private_var
    }

    set private_var(private_var){
        this.#private_var = private_var
    }
}
```

Constructor functions
```javascript
function Car(name, model, year){
    Vehicle.call(this, name)
    const privateVariable = "Test"
    this.model = model // The this.model variable is automatically created for the object
    this.year = year
    this.info = function () {
        console.log(this)
    }
}
```

Using classes
```javascript
class Car extends Vehicle {
    constructor(name, model, year){
        super(name) // super is the contractor of the parent
            // This will allow you to use this.vehicleConstructorArg1
        this.model = model
        this.year = year
    }

    getAge(){return 2023 - this.year}

    static test(){
        console.log("Test")
    }
}
```

### [Prototype](#javascript)
Adds a variable or function to a class or constructor function.

`Car.prototype.moreInfo = () => {console.log("moreInfo")}`
- All objects of Car, even the ones created in the past, get access to this method.

This can be used to have inheritance with constructor functions.

## [Debugging](#javascript)
Just put `debugger` in your js code and in your inspect element it should allow you to debug

## [Labels](#javascript)
Labels are useful when you have nested for loops and you want to break out of both for loops.

You can use `break label` or `continue label`

```javascript
outerLoop: for (let i = 0; i < 5; i++) {
  for (let j = 0; j < 5; j++) {
    if (i === 2 && j === 2) {
      break outerLoop // Breaks out of the outer loop
    }
    console.log(i, j)
  }
}
```

## [Symbols](#javascript)
All symbols are unique, guaranteed by javascript runtime.

To create a symbol do `Symbol()` or `Symbol("description")`

In order to create a symbol across the global symbol registry do `Symbol.for("globalKey")`.  In order to access this symbol in other places in your code you can use `Symbol.keyFor("globalKey")`

## [Symbol.iterator](#javascript)
The iterator protocol requires the field of `Symbol.iterator` to return an object with a `next()` function which returns an object with `value` and `done` properties.
- `value` is the value returned
- `done` is true when there are no more values. When done is true it doesn't return a value, but instead is just `{ done: true }`

All arrays automatically have a `Symbol.iterator` so you can iterate on them.

```javascript
let array = [1, 2, 3, 4]
let iterator = array[Symbol.iterator]()
console.log(iterator.next()) // { value: 1, done: false }
console.log(iterator.next()) // { value: 2, done: false }
console.log(iterator.next()) // { value: 3, done: false }
console.log(iterator.next()) // { done: true }
```

### [Adding Symbol.iterator to object](#javascript)
In order to use a for of loop with any object, that object needs a `Symbol.iterator` function as a property.

This `Symbol.iterator` function returns an object with a callback `next` function property.

```javascript
const iterableObj = {
    data: [1, 2, 3, 4],
    [Symbol.iterator]: function(){
        let index = 0
        return {
            next: () => { // Use the error function so the `this` keyword doesn't get reset.
                if(index < this.data.length){
                    return { value: this.data[index++], done: false }
                }else{
                    return { done: true }
                }
            }
        }
    }
}

for(const value of iterableObj){
    console.log(value)
}
```

## [Generator functions](#javascript)
Generator functions allow you to create iterators.

To create a generator function use `function* generatorFunc(){}`.

```javascript
function* generatorFunc(){
    yield 1
    yield 2
    yield 3
    yield 4
}

const iterator = generatorFunc()
console.log(iterator.next()) // { value: 1, done: false }
console.log(iterator.next()) // { value: 2, done: false }
console.log(iterator.next()) // { value: 3, done: false }
console.log(iterator.next()) // { value: 4, done: false }
console.log(iterator.next()) // { done: true }
```

## [Async iterators](#javascript)
Async iterators allow you to execute a list of async tasks sequentially. Await for first promise, await for 2nd promise, etc.

The async iterator protocol requires the field of `Symbol.asyncIterator` to return an object with a `next()` function which returns a promise whcih resolves with an object with the properties of `value` and `done`.

```javascript
async function asyncFunc(arg){
    // Some async code
}

const asyncArray = [
    asyncFunc(1),
    asyncFunc(2),
    asyncFunc(3)
]

for await (const result of asyncArray){ // A loop that pauses and await for the next result to finish
    console.log(result)
}
```

```javascript
const asyncIterableObj = {
    data: [asyncFunc(1), asyncFunc(2), asyncFunc(3)],
    [Symbol.asyncIterator](){
        let index = 0
        return {
            next: () => {
                return new Promise((resolve, reject) => {
                    if(index < this.data.length){
                        resolve({ value: this.data[index++], done: false })
                    }else{
                        resolve({ done: true })
                    }
                })
            }
        }
    }
}
```

## [UUIDs](#javascript)
You can generate a new uuid with `crypto.randomUUID()`.
- This only works on the client
- You have to import crypto if you want to use it in node

The probability of a UUID collision is so low, that it can be ignored.