# Topics
- Inheritance
  - multiple and virtual
- Exception handling
- Smart pointers
- Move semantics
  
**There will be a study guide**

Midterm  review on oct 25. Midterm oct 27

**SHOULD WATCH LECTURE VIDS**

# Review
## Exception Handling
- throwing from destructor is no good. nothing will catch a throw from destructor. is **NOT** processed. crashes the program
- can re-throw. item re-thrown des not have to be the same type as what's caught. re-throw is an idea just means throwing after you catch
- if you want to rethrown the value caught, make sure the catch includes a parameter not just the type
- catch all **must** be last or it won't compile

## Exception safety
- `No throw`: from user POV nothing happened, all handled internally
- `Strong`: if an operation fails their are no side effects. All values return to original values
- `basic`: no memory leaks but values may differ.
- `no exceptoin safety`: no guarantees

- `noexcept`: keyword used for function, class if we expect no exception t occur and if an exception does occur then we can't handle it. precedes final, override, or =0


**put exception tables in notes**

## Move semantics
- r-value vs l-value
- reference collapsing rules
  - && called `universal type`. allows us to perfectly forward l-values or r-values. so l-value in l-value out. r-value in r-value out

it's incorrect to think about r-values as unbound values right? All unbound values are r-values not all r-values are unbound (move)

**need a better look at perfect forwarding**

## Smart pointers
- `RAII`: binding life cycle of a resource to the lifetime of an object. **WTF** does that mean
- `shared_ptr`: ref count
  - `reset`: releases the resource that was acquired
- `unique_ptr`: can only have 1 reference (so use move). **are you not getting a guarantee that there is only one pointer?** only used in place of raw because auto garbage collection
- `weak_ptr`: used for circular reference
- has no ownership so to access attributes us `lock` method. lock actually returns a shared pointer which, if not assigned, is destructed

# Smart Pointers
- make sure to import memory
- making a list of shared pointers
```cpp
shared_ptr<CLASS> ptr(new CLASS[length], optional_custom_destructor);
ptr.get()[index].method();
```