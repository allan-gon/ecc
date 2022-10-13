## Stacks
- LIFO
- used for depth first traversal
- I think `push` and `pop`

## Queues
- FIFO
- used for breadth first traversal
- I think `push` and `pop`

## Vectors
- like arrays but can shrink and grow (python list)
- values get pre-initialized/instantiated
  - in other words, strings will be empty, ints will be 0
- `push_back`: appends to end of vector **but** it reserves 50% above the list's size. This is obfuscated from you
- `at` is like `[]` but at will throw an out of bounds error where [] will try anyways and behavior is undefined
- `front` and `back`: list [0] and [-1]
- `pop_back`: pop_back speaks for itself
- can mass initialize the list

```cpp
vector<int> vals(3, 444); // size, intialized val 
```

- `empty`: returns bool
- `size`: speaks for itself
- `reserve`: reverse is more memory efficient because pushback doesn't reserve until size == capacity. push_back is greedy

## List
- doubly-linked list
- `Iteration`: 

```cpp
auto it = var.begin(); // also end, and inc with ++
// end goes 1 past so it != end
// dereference it for use
```
- iterators aren't pointers. they look and act like them (mostly) but not the same

## Map
- dict but with type
- 

# Lead for black-esque formatter
- https://stackoverflow.com/questions/841075/best-c-code-formatter-beautifier
