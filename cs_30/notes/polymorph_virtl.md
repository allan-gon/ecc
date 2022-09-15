# Virtual destructors
- Need when using inheritance and polymorphism
- without, object may not destroy correctly
- when inheriting, the destructor for both the intherited and the extended class must be called because the extended destructor wont be called if not virtual 

## Summary of Polymorphism
- useful because if there is a function that only work for class, all children of a will work with that function

```cpp
class Child::public BaseClass{}; 
void print(Baseclass* obj){};
BaseClass* obj = new Child();
print(obj);
```

- `Pure virtual function`: a method in an ABC which is assigned to 0
- classes are abstract when ther is atleast on epure vurtual function present
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

## Virtual Inheritance
