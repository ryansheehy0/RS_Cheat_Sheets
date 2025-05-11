[Home](../README.md#web-dev)

# NodeJS Packages

Useful npm packages

<!-- TOC -->

- [Packages](#packages)
	- [inquirer](#inquirer)
	- [express](#express)
		- [Express HTTP Methods](#express-http-methods)
		- [Parameters](#parameters)
		- [Routers](#routers)
		- [Middleware Functions](#middleware-functions)
		- [View Engines](#view-engines)
			- [Handlebars](#handlebars)
		- [Definitions](#definitions)
		- [Custom Helpers](#custom-helpers)
		- [Front end and Back end](#front-end-and-back-end)
	- [jest](#jest)
	- [mysql2](#mysql2)
		- [mysql2 with Promises](#mysql2-with-promises)
		- [Prevent SQL Injections](#prevent-sql-injections)
	- [dotenv](#dotenv)
	- [bcrypt](#bcrypt)
		- [Creating a Hash](#creating-a-hash)
		- [Comparing a Password](#comparing-a-password)
	- [tailwindcss](#tailwindcss)
	- [express-session](#express-session)
		- [Authentication](#authentication)
		- [Server Side](#server-side)
		- [Storing and Retrieving](#storing-and-retrieving)
			- [Storing data](#storing-data)
			- [Retrieving data](#retrieving-data)
		- [Destroying session](#destroying-session)
	- [cookie-parser](#cookie-parser)
	- [http-server](#http-server)

<!-- /TOC -->

## [Packages](#nodejs-packages)

| Package         | Description                                                            |
|-----------------|------------------------------------------------------------------------|
| inquirer        | Used to simply get user input from the terminal                        |
| express         | Simplifies HTTP-related tasks usually for making APIs.                 |
| jest            | Used for tests inside node.                                            |
| mysql2          | MySQL library.                                                         |
| dotenv          | Used for working with environment variables.                           |
| bcrypt          | Used to create hashes for passwords.                                   |
| tailwindcss     | Use tailwind inside nodeJS.                                            |
| express-session | Handle session which are info about the user across multiple requests. |

### [inquirer](#nodejs-packages)
Used to simply get user input from the terminal.

Use  `npm install inquirer@8.2.4` to use require with inquirer.

```javascript
const inquirer = require('inquirer')

async function askQuestion(question, answerName, validationFunction){
  // List can be an array of strings or an array of objects with name and value
  let list = [`option 1`, `option 2`, `option 3`]
  list = [
    {name: `option 1`, value: 1},
    {name: `option 2`, value: 2},
    {name: `option 3`, value: 3},
  ]
    // name is what's displayed to the user
    // value is the value that is returned if the user chooses that option
  return new Promise((resolve, reject) => {
    inquirer.prompt([
      {
        type: 'input',
        name: answerName,
        message: question,
        validate: validationFunction,
        choices: type === `list` ? list : undefined,
      }
    ])
    .then(answer => {resolve(answer)})
    .catch(error => {reject(error)})
  })
}
```

The validation function should return true if the input is valid or return an error message.

```javascript
function validationFunction(input){
  if(input === "Test"){
    return true
  }
  return `The input must be "Test"`
}
```

### [express](#nodejs-packages)
Simplifies HTTP-related tasks usually for making APIs. It's a framework for handling http requests.

```javascript
// server.js
const express = require("express")
const path = require("path")

const app = express()

// Settings
const settingName = "view engine"
const settingValue = "ejs"
app.set(settingName, settingValue)

// Middleware. Middleware functions are functions that can intercept and process incoming requests before they reach route handlers.
  // You need to parse the data because it comes in as a stream of binary data in packets that need to be constructed together
  // The content type header defines which middleware is triggered.

app.use(express.json()) // Parses the json body to an object
app.use(express.static('public')) // Setting for serving static files from the public folder. You can directly call the file. Ex: localhost:3000/images/image.jpg
  // This is needed to use js and css files in you html. To reference them the file path should be /folderInPublicFolder/file.js
app.use(express.urlencoded({ extended: true })) // Old browsers might send json through URL encoded
  // URL encoded is used to parse information sent in the URL. Ex: https://website.com/information
  // extended: true uses the "qs" library to parse the information passed in the url. This allows for more complex data structures like arrays and objects. Ex: key1=value1&key2=value2&nested[key3]=value3
  // extended: false uses the "querystring" library. This only supports simple jey value pairs. Ex: key1=value1&key2=value2

// HTTP Methods/Endpoints

// Listen
const port = process.env.PORT || 3000 // This is used when deploying on 3rd party servers. The port already defined or port 3000
app.listen(port, () => {
  // Optional function that is run when connected to the port
  console.log(`Server is running on ${port}.`)
})
```

- Always start your listening after you have defined all of your routes so the server can start with routes already defined.

#### [Express HTTP Methods](#nodejs-packages)
Making/Receiving an http method uses the format of `app.httpMethod("path", callbackFunction)`
- The path is what is after the URL. By default the path is "/".
  - Ex: https://www.rscheatsheets.com/
  - You can also make the path "*" which will catch all other terms
    - This has to be placed after other http methods or else the "*" will overwrite the other http methods.
- The callbackFunction can take the arguments of request, response, and/or nextFunction

```javascript
app.get("/", (req, res) => {
  // Gets data from the server
  console.log("Test") // Outputs to the terminal of the server
})
app.post("/", (req, res) => {
  // Creates new data in the server
  // Used for login in
  const data = req.body
})
app.put("/", (req, res) => {
  // Replaces a resource in the server
})
app.delete("/", (req, res) => {
  // Removes data in the server
})

app.patch("/", (req, res) => {
  // Changes some of the information in a resource in the server
  // This is very rarely ever used
})
//etc.
```

| Sending methods                                   | Description                                             |
|---------------------------------------------------|---------------------------------------------------------|
| res.sendStatus(statusCode)                        | Sends a HTTP status code                                |
| res.json({ message: "error"})                     | Sends json. .json only accepts an object.               |
| res.download("./fileToDownload.txt")              | Sends file to be downloaded.                            |
| res.send("html")                                  | The Content-Type header is set to text/html by default. |
| res.sendFile(path.join(__dirname, "/index.html")) | Renders html file in the browser                        |
| res.redirect('/newURL')                           | Redirects the client to a new URL.                      |
| res.end()                                         | Ends the response.                                      |

Your http methods need to return something, even an empty response, to indicate that the request was successfully handled. You can use `res.send("GET / handled successfully")`

You can change the default header type by `res.header("Content-Type", "application/javascript")`

#### [Parameters](#nodejs-packages)
Parameters are data sent through the URL. This can include regular parameters like `/api/test/${id}` or query parameters like `/api/test?id=${id}`

```javascript
// Regular parameters
app.get("/api/test/:id", (req, res) => {
  const id = req.params.id
})
```

```javascript
// Query parameters
app.get("/api/test", (req, res) => {
  const id = req.query.id
})
```

- Often times parameters are set to `.toLowerCase()` to make them case insensitive. .toLowerCase is used over .toUpperCase because it is slightly faster.

#### [Routers](#nodejs-packages)
Routers are used to help you organize your routes and the code for those routes.

In your main express file (usually server.js) you need to add:

```javascript
// In server.js. There is more to server.js
const api = require("./routes/index.js") // The exported app from index.js.

// Middleware
app.use("/api", api) // If the route uses /api it sends the endpoint to the api variable which is a separate Router in index.js.
```

```javascript
// In ./routes/index.js
const router = require("express").Router()

const tipsRouter = require("./tips") // The exported .Router() from tips.js

// Middleware
router.use("/tips", tipsRouter) // If the path is /api/tips send the endpoint to the tipsRouter

modules.exports = router
```

```javascript
// In ./routes/tips.js
const tipsRouter = require("express").Router()

tipsRouter.get("/", (req, res) => { // This path is /api/tips/
  res.send("The path is /api/tips")
})

module.exports = tipsRouter
```

#### [Middleware Functions](#nodejs-packages)

```javascript
const middleware = (req, res, next) => {
  console.log(`Middleware function: ${req.method} with the ${req.get('Content-Type')}`)
  next() // Used to call the next middleware
}

app.use(middleware)
```

Middleware functions are often used to see if the user is logged in.

```javascript
const withAuth = (req, res, next) => {
  if(!req.session.loggedIn) res.redirect("/login")
  next()
}
```

#### [View Engines](#nodejs-packages)
View engines allow you to change the html from the server before it is sent.

View engines offer ___ inside of html
- placeholders for data
- functions
- coitional rendering and looping
- text replacement

This allows you to keep your view and your controller separated.

`/views/layouts/main.handlebars` is the default location for where handlebars will look for.

##### [Handlebars](#nodejs-packages)

```javascript
const exphbs = require("express-handlebars")
const hbs = exphbs.create({})

app.engine("hbs", hbs.engine) // Sets the template engine which tells express how to render templates of a specific type
app.set("view engine", "hb") // Sets the default template engine defined in the first arg of app.engine()
  // The string is the default file extension when not specifying one. Ex. main.hbs

// Or you can use render to send data
app.get("/", (req, res) => {
  // res.render(template file path, locals)
  // You could also do res.render('template') which would make the template file template.hbs
  // locals are variables that can be put into views
  res.render('template.html', { // the file path starts from views. views/template.html
    layout: 'main', // views/layout/main.hbs will be used as default
    title: 'Title',
    name: "Ryan",
    thisCanBeAnything: "anything",
    array: ["Item 1", "Item 2", "Item 3"],
    object: {item1, item2, item3},
    boolean: true
  })
  // This will send the rendered(with handlebars) html
})
```

- If you want to use multiple template engines you can, but to use the something other than the default you have to put the exact file extension set by 'view engine'

View File Example:

{% raw %}
```HTML
<!DOCTYPE html>
<html>
    <head> <!-- Contains metadata -->
        <title>{{title}}</title>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    </head>
    <body> <!-- Contains the visible content -->
    {{#if boolean}}
      <p>Welcome {{name}}</p>
    {{else}}
      <p>No name</p>
    {{/if}}

    {{#unless boolean}} {{! if not}}
      <p>No name</p>
    {{/unless}}

    <p>I can put {{thisCanBeAnything}} into my html</p>
    {{! This is  comment}}
    <ul>
      {{#each array}}
        {{if @index 'greater' 1}} {{! Skips the fist element}}
          <li>{{this}}</li> {{! this is th current item in the loop}}
        {{/if}}
      {{/each}}
    </ul>

    {{! If you don't want to use this}}
    <ul>
      {{#each array as |item|}}
        {{if @index 'greater' 1}} {{! Skips the fist element}}
          <li>{{item}}</li> {{! this is th current item in the loop}}
        {{/if}}
      {{/each}}
    </ul>

    <p>I can also use keys in objects. {{object.item1}}</p>

    {{{ body }}} {{! This is the template}}
    </body>
</html>
```

- {{s are treated like text
- {{{s are used to rended a local arg as html

{% endraw %}

#### [Definitions](#nodejs-packages)

- **Layouts** are used to make a consistent structure for multiple pages
  - You can pass in templates into layouts by using `{{{ body }}}`
  - Put in the layouts folder in the views folder
- **Templates** contain the content unique to a particular page
- **Partials** are reusable sections of a web page
  - Put in the partials folder in the views folder
  - You can use `{{> handlebarFileName}}` to render any handlebar partial
  - The default file path starts with views/partials/handlebarFileName

Particles are placed into layouts in order to make a completed page.


#### [Custom Helpers](#nodejs-packages)

In your handlebars file: `{{custom_helper arg1}}` to use the helper function

In your helper JS file:

```javascript
module.exports = {
  custom_helper: (arg1) => {
    return arg1 // do some stuff
  }
}
```

In your server JS file where you create your engine:

```javascript
const helperJSFile = require("./utils/helpers")
const hbs = exphbs.create({helperJSFile})
```

#### [Front end and Back end](#nodejs-packages)
When using links in the font end with express you should use `/`s and then crete an express source to render that page.
### [jest](#nodejs-packages)
Used for tests inside node.

Tests are used to test your code usually before sending them towards production. Install jest as a dev package.

Tests are usually done in small units(Unit Testing) so that if one test fails then you know where some code is broken.

In your package.json add
```javascript
"script": {
  "test": "jest"
}
```

`npm test` will now run jest and thus all of your tests.

To run a test file individually you can run `npx jest --testPathPattern=./filePath/file.test.js`

In order to create tests they have to be named `fileName.test.js`

```javascript
describe("test title" () => {
  test("test description", () => {
      // JS code tests
      expect(/*Code to be run*/).toBe(/*Weather the output of expects ===(strictly equals) this code.*/)
        // or
      expect(/*Code to be run*/).toEqual(/*Checks for structural equality. Compares the contents of two objects or arrays*/)
      expect(/*object*/).toBeInstanceOf(/*Class. Checks if the object is an instance of that Class.*/)
  })
  it("test description", () => {
    // This is the same thing as test
  })
})
```

- expect is used instead of if statements to make code cleaner and less lines.
- Each test/it is run in a separate instance so if an error is thrown in one of them it will still run the other tests/its.

### [mysql2](#nodejs-packages)

```javascript
const mysql = require("mysql2")

const db = mysql.createConnection(
  {
    host: 'localhost',
    user: 'root',
    password: 'your_password',
    database: 'database_name'
  },
  console.log("Connected to the database.")
)

db.query(`SELECT * FROM table_name;`, (err, results) => {
  console.log(results)
})
```

#### [mysql2 with Promises](#nodejs-packages)

```javascript
const mysql = require("mysql2/promise")

const db = mysql.createPool(
  {
    host: 'localhost',
    user: 'root',
    password: 'your_password',
    database: 'database_name'
  },
  console.log("Connected to the database.")
)

async function asyncQuery(){
  try{
    const [results, ] = await db.query(`SELECT * FROM table_name;`)
    return results
  }catch(error){
    console.error(error)
  }
}
```

#### [Prevent SQL Injections](#nodejs-packages)
You can use the `?` in you SQL query to prevent SQL injections.

```javascript
async function unsafe(){
  const unsafeName = "' OR 1 = 1; DROP TABLE users; --" // SQL Injection
  const query = `SELECT * FROM users WHERE name = '${unsafeName}';`
  const [results, ] = await db.query(query)
  return results
}
```

```javascript
async function safe(){
  const firstName = "' OR 1 = 1; DROP TABLE users; --" // SQL Injection
  const lastName = "Sheehy"
  const query = `SELECT * FROM users WHERE first_name = ? AND last_name = ?;`
  const [results, ] = await db.query(query, [firstName, lastName])
  return results
}
```

### [dotenv](#nodejs-packages)
Used to work with environment variables so that you don't have your passwords or keys stored in plane text.

Environment variables are variables that are local on your server or computer. Usually environment variables are all capitalized.

When deploying code on a server you can set that server to have specific environment variables.

Dotenv loads environment variables from a `.env` file into `process.env`. `.env` needs to be put into `.gitignore` so that it doesn't get pushed.

```javascript
// This sets up dotenv
require("dotenv").config()

console.log(process.env.API_KEY)
```

Example of `.env` file:

```
# These are comments
API_KEY=08fe01a78943266193fc7a23625f68fa
DB_PASSWORD=password
```

### [bcrypt](#nodejs-packages)
Used to hash passwords. Bcrypt automatically creates the salt.

```javascript
const bcrypt = require('bcrypt')
```

#### [Creating a Hash](#nodejs-packages)

```javascript
const saltRounds = 14 // Number of times the hash is applied. This sets the time to make the hash
// The salt Rounds are exponential. 2^saltRounds.
  // As computational power increases the salt rounds need to increase

bcrypt.hash(`password`, saltRounds, (err, hash) => {
  if(err){
    console.error(err)
    return
  }
  console.log(`Hashed password: ${hash}`)
})

// You can also use await
let hash = await bcrypt.hash(`password`, saltRounds)

// You can also use sync
let hash = bcrypt.hashSync(`password`, saltRounds)

```

#### [Comparing a Password](#nodejs-packages)

```javascript
const hash = `$2b$07$i7vcjUJXJbczMVmbiJiQBOHEtZHk/N93Sh1H862iC9iKxVqIveihG`
// $ version of hash $ salt rounds $ 22 character salt and then 31 character hash
const password = `password`

bcrypt.compare(password, hash, (err, result) => {
  if(err){
    console.error(err)
    return
  }
  // Result is true or false
  console.log(`Is password correct? ${result}`)
})

// You can use async/await
let isPassword = await bcrypt.compare(password, hash)

// You can use sync
let isPassword = bcrypt.compareSync(password, hash)
```

### [tailwindcss](#nodejs-packages)
Tailwindcss goes through all your HTM, JS, and any other files to find which tailwind classes are being used and then creates one css file which is used.

`npm install -D tailwindcss`

1. Initialize tailwind. Creates a tailwind.config.js file
  - `npx tailwindcss init`
2. Add file extensions you want tailwindcss to search through inside tailwind.config.js

```javascript
/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ["./src/**/*.{html,js}"],
  theme: {
    extend: {},
  },
  plugins: [],
}
```

- Make sure to change `src` to yor source folder.

3. Add tailwind directives to your custom css file.
  - These directives give you special functionality with tailwind

```
@tailwind base;
@tailwind components;
@tailwind utilities;
```

4. Start tailwind-cli to build your css file
  - `npx tailwindcss -i ./css/custom.css -o ./css/tailwind.css --watch`
  - If you don't have a custom css you can run `npx tailwindcss build -o ./css/tailwind.css`
  - When the input file(./css/custom.css) changes the output file(./css/tailwind.css) with automatically update

5. Link the output file in your html
  - `<link href="./css/tailwind.css" rel="stylesheet"/>`
  - If you need to make quick changes or development it is much faster to use the CDN
    - `<script src="https://cdn.tailwindcss.com"></script>`

### [express-session](#nodejs-packages)
Express middleware which manges sessions and cookies across multiple requests.


- Local Storage and Session Storage are client side storage and used by the font end.
- Cookies are client side storage, but are used by the server. They are strings and are often used for authentication. 4kbs limit on cookies.
  - Cookies are sent in the header of any HTTP requests between the client and server
  - Cookies belong to each website. If you are on one website, but loading data from another website in that website, then a cookie from the loading website can be stored. When you load data from that website again, that website can know who you are from that cookie.
    - You visit Website A which is using Advertiser A.
      - then you load data from Advertiser A's website and gives you a cookie to identify you.
      - then Website A tells Advertiser A what products you are viewing.
    - If you go to Website B which is also using Advertiser A
      - then you load from Advertiser A which identifies you based on your cookie
      - then Advertiser A can load an ad relating to Website A
    - In order for this to work there needs to be cross origin requests. Cross origin requests are the server/website telling the client to load some data from another server/website.
- Sessions are server side storage and are unique for each client.

When a session is created a cookie with that session's id and hash is sent to the client.

#### [Authentication](#nodejs-packages)
  Sessions and cookies are used for authentication.

  Client sends username and password -> Server checks username and password in database -> Server logs in client, creates a new session(user specific data) for them, and sends a cookie with the session id to the client.

  If the user logs out the session is destroyed on the server.

#### [Server Side](#nodejs-packages)

```javascript
const session = require("express-session")

app.use(session({
  secret: "secretKey", // Required. Used to encrypt the session id to prevent others from putting in their own session id into the cookie. This should be put in the .env file.
    // The secret key is used for message authentication codes(MACs) which prevent the client from changing the message.
    // On the server: Session ID + Secret Key -> Hash
    // The client's cookie: Session ID and Hash
    // When the server receives the cookie: Cookie's Session ID + Secret Key -> Generated Hash. Compares the Generated Hash and the cookie's hash. If they match then the session ID wasn't modified. If they don't then the session id should not be used.
  cookie: { // Optional. Sets the settings for the session cookie.
    maxAge: 24 * 60 * 60 * 1000, // Expires after 1 day. In milliseconds. Sets the expiration for the session and the cookie.
    httpOnly: true, // The cookie is unaccessible to client side JavaScript. Used to prevent XSS.
    secure: false, // If true then the session is only sent over HTTPS
    sameSite: "strict" // Can the browser send cookies with cross origin requests
  }
  resave: false, // Optional. If set to false the session is saved only when modified. Setting it to true maybe useful to reset the expiration date on the session.
  saveUninitalized: false // Optional. If set to false sessions that aren't initialized aren't saved. Sessions only initialized are saved.
    // This is useful to only make sessions for users who are logged in.
}))
```

#### [Storing and Retrieving](#nodejs-packages)
express-session stores the session data in the `req.session` object which can be used inside express endpoints.

##### [Storing data](#nodejs-packages)

```javascript
app.get('/login', (req, res) => {
  // Assuming user is authenticated with the db
  req.session.username = 'john_doe';
  res.send('Logged in successfully!');
});
```

##### [Retrieving data](#nodejs-packages)

```javascript
app.get('/dashboard', (req, res) => {
  const username = req.session.username;
  if (username) {
    res.send(`Welcome, ${username}!`);
  } else {
    res.redirect('/login'); // Redirect if user is not logged in
  }
});
```

#### [Destroying session](#nodejs-packages)

```javascript
app.get('/logout', (req, res) => {
  req.session.destroy((err) => {
    if (err) {
      console.error(err);
      res.send('Error logging out');
    } else {
      res.send('Logged out successfully');
    }
  });
});
```

### [cookie-parser](#nodejs-packages)

### [http-server](#nodejs-packages)
http-server for Node.js is a simple, zero-configuration command-line HTTP server that serves static files from a specified directory.
- So that you don't have to create a express server to serve static files.