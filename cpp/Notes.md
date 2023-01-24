# Notes about C++

## Book: A Tour of C++

### Basic Principles

- RAII (*Resource Acquisition Is Initialization*)
  - constructor acquires all resources necessary for class to operate
  - destructor release all resources

### Headers (Covered)

<variant> - type-safe union alternative
<stdexcept> - declaration of exceptions

### Chapter 1 - Basics

- **type**: defines a set of possible values and a set of operations
- **object**: memory that holds a value of some type
- **value**: set of bits interpreted according to a type
- **variable**: named object

- if in doubt use `{}` initialization
- when using `auto` the `=` initialization can be used (no troublesome type conversion)


- Scopes
  - Local scope
  - Class cope
  - Namespace scope

- **const**: not changing value
- **constexpr**: evaluated at compile time
  - function can also be **constexpr** `constexpr double square(double x)`

  - used: array bounds, case labels, template value arguments


- range-for statement also applicable to ordinary arrays

- reference: 
  - similar to pointer, but no `*` needed to access value referred to
  - can only refer to one object

  - const reference: don't modify argument and don't copy

- **nullptr**: no value present (avoids confiusion between integers `0/NULL` and pointers)
- every test `if (cond); while (cond)` evaluates to true 

- distinction: initialization vs assignment


### Chapter 2 - User-Defined Types

- STL: contains user-defined types (types defined in terms of built-in types [arrays, ...,])

#### Structures

```
	struct Vector {
		int m_size;
		double* m_element;
	}
```

#### Classes

- set of members (functions/ type members)
- public members: define interface

- constructor is guaranteed to initialize objects of its class

- struct is a class with members public by default

#### Union

- **union** is a **struct** in which all members are allocated at the same address
  - use **variant** as alternative

#### Enumerations

- type for enumerating values
  - `enum class`: specifies that enumeration is strongly typed
  - `Color x = Color{2}`

- plain `enum` converted to int and visible in same scope as `enum`

### Chapter 3 - Modularity

- declaration and definition can be separated

- C++20: Modules

#### Namespaces

- `using` declaration makes a name from a namespace usable as if it was declared in the scope

#### Error Handling

- **throw**: transfers control to a handler for exceptions
  - unwinds call stack 
  - **catch** provides handler for exceptions

- **noexcept**: function that should never throw exception
  - if exeception thrown in `noexcept` function, `terminate()` will be called
- throw in catch-clause: rethrow exception

- `assert(condition)`: Condition that must hold during runtime
- `static_assert(cond)`: Condition that must hold at compile time

Default: **pass-by-value**
  - refer to same object -> **pass-by-reference**

- Function overloading supported

- Only **return by reference** if granting caller access to something not local to function
- Returing large amounts (e.g. matrix)
  - give object a *move constructor* then move out of function (**no pointer needed**)

- Structural binding supported

```
struct Entry {
	string name;
	int value;
}

Entry read_entry(istream& is) {
	string name;
	int value;
	is >> name >> value;
	return {name, value}
}

...

auto [n,v] = read_entry(cin);
```
**READING STOP: p. 47**
