# Overloading comparison operator
- when comparing outside a class have to use public functions, so make the getters const
- the actual overload takes 2 const references of objects
- the above only matters for FUNCTIONS not methods
- methods obviously only take 1. method requires the function signature to be const

```cpp
template<typename any>
void foo(any &a, any &b){
    // stuff
}
```
- **Always** place templated classes/functions implementation in header file
- you may want to implement a specialized version of the templated function. It always takes precedence

# Multi-type Template
- what it sounds like
```cpp
template<typename T1, typename T2>
void foo(T1 var1, T2 var2){};
```

# Generic Classes

# Template argument deduction
- types must match exactly
- if passing in int and int-ref, deduced as int
- if passing in int-ref and int-pointer, deduced to int pointer
- compile error will occur if types don't match
- if the type is ever ambiguous throw error
- can fix with casting an argument, explicitly specifying type, or multi-type templates
```cpp
max(static_cast<double>(4), 7.2);
max<double>(4, 7.2);
```
- can have another type in the template which will be the return type. auto will also work as the return type
```cpp
template<typename T1, typename T2>
auto foo(T1 var1, T2 var2) -> decltype(expression){};
```

# Lambda Expressions
- anonymous functions. inline, used once
- `format`: [capture clause] (params) -> return type{def}
- can capture external variables by reference, value, or both (&, =, both)
- if you only want local variables, leave capture clause empty
- `capture clause`: capture external variables from above scope by value, reference, or mixed ([a, &b]). = or & captures all by that

# Variadic Templates
- **args but for any type(s)
- used when entering an unknown number of arguments 
- is recursive
- types are checked at compile time

```cpp
template<typename T>
T adder(T v){
    return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args){
    return first + adder(args...);
}
```
- **args are perfect forwarded via moved semantics

# Template Specialization
## Explicit
- lets you write a specific implementation for a particular combination of template parameters
- compiler will use the specialized version of a function before the general, templated version

```cpp
template<typename T>
foo();

template<>
foo<int>(int x);
```

## Partial
- for class templates, you can have partial specializations that don't have to fix all of the primary parameters
- **YOU DID NOT PAY ATTENTION. LOOK INTO THIS**

## Class
- also didn't pay attention

## Curiously Recurring Template Pattern (CRTP)
- allows to do polymorphism at compile-time
- general class of techniques that consists of passing a derived class a template argument to one of its own base classes

### Benefits
- by passing the derived class down to its base class via a template parameter, the base class can customize it's own behavior to the derived c;ass without requiring the use of virtual functions
- makes CRTP useful to factor out the implementations that can only be member functions or are dependent of the derived class's identity (eg., constructor, destructor, subscript operator)

### Application
- keeping track of how many objects of a certain type 

```cpp
template<typename Derived>
class CuriosBase{};

template<typename T>
class CuriousTemplate: public CuriousBase<CuriousTemplate>{};
```

# Project 1 Part 1
- earth + mineshaft
- player model moves and can dig
  - no out of bounds
  - may bug on windows. if does, use linux vm
- only editing Actor.h, Actor.cpp, StudentWorld.h. StudentWorld.cpp