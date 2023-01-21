# Notes about C++

## Book: A Tour of C++

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

**CURRENT READING: p. 23**
