[Home](../README.md)

# Smart pointers
What problem do smart pointers solve?

They are pointers, but they are smart because they handle the allocation and deallocation of the underlying heap memory they point to.

## unique_ptr
- Owns the resources exclusively
- Cannot be copied
- Deals with non-copy objects

## shared_ptr
- Shares a resource
- Reference counter to the shared resources
- Deletes the resource if the reference counter becomes 0

## weak_ptr
- Borrows the resource
- Helps break cyclic references
- Doesn't change the reference standard

## Performance
## Concurrency
## Function Arguments and Return Values