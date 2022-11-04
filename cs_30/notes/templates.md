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
- 

# Variadic Templates

# Template explicit specialization
