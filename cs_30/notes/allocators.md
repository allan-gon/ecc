- only takes care of memory allocation not initialization. you have to. the same is true from deallocator + destructor
- useful because you can define howmemory is being allocated
- on an embdedded system, you have very little memory to work with, so being able to decide how this happens will be extremely important

# Methods
- `allocate`: acquires space for n objects of type T
- `deallocate`: release space for n objects of type T pointed to by p
- `address`: used for obtaining the address of an object (deprecated c++20)
- `construct`: construct object (deprecated)
- `destroy`: destructs (deprecated)
- `max_size`: returns largest supported alloc size (deprecated)

- when dealing with primitive types no need to destroy (string not primitive)
