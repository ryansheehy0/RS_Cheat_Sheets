[Home](../README.md)

# NodeJS
NodeJS is used to run JavaScript outside of the browser.

Somethings work differently when using JS in NodeJS then in the browser. This cheat sheet will cover those differences.

To make a file execute using node you can add `#!/usr/bin/env node` to the beginning of it.

<!-- TOC -->

- [Getting Started](#getting-started)
- [Node Package ManagerNPM](#node-package-managernpm)
	- [Scripts](#scripts)
	- [Importing](#importing)
	- [Exporting](#exporting)
- [Miscellaneous](#miscellaneous)
- [Things that don't work](#things-that-dont-work)
- [this keyword](#this-keyword)
- [Global Variables](#global-variables)
	- [Process](#process)
		- [Arguments from the Terminal](#arguments-from-the-terminal)
- [Events](#events)
	- [Emitting Events](#emitting-events)
	- [Receiving Events](#receiving-events)
- [File System](#file-system)
	- [Reading to Files](#reading-to-files)
	- [Writing to Files](#writing-to-files)
	- [Appending to Files](#appending-to-files)
- [Path](#path)
- [Node-fetch](#node-fetch)
- [Executing terminal commands](#executing-terminal-commands)
- [Debugger](#debugger)

<!-- /TOC -->

## [Getting Started](#nodejs)
Run `node -v` to see what version of node you have. If you don't have node you can install it from [here](https://nodejs.org/en).

You can run `node script.js` or `node script` to run a JS file.

## [Node Package Manager(NPM)](#nodejs)
NPM is used to install dependencies/packages for NodeJS code.

|                           |                                                                                                             |
|---------------------------|-------------------------------------------------------------------------------------------------------------|
| `npm init`                | Sets up a package.json file in order to keep track of needed dependencies.                                  |
| `npm init -y`             | Sets up a package.json file with the default settings.                                                      |
| `npm install <package>`   | Installs the package for your project. Puts it in your package.json                                         |
| `npm install <package>@8.2.4`   | Installs the package with the version 8.2.4 for your project. Puts it in your package.json            |
| `npm i --save-dev <package>` | Installs the package as a dev package.                                                                   |
| `npm i -D <package>`      | Installs the package as a dev package. Short hand for `--save-dev`                                          |
| `npm uninstall <package>` | Uninstalls the package for your project.                                                                    |
| `npm install`             | Installs all the dependencies if there is a package.json file and if the packages aren't already installed. |

package-lock.json locks the versions of the packages so that new version don't brake your code.

- devDependencies are dependencies that are only applied when developing and not in the production release of the app.

### [Scripts](#nodejs)
Inside the package.json

```javascript
"scripts": {
  "start": "node index.js",
  "test": "jest"
}
```

Running a script
`npm run scriptName`

### [Importing](#nodejs)
To import the exported variable you can do `const module = require("./filepath.js")`

In order to import from a package you do `const package = require("packageName")`

You can import json directly `const json = require("./file.json")`

To use the regular importing syntax you can do `npm install @types/node --save-dev`.

### [Exporting](#nodejs)
To export you use the module.exports object

```javascript
module.exports = {
    function1: aFunctionThatDoesSomething,
    variable1: "test",
}
```

## [Miscellaneous](#nodejs)
- Functions that end in "sync" are blocking functions which means they force the other code to wait until it it done.
- index.js is the default location for node.
    - If you run `node ./` it will look for index.js first.
- You can exit the program without throwing an error with `process.exit(1)`

## [Things that don't work](#nodejs)
- window global variable
- alert, prompt, and confirm

## [this keyword](#nodejs)
- In order to use the this keyword you have to be inside a function.

## [Global Variables](#nodejs)

|           |                                                                                       |
|-----------|---------------------------------------------------------------------------------------|
| global    | Global for all files in your program. Like the window global variable in the browser. |
| process   | Info and controls over the current node environment.                                  |
| console   | Log info to the console.                                                              |
| module    |                                                                                       |
| Buffer    | Used to handle binary data.                                                           |
| __dirname | Specifies the absolute path of the currently running JS file.                         |

### [Process](#nodejs)
`process.platform` get what platform the node is running on like linux.

`process.env.NAME` get the environment variable called NAME

`server.address().port` gets the current port the server is running on.

#### [Arguments from the Terminal](#nodejs)
process.argv is an array that contains the command-line arguments.

```
Terminal: node ./ "This is a test" arg1
index.js: console.log(process.argv)
Console:
[
  '/path/to/node/executable',
  '/path/to/your/javascript/file.js',
  'This is a test',
  arg1
]
```

## [Events](#nodejs)

### [Emitting Events](#nodejs)

```javascript
const { EventEmitter } = require('events')
const eventEmitter = new EventEmitter

eventEmitter.emit("eventName")
```

### [Receiving Events](#nodejs)

```javascript
eventEmitter.on("eventName", () => {
})
```

## [File System](#nodejs)
`const fs = require('fs')` or with premisses `const fs = require('fs').promises`

### [Reading to Files](#nodejs)

```javascript
const encodingType = "utf8"

// Blocking/Sync
const file = fs.readFileSync("filepath.txt", encodingType)

// Non-Blocking
fs.readFile("filepath.txt", encodingType, (error, file) => {/* function when file is loaded*/})

// Asynchronous/Promises
async function loadFile() {
    const file = await fs.readFile("filepath.txt", encodingType)
}
```

### [Writing to Files](#nodejs)

```javascript
fs.writeFile("./filepath.txt", "Written data", error => {error ? console.log(error) : false})
```

### [Appending to Files](#nodejs)

```javascript
fs.appendFile("./filepath.txt", "Written data", error => {error ? console.log(error) : false})
```

## [Path](#nodejs)
Used to make working with file paths easier.

`const path = require("path")`

## [Node-fetch](#nodejs)
Allows you to use the fetch function in node

`const fetch = require('node-fetch')`

## [Executing terminal commands](#nodejs)

```javascript
const {exec, execSync} = require("child_process")

exec("ls", (err, stdout, stderr) => {
  if(err) console.error(stderr)
  console.log(stdout)
})

const data = execSync("ls") // Outputs as buffer instead of a string
console.log(data.toString())
```

## [Debugger](#nodejs)
- Add `debugger` anywhere in your code
- Run `node --inspect ./yourScript.js`
- Go to the local ip given in the terminal