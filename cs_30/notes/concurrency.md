# What is concurrency
- 2 or more independent activities happening at the same time
- we have computers with multiple cores that are capable of running more than one task in parallel. Known as `Hardware Concurrency`

# Approaches to Concurrency
## Multiple Single threaded processes
## Multiple thread s in a single process
- `thread`: a lightweight process
- independent of each other but share same address space
  - most data can be accessed from all threads

# Multithreading in C++
- include `thread`
- in main create a thread object that launches a function or set of functions
## Issues
- `race condition`: when you have multiple threads access shared memory at the same time
  - happens because threads run independent of each other
  - solution: `mutual exclusion`. When a thread executes on a section of data while preventing other threads from running their execution until it's done
    - steps: lock the data. access the data. unlock the data
- import `mutex`. create a mutex object. use the lock and unlock methods
- `deadlock`: when threads have locked memory the other running threads need. Nothing will happen ae. deadlock
  - `syncronization`
  - `hierarchy`: create a order mutex object and on instantiation pass it an int which tell sit the priority
  - `unique_lock()`: adopt_lock, defer_lock. Functions
    - ownership must be transferred between scopes
  - `atomic type`: import `atomic`. a template class you can use on any data type to make it thread safe
  - `load`: method to read
  - `store`: method to write
  - `exchange`: method to set a new value and return the previously contained value
  - `compare_exchange_STRENGTH`: weak or string. method to exchange only if the value is equal to the provided expected value. weak when looping strong for non-loops. strong always return true when the value is equal to the provided expected value. weak can fail

# Promise and future
- import `future`
- `PROMISE`: provide a value
- `FUTURE`: linked to promise. will get value when promise fulfilled
  - links by future = promise.get_future()
- move responsibility of the promise to the thread
- promise.set_value(val)
- future.get()

# Async
- did NOT pay attention to async
- will execute the task you gave it
- once you use the get function on the future, 
