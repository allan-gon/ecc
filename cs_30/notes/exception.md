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
} catch (type_thrown alias) {
    // code to handle e
}
```
- `catch-all`: last catch block, will handle all exception not mentioned. but ... in catch()
- try to avoid these

# Rethrowing
- with nested error handling, you catch a problem in the inner layer and throw it again to the outer layer
- just use the word throw, you don't have to specify what's thrown. That's understood
- also works with a function within a try catch. the error rethrown from foo will be caught in main 

# Exception Hierarchy

# Standard Exceptions

- must include the `exception` library
- must pass exception by reference
- `exception`: is the parent class of al c++ exceptions
- `bad_alloc`: thrown by new
- `bad_cast`: thrown by dynamic_cast
- `runtime_error`: an exception that can't be detected by reading the code
  - `overflow`
  - `underflow`
  - `range_error`:when you store a value out of range
- `logical_error`
  - `domain_error`: invalid math domain is used
  - `invalid_arguement`: enough said
  - `out_of_range`: indexing
  - `length_error`: when a too long string is created

# Exception safety

## No Throw Guarantee
- when the exception occurs it will be handled internally and no one outside will observe it. from the users POV there was no problem

## Strong Exception safety
- in an operation fails, there will be no side effects because the data returns to the origin al values. think git rollback

## Basic Exception Safety
- No-leak guarantee. Potential memory leaks are cleaned up, but the stored data may contain different valid values than what we originally started with

## No Exception safety
- no guarantees

- `noexcept`: <- keyword, provides a no-throw guarantee to functions
- not checked at compile time
- use if confident function wont throw an error, or you don't know how to handle the error. swap should be guaranteed to not throw and error and delete won't ever throw an error

# ASK ABOUT PROBLEM ON OTHER NOTE
# **Will be asked about exception safe code on midterm**
- just think abut order and it's relation to the types of exception safety