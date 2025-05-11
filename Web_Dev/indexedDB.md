[Home](../README.md#web-dev)

# IndexedDB/idb
IndexedDB is useful if you need to store large amounts of data on the client side that can quickly be retrieved.

Why use IndexedDB over local storage?
- Need to store a lot of data
- Need to store different types of data other than strings
  - Storing images
- Better CRUD operations
  - Easier to create structured data
  - Easier to query data/More query options
  - Easier to update data
  - Easier to delete data

IndexedDB is a NoSQL database that stores data in object stores in a binary format for efficiency. There is no inbuilt functionality for schemas.
- **Databases** store collections of object stores and data.
- **Object Stores** can hold multiple objects. Like containers in MongoDB.
- **Objects** are like objects in JS, but they are given a unique key to allow for easy retrieval. Like documents in MongoDB.
- **Key Paths/Primary Key** defines which one key in the objects, that are stored in an object store, should be used as the unique id. All objects in that object store need that primary key set to a unique value.
- **Indexes** are one key/property in the objects(in the object store) which allow for complex queries. Ex: In order to find all books of an author you can make an Author Index and do a getAll function.

IndexedDB allows for
- Automatic indexing
- Indexed CRUD operations are async
- Accessing data even when offline
- Structuring of data
- Allow for **transactions**
  - A sequence of CRUD operations where if one of them fails all the rest fail.
  - Ex: Moving money from account A to account B. If you cannot remove money from account A you don't want to add money to account B.

IDB is a library that makes it easier to work with indexedDB. Instead of callbacks it uses promises. `npm install idb`
- idb is cross browser compliant

<!-- TOC -->

- [Initializing DB](#initializing-db)
	- [IndexedDB initializing](#indexeddb-initializing)
	- [idb initializing](#idb-initializing)
- [CRUD Operations](#crud-operations)
	- [Seeding data](#seeding-data)
	- [IndexedDB CRUD](#indexeddb-crud)
	- [idb CRUD](#idb-crud)
- [Indexes](#indexes)
- [Cursor](#cursor)
- [Dexie.js](#dexiejs)
	- [Using dexie with react](#using-dexie-with-react)

<!-- /TOC -->

## [Initializing DB](#indexeddbidb)

### [IndexedDB initializing](#indexeddbidb)

```javascript
// Get the indexedDB which will be different depending upon the platform.
const indexedDB =
  window.indexedDB ||
  window.mozIndexedDB ||
  window.webkitIndexedDB ||
  window.msIndexedDB ||
  window.shimIndexedDB

// Open the db
const dbName = "Library"
const version = 1 // Version of indexedDB
const request = indexedDB.open(dbName, version)

// Handle error
request.onerror = function(event){
  console.error("An error occurred with IndexedDB")
  console.error(event)
}

// When a new db is created or an existing db's version number has upgraded
  // This function allows you to specify the schema of the DB
request.onupgradeneeded = function(){
  const db = request.result
  // Define a new object store in the indexedDB
  const objectStoreName = "FictionalBooks"
  const primaryKey = "ISBN"
  const fictionalBooks = db.createObjectStore(objectStoreName, { keyPath: primaryKey }) // You can have the optional ,autoIncrement: true to automatically increment the primaryKey
}
```

### [idb initializing](#indexeddbidb)

```javascript
import {openDB} from "idb"
async function initDB(){
  const dbName = "Library"
  const version = 1
  openDB(dbName, version, {
    upgrade: function(db){
      const objectStoreName = "FictionalBooks"
      // Make sure db doesn't already exist
      if(!db.objectStoreNames.contains(objectStoreName)){
        db.createObjectStore(objectStoreName, { keyPath: "ISBN"/*, autoIncrement: true*/})
      }
    }
  })
}
```

## [CRUD Operations](#indexeddbidb)

| Method Name                   | Description                                               |
|-------------------------------|-----------------------------------------------------------|
| .add(object)                  | Adds a new object to the object store.                    |
| .get(primary key)             | Gets object from the object store or index.               |
| .getAll()                     | Gets all the objects in the object store.                 |
| .put({primaryKey: 1, object}) | Replaces object with the primary key in the object store. |
| .delete(primary key)          | Deletes object with primary key.                          |
| .clear()                      | Deletes all objects in object store.                      |
| .count(query)                 | Gets the count of the query                               |
| .count()                      | Counts all objects in the object store.                   |

You can do `deleteObjectStore("objectStoreName")` to delete object stores.

### [Seeding data](#indexeddbidb)

```javascript
const data = [
  {
    ISBN: 9781234567, Title: "Book A", Author: "Author A", Genre: "Sci-Fi"
  },
  {
    ISBN: 9781234568, Title: "Book B", Author: "Author B", Genre: "Fantasy"
  },
  {
    ISBN: 9781234569, Title: "Book C", Author: "Author A", Genre: "Fantasy"
  },
]

data.forEach(book => {
  fictionalBooks.add(book) // Adds book object to the fictional books object store
})
```

### [IndexedDB CRUD](#indexeddbidb)
This is the boilerplate code needed to make any CRUD operation

```javascript
// Open the db
const request = indexedDB.open("Library", 1)

// Handle if request what successful. Opened db
request.onsuccess = function(event){
  const db = event.target.result
  // Make the transaction
  const objectStores = "FictionalBooks" // String or array of strings of object stores
  const mode = "readwrite" // "readonly", "readwrite", or "versionchange". This is optional and the default value is readonly
  const transaction = db.transaction(objectStores, mode)
  // Get object store from transaction
  const fictionalBooks = transaction.objectStore("FictionalBooks")
  // Make request for CRUD operation
  const crudRequest = fictionalBooks.getAll()
    // Handle if the request succeeded
    crudRequest.onsuccess = function(event){
      const books = event.target.result
      console.log(books)
    }
    // Close db once the request completed
    crudRequest.oncomplete = () => {
      db.close()
    }
}

// Handle if the request failed. Failed to open db
request.onerror = (event) => {
  console.error(`Error opening the database: ${event.target.error}` )
}
```

### [idb CRUD](#indexeddbidb)
This is the boilerplate code needed to make any CRUD operation

```javascript
import {openDB} from "idb"

async function crudOperation(){
  const db = await openDB("Library", 1)
  try{
    const transaction = db.transaction("FictionalBooks", "readwrite")
    const fictionalBooks = transaction.objectStore("FictionalBooks")
    const books = await fictionalBooks.getAll()
    console.log(books)
  }catch(error){
    console.error(`An error occurred with get: ${error}`)
  }finally{
    db.close()
  }
}
```

Or you can make it a function

```javascript
async function(db){
  try{
    const transaction = db.transaction("FictionalBooks", "readwrite")
    const fictionalBooks = transaction.objectStore("FictionalBooks")
    const books = await fictionalBooks.getAll()
    console.log(books)
    return transaction.complete // returns a promise
  }catch(error){
    console.error(`An error occurred with get: ${error}`)
  }
}
```

## [Indexes](#indexeddbidb)
To get more complex queries you have to use indexes.

```javascript
// Creating indexes
const indexName = "AuthorIndex"
const keys = "Author" // String or array of strings of the keys that are to be indexed
objectStore.createIndex(indexName, keys, { unique: false }) // Enforces uniqueness for any new objects added to the object store

// Getting indexes
const index = objectStore.index(indexName)

// Deleting indexes
objectStore.deleteIndex(indexName)
```

## [Cursor](#indexeddbidb)
A cursor allows you to iterate over multiple objects in an object store or index.

```javascript
// The range is optional
  // Sets the range for what the primary key can be for when the cursor moves
  let range = IDBKeyRange.bound(100/*lower*/, 200/*upper*/, false/*Optional. Inclusive lower?*/, true/*Optional. Inclusive upper?*/) // The default for inclusive lower and inclusive upper are false
  range = IDBKeyRange.lowerBound(100)
  range = IDBKeyRange.upperBound(200)
  range = IDBKeyRange.only(1) // The cursor can only move between queries where it's primary key is equal to 1
// The direction is optional
  const direction = "next" // "nextunique" which moves to the next unique object in an index, "prev", and "prevunique"
const cursor = await objectStore.openCursor(range, direction)

// Move the cursor
cursor.continue()

// Delete cursor
cursor.close()
```

## [Dexie.js](#indexeddbidb)
Dexie is a library to make working with indexedDb easier to use.

`npm install dexie`

Creating a db

```javascript
let db = new Dexie("Database name")
db.version(1).stores({
  table1: "++id,field1,field2",
  table2: "++id,field1,field2"
})
```

Creating data

```javascript
const newlyAddedObjId = await db.table1.add({
  field1: "value1",
  field1: "value2"
})
```

Reading data

```javascript
let id = 1 // Ids start at 1
let obj = await db.table1.get(id)

// or
let table1Objs = await db.table.toArray()
```

Updating data

```javascript
let id = 1
await db.table1.update(id, {
  field1: "updated value"
})

// You can update just one value at a time
```

Deleting data

```javascript
// Delete 1 obj in table
let id = 1
await db.table1.delete(1)

// Delete all objects inside table
await db.table1.clear()

// Delete table
await db.delete("table1")
```

### [Using dexie with react](#indexeddbidb)
You can have something like state in react that updates whenever the db updates.

`npm install dexie-react-hooks`

```javascript
export default function Component({db}){
  const table1 = useLiveQuery(async () => {
    return await db.table1.toArray()
  }, [/*optional dependencies*/])

  return <div>{table1}</div>
}
```

Whenever the db changes table1 gets updated like state in react.

If you are using custom awaits, awaits not associated with dexie, you have to use Promise.all in order for it to work.