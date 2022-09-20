# Virtual destructors
- Need when using inheritance and polymorphism
- without, object may not destroy correctly
- when inheriting, the destructor for both the inherited and the extended class must be called because the extended destructor wont be called if not virtual 

## Summary of Polymorphism
- useful because if there is a function that only work for class, all children of a will work with that function

```cpp
class Child::public BaseClass{}; 
void print(Baseclass* obj){};
BaseClass* obj = new Child();
print(obj);
```

- `Pure virtual function`: a method in an ABC which is assigned to 0
- classes are abstract when there is at least on pure virtual function present
- ABC won't compile/instantiate but children will given you redefine the pure virtual functions

# More on Inheritance
## New Keywords
### Override
- Ensures that the virtual function has the proper function name, input arguments, and return type
- if there are any inconsistencies in the function signature, a compiler error will occur
- override keyword is the the right of the function definition

### Final
- final word is used on a virtual function
- makes it so that function can't be overwritten by child classes
- if a class is final, then no one can inherit from it

## Multiple Inheritance
- one class derives from multiple base classes
- put them in a list
```cpp
class Obj3: public Obj1, public Obj2{
    // class def here
};
```
- constructor runs in declaration order
- destructor runs in reverse declaration order
- no issues when the classes are `orthogonal` (not related to each other)

### Why multiple inheritance
- want to have combinations of classes that help us solve the `fat interface problem`
- want to create interfaces that model behavior
- can use dynamic casting to figure out if an object implements a particular interface
### Implications/issues with multiple inheritance
- `the diamond problem`: when the parents of a child class inherit from the same base class
- there's an ambiguity issue. how do you know what parts of person in the child come from student/professor since student and professor inherits from person and the child inherits from student and professor
- issue: the 2 bases classes have different implementations of the same function
- issue:a inherits from b and c. let x be a b pointer of a. let y be a c pointer of a. Because of the upcasting, x knows about virtual functions in c but cant access then. Use `dynamic_cast` to cross-cast
- BUT there is a runtime cost with dynamic_cast because it adjusts the addresses

## Virtual Inheritance
- `advantage`: removes ambiguity of base sub-object, but complicates construction
- `disadvantage`: complicates the addressing
- has to be anticipated in class design
- bases classes inherit virtually from it's base class

## Run-Time Type Information (RTTI)
- TBD

# Problem
- same as before, if I'm initializing and assigning a variable for he 1wt time, the copy constructor is called, is the copy constructor only called then? My impression was if the user ever implicitly called the copy constructor it would be used therefore there is no guarantee that the assignee is empty as it could theoretically be reassigned and therefore need to be released.
- copy is for sure called when it's uninitialized and being assigned to another var

```cpp
Obj var = Obj();
Obj new_var = var;
```
- Is this the only time it's called?
- can't it be explicitly called? in which case this can happen

```cpp
Obj var = Obj();
Obj second = Obj();
second.populate();
second = Obj(var);
```
- I this can happen, then there is no grantee that second has no dynamically allocated memory in which case we have to free it. But because it could be instantiated, head may be non null even if it's not populated so crash could happen

