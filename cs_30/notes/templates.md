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

# Generic Classes