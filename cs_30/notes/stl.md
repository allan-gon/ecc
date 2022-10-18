# STLs
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
- have to overload a custom types `<` so that it's a valid key, also maybe hash function?

```cpp
map<string, int>::iterator it;
it = var.find("key");
if (if == var.end()){
  cout << "Not found\n";
  return;
}
cout << (*it)->first; // key
cout << (*it)->second; // value
```

- `erase`: looks for the key, if found delete's pair and returns iterator to next element.
-  if you erase where the iterator is pointing and it's the last element make sure to reset the iterator
- `emplace`: adds to map via insertion? Literally `[]` but exception safe and used across several stls? Apparently also more efficient because it avoid copy and move operations
- pair looks like a map but of size one. it's a struct with attribute first and second

## Set
- unique items in alphabetical order
- `insert`
- `size`
- `erase`

## In-line if
- ((cond) ? if value : else value)

## Deletion
- it = var.find(val);
- var.erase(it); // only if it != var.end()

## Iterator Gotcha
- you need to reset the iterator if
  - if you add/erase from a vector
  - if you erase the item an iterator point to
  - if you erase the last item of an STL container

# STL Algos
## Sort
- sort a list-like from [a, b)

```cpp
sort(obj.begin(), obj.end(), "optional sort func"); // lambda would looklike [](type obj1 attribute, type obj2 attribute)
```

# Lead for black-esque formatter
- https://stackoverflow.com/questions/841075/best-c-code-formatter-beautifier
