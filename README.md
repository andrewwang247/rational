# Rational Numbers

Exact representation of rational numbers. Extends the compile-time standard library utility `std::ratio` to be usable at run-time and adds greater functionality.

Every function in the API is [unit tested](test.cpp), which can be executed with the included [Makefile](Makefile).

## Invariants

- The numerator and denominator are stored in `std::int64_t`.
- The denominator is always positive, regardless of sign.
- The numerator and denominator will be reduced such that they are co-prime.

## Functionality

See [header file](rational.h) for full API. Briefly, the following operations are supported:
- Construction via whole number or by specifying numerator and denominator.
- Getters for numerator and denominator as well as the closest `double` approximation to the rational.
- Unary `+` and `-` yield the absolute value and opposite sign, respectively.
- Addition, subtraction, multiplication, and division.
- Increment and decrement by one.
- Equality and comparison operators.
- Stream insertion for writing as output.
