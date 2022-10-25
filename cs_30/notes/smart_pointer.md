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
- `use_count` method: getter for ref_count
- `reset` method: deallocates memory + sets pointer to nullptr this is **JUST** for the instance that called reset not all instances of shared_ptr
- in the example, he had 2 constructors. One for when a name is given one for when a name is not given. in the example, he creates a list of points like so:

```cpp
shared_ptr<CLASS> sp3(new CLASS[3], foo);
```
- because he's pointing to an array of pointers, he passes in a function as an argument to the constructor so that the destruction would have custom behavior

## unique_ptr
- lightweight smart pointer
- unique ownership
- again make sure to include the `memory` package
- unique function doesn't need specific function for custom deletion
- `make_unique`: 
```cpp
unique_ptr<CLASS[]> list(new CLASS[3]); // creating an array
// notice syntax between unique and shared when creating array
```
- to 'reference', use `std::move(var)`. it deletes the left, assigns to right and makes right point to nullptr

## weak_ptr
- used when there's a `cyclical reference`. when one pointer has a reference to another pointer and vice versa
- can reference a shared pointer without ownership
- use `lock` method before accessing attributes

# Move Semantics
- has to do with copying and being efficient
- addresses the issue of copying through the creation of temporary objects
- shallow copy of the rvalue us less expensive than a deep copy of the lvalue

```cpp
vector<int> createVector(){
    vector<int> x(5);
    return x;
}

int main(){
    vector<int> y = createVector();
    // lvalue       rvalue
    return 0;
}
```


### Issues: 
- the return of the vector from the called function create vector must be copied. That copy is a temporary object
- is there a way to simply reassign the vector in createVector instead of copying it?

## lvalue
- an expression whose address can be taken, a locator value
- provides a semi permanent piece of memory

## rvalue
- not an lvalue
- memory only exist temporarily
- double &

## Move copy constructor/move assignment operator
- double & and no const
- just assign the rvalue's attributes to our attributes but reinitialize the rvalue
- technically, a "shallow-copy"

## Perfect forwarding
- allows us to preserve an arguments value category (lvalue/rvalue) and const/volatile modifiers
- preformed in two steps
  - receive a universal or forward reference (&&, it will be able to figure out if it's an l or r value)
  - use `std::forward` to forward the reference
