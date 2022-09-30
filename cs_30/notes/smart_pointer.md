# Problem with raw pointers
- if an exception is thrown after memory is allocated, memory will never be deallocated

# Resource Acquisition is Initialization (RAII)
- tech that binds life cycle of a resource that must be acquired before the use to the lifetime of an object

# Types of smart pointers

## shared_ptr
```cpp
shared_ptr<CLASS> sp = new CLASS;
// is equivalent to the better way
auto sp = make_shared<CLASS>();
```
- gives us a pointer that counts the number of references to a particular piece of memory
- helps with exception safety
- one memory allocation instead of two
- has a `ref_count` which tells you how many shared_ptrs point to an object
- `use_cout` method: getter for ref_count
- `reset` method: deallocates memory + sets pointer to nullptr this is **JUST** for the instance that called reset not all instances of shared_ptr
- 

## unique_ptr
- 
## weak_ptr

if that's a shared_ptr, are unique pointer how rust implements borrowing. because a unique pointer enforces the fact that it can only have 1 reference