# What is an exception
- runtime anomalies
- usually unexpected input or external connection outside the program is lost (database connections, network connection, file reading/writing)

# How C Deals with Exceptions
- there are no exceptions in C, instead used return codes

# Basic Structure of Exceptions in C++
- try, catch, throw, rethrow

## Throw
- `throw`: returns something, a string, integer, other
- want to be able to tell an exception or issue occurs during the running of the program (can be the raise)
- signals to the computer that a problem needs to be handled
- can throw any type in order to help us determine how to handle the exception

## Try
- try to run this code

## Catch
- after a try
- catch what's thrown so you can tell what exception was raised
- handle the problem

```cpp
try {
    // protected code
} catch (ExceptionName e) {
    // code to handle e
}
```
- `catch-all`: last catch block, will handle all exception not mentioned. but ... in catch()
- try to avoid these

# Exception Hierarchy