# Template Specialization
## Explicit
- specific implementation for a particular set of parameters

## Partial
- some params are specific types some are general
- gotcha is ambiguous signature to match

## Class
- the same way you can make several templated functins with same name (specialization) you can also make classes with same name but work for diff types
- look at slides of code snippets for example

# Fragmentation
## Internal
- occurs if the payload is smaller than the block size
- has to do with memory. Application block in middle of memory block
- `cause`:
    - overhead of maintaining heap
    - padding alignment, other
## External
- occurs when there is enough aggregate heap memory, but no single free block is large enough
- there's a graphic you need to look at

# Keeping track of free blocks
## Implicit free list
- 
## Explicit Free list
- use pointer to point to the next free block
- not contiguous
- again another graphic. looks like undrstanding what structure of blocks of memory

# Concurrency
## Race Conditions
- need to make sure that memory shared betweeen threads is consistent (ae. they dont write at same time and something is overwritten)
- when 2 threads access data at same time that's a race condition
- last one wins
- pointers don't matter. last wins with orign al value
- **ASK ABOUT THIS**: how to pointers not stop this? if a set n to 100, my pointer should say it's 100
## Mutex and Locks
- to solve race cond, lock, access, and unlock
- deadlock if n threads are accessing memory and they all get what they need but later depend on what a different thread shas. because that thread has it's dependency and that thread depends on what you have, no one does anything
- solution is sequencing, lock hierarchy, or unique lock

## Async
- import thread and future
- `std::ansyc()`: takes func and args to func as params
- for output, 1 then other, ping pong from start, ping pong later, and one goes gets taken over and completes last

# Runtime of STLs
- stl's slide 34. take a picture and insert into notes

# Use STLs
- ae. iterators, put, erase
- `type<subtypes<maybemore>>::iterator`
- emplace vs push

# Re-look study guide
- be able to debug is just race condition and deadlock

# Regex
- meta charcters slide [8,10]
- outputs
- ^$ start and end
