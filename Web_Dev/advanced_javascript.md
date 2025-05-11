[Home](../README.md#web-dev)

# Advanced JavaScript
Javascript is single threaded language. The thread has a call stack and memory heap. This cheat sheet goes through how those things work and other things on how javascript works under the hood.

<!-- TOC -->

- [LIFO/FIFO](#lifofifo)
- [Call Stack](#call-stack)
	- [Example 1](#example-1)
	- [Example 2](#example-2)
- [Callback Queue and Event Loop](#callback-queue-and-event-loop)
- [Global and Function Execution Context](#global-and-function-execution-context)
- [Use Strick](#use-strick)
- [Useful terms](#useful-terms)
- [Closures](#closures)
	- [Var/Let trick question](#varlet-trick-question)
- [Big O Notation](#big-o-notation)
- [Progressive Web Apps PWAs](#progressive-web-apps-pwas)
	- [Manifest](#manifest)
	- [Service worker](#service-worker)
		- [Push notifications](#push-notifications)
	- [Importing and Exporting](#importing-and-exporting)
- [Lighthouse](#lighthouse)
- [Client-Server Folder Layout](#client-server-folder-layout)

<!-- /TOC -->

## [LIFO/FIFO](#javascript-under-the-hood)
**LIFO** - Last in first out.
- The last thing added is going to be the first thing out.
- Like a stack of plates where you take one from the top.

**FIFO** - First in first out.
- The first thing added is going to be the first thing out.
- Like a queue of people. The person who was first in line gets pulled out first.

## [Call Stack](#javascript-under-the-hood)
The call stack is LIFO and is a list of functions that need to be ran. The bottom is always the Global Execution Context.

### [Example 1](#javascript-under-the-hood)

```javascript
function first(){console.log("first")}
function second(){console.log("second")}
function third(){console.log("third")}

first()
second()
third()
```

```
         | Call Stack |
---------|------------|---------
third -> | second     | -> first
         | Global EV  |
```

### [Example 2](#javascript-under-the-hood)
When you have functions inside functions it is added to the call stack.

```javascript
function first(){
  console.log("first")
  second()
}

function second(){
  console.log("second")
  third()
}

function third(){
  console.log("third")
}

first()
```

| Call Stack |
|------------|
| third      |
| second     |
| first      |
| Global EC  |

## [Callback Queue and Event Loop](#javascript-under-the-hood)
[This](https://www.youtube.com/watch?v=8aGhZQkoFbQ&list=WL&index=3) is a good resource.

When an `async` function is called it runs synchronously like any other function. If an `await` is encountered, it passes the code to the webAPI or the NodeAPI.

The webAPIs or the NodeAPIs run in a different threads and are called when async operations need to be performed.

When the async operation finishes, like the timer in `setTimeout` or `fetch` gets back data, the callback function(with async, the code after the await) is added to the callback queue.

The event loop checks if the callback stack is empty. If it is empty it checks for the next callback function in the event queue. It then puts that function in the callback stack.

The synchronous functions always have higher priority than any function in the callback queue.

## [Global and Function Execution Context](#javascript-under-the-hood)
The global execution context is the outermost scope in JS.

The function execution context is created when a function is invoked and variables declared in the function can only be used in the function.

## [Use Strick](#javascript-under-the-hood)
Use strick is used to convert bad syntax to errors.

To use use strick you can either put `"use strick"` at the top of your js file or put `"use strick"` at the top of functions to just use strick for that function.

- Can't use un-declared variables.
  - You have ot first create a variable with var, const, or let
- You can't delete a variable
  - Ex: `const x = 5; delete x;` will throw an error
- No duplicate argument names in functions
- `this` is undefined for functions that aren't methods
- Can't use `with` or `eval` keyword

## [Useful terms](#javascript-under-the-hood)

| Term                   | Definition                                  |
|------------------------|---------------------------------------------|
| Higher order functions | Functions with other functions as arguments |
| Shallow copy           | Pass by reference                           |
| Deep copy              | Pass by value                               |
| Lexical Environnement  |                                             |

## [Closures](#javascript-under-the-hood)
Closures are functions that are returned from another function, that allow you to access private variables in the outer function.

When a function is returned a closure, in the backend, is made which holds the private variables.

```javascript
function bankAccount() {
  const checking = 400
  const savings = 1000

  return {
    displayFunds: function () {
      console.log(`You have $${checking} in your checking account and $${savings} in your savings account`)
    },
  }
}
```

Factory functions are like closures, but are given arguments.

### [Var/Let trick question](#javascript-under-the-hood)

```javascript
// var is scoped to the global scope therefore it doesn't change closures
// If i were let it would be scoped to the for loop and would have its own closure.
  // If it was let it would be 0, 1, 2
for(var i = 0; i < 3; i++){
  const log = () => {
    consol.log(i)
  }

  setTimeout(log, 100)
}

// This will output 3 3 3
```

## [Big O Notation](#javascript-under-the-hood)
Because an increasingly complex computer can run any algorithm faster, in order to compare algorithms we use a standard notation called Big O Notation.

Big O Notation removes any constants and only accounts for the number of inputs so you don't have to worry about different computers.

Big O notation uses the syntax of O().

This is the efficiency in order of worst to best when n is very large.
  - O(n!), O(2^n), O(n^2), O(n log n), O(n), O(log n), O(1)

The Big O of a for loop is O(n)

The Big O of a nested for loop in another for loop is O(n^2)

Big O notation is always the worst case scenario

## [Progressive Web Apps (PWAs)](#javascript-under-the-hood)
A progressive web app(PWA) is a web application that performs like a native app.
- Installable on the device
  - Run in a headless browser
- Can work offline
- Can have a splash screen
- Needs to run over HTTPS
- Assets are downloaded and bundled which often leads to faster performance.
- Has access to device specific API features
  - Push notifications
  - Bluetooth
  - File system Access
  - Geolocation
  - Clipboard
  - There maybe device features not allowed for PWAs

Need to research
- service worker
  - Thread that works in the background. Caching, background sync, push notifications.
- client side database
- userAgent
- indexedDB

When you code for a PWAs you need to check if a feature is there in order to use it.

This is js on the front end.

```javascript
// Note: window.navigator. is the same as navigator.
if("serviceWorker" in navigator){}
if("bluetooth" in navigator){}
if("geolocation" in navigator){
  navigator.geolocation.getCurrentPosition()
}
if("contacts" in navigator && "ContactsManager" in window){
  const props = ["name", "email", "tel", "address", "icon"]
  const opts = {multiple: true} // Allows selecting multiple contacts
  const contacts = await navigator.contacts.select(props, opts)
}
// etc
```

### [Manifest](#javascript-under-the-hood)
Meta data and settings for the PWA.

https://developer.mozilla.org/en-US/docs/Web/Manifest/

The only settings that are required are name and short_name

```javascript
{
  "name": "Web App Name",
  "short_name": "name", // Name on the device home screen or app launcher
  "description": "The description of the web app.",
  "start_url": "/", // Specifies the starting url path when the PWA is launched. Ex: "start_url": "/home" will be https://yourwebsite.com/home
  "icons": [
    {
      "src": "icons/icon-32.png",
      "sizes": "32x32",
      "type": "image/png"
    },
    // More icons
    // SVG icon
  ],
  "orientation": "portrait", // default orientation for the PWA
  "display": "standalone", // fullscreen(Puts the webapp in fullscreen like a video), standalone(standalone app), minimal-ui(mini ui for controlling navigation), browser(normal browser tab)
  "theme_color": "#4285F4", // The ui color theme of the browser
  "background_color": "#FFFFFF", // Sets the background color of the splash screen
}
```

You have to link the manifest file in your html

`<link rel="manifest" href="/manifest.json">`

You can put the manifest file in the `webpack.config.js` with `npm install webpack-pwa-manifest --save-dev`

```javascript
const WebpackPwaManifest = require('webpack-pwa-manifest')
// Put in the plugins array
  new WebpackPwaManifest({
    name: "Just Another Text Editor",
    // More manifest fields
  })
```

### [Service worker](#javascript-under-the-hood)
The service worker is a separate thread that runs in the background which allows for offline functionality, push notification, and background synchronization(app keeps running even if its not on the screen).

The 3 steps for service worker.
- Install
- Activate
- Claim

In your main js file

```javascript
// Register the service worker
if ('serviceWorker' in navigator) {
  navigator.serviceWorker.register('/service-worker.js')
    .then(registration => {
      console.log(`Service Worker registered: ${registration}`)
    })
    .catch(error => {
      console.error(`Error registering Service Worker: ${error}`)
    })
}
```

In your service-worker.js file in the client

This can all be automatically generated by `workbox-webpack-plugin`

```javascript
const cacheName = "my-cache-name"

// Install the service worker. Cache the files
self.addEventListener('install', event => {
  event.waitUntil(
    caches.open(cacheName).then(cache => {
      return cache.addAll([ // The files built by webpack
        '/',
        '/index.html',
        '/bundle.js',
        '/images/logo.png'
      ])
    })
  )
})

// Activate the service worker. Used to clean up past caches
self.addEventListener("activate", (event) =>
  event.waitUntil(
    caches.keys().then((keyList) =>
      Promise.all(
        keyList.map((key) => {
          if (key !== cacheName) {
            return caches.delete(key)
          }
        })
      )
    )
  )
)

// Claim the service worker so the service worker intercepts requests to other servers
  // Server/Websites -> Service worker -> Client's webpage
self.addEventListener("activate", (event) => {
  event.waitUntil(clients.claim())
})

// When a request is fetched
self.addEventListener("fetch", event => {
  event.respondWith((async () => {
    // Check if resource is cached and if so return cache
    const result = await caches.match(event.request)
    if(result) return result
    // If not, retrieve the resource
    const response = await fetch(event.request)
      // Cache it, and then return it. You may not want this
        // const cache = await caches.open(cacheName)
        // cache.put(event.request, response.clone())
    return response
  })())
})
```

#### [Push notifications](#javascript-under-the-hood)

### [Importing and Exporting](#javascript-under-the-hood)

```javascript
// You can either import the defaulted export(without the {}s) or just the exported value(with the {}s)
import defaultExport from "npmPackage"
import {regularExport} from "./javascriptFile"
import {obj: {key1, key2}} from "./anotherJSFile" // dereferencing an object inside an export
import "jsFile" // This will just run the jsFile.
import defaultExport as anotherDefaultName, {regularExport as anotherName} from "./javascriptFile" // Importing as a different name

// In separate files
export default function defaultThing(){console.log("default export")}
export function regularExport(){console.log("regular export")}
export const obj ={
  key1: "value1",
  key2: "value2"
}
```

## [Lighthouse](#javascript-under-the-hood)
Test the performance, accessability, SEO, and other things for your web app.

Inspect element and Lighthouse tab.

## [Client-Server Folder Layout](#javascript-under-the-hood)
You want to separate the package.json/dependencies into separate client and server side for organization reasons.

```
client
  - uses webpack
  - dist
  - src
  - package.json
server
  - uses express
  - package.json
package.json
```

In your express server add `app.use(express.static("../client/dist"))` in order to load the webpack built files which are usually in the dist folder inside client.

In the main package.json file

Scripts

```javascript
{
  "name": "Project Name",
  "version": "1.0.0",
  "main": "index.js",
  "license": "MIT",
  "scripts": {
    "start:dev": "concurrently \"cd client && npm run build\" \"cd server && npm run server\" ",
    "start": "npm run build && cd server && node server.js",
    "server": "cd server node server.js --ignore client",
    "build": "cd client && npm run build",
    "install": "cd server && npm i && cd ../client && npm i",
    "client": "cd client && npm start"
  },
  "devDependencies": {
    "concurrently": "^5.2.0"
  }
}
```

Run `npm run start`