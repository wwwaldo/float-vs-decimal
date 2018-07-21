# float-vs-decimal
Checks if a decimal value has exact representation in floating point.

# Why?
32, 64-bit floating point is internally represented with base 2 instead of base 10, and this is the source of many representation errors. It can be confusing to learn about floating point arithmetic when you don't even know the true values of the floats you're adding!

The Python REPL used to do this for you, but now has smarter rounding.

# How?
It casts the input string into a float, then back again, with `std::numeric_limits<float>::max_digits10` amount of precision, and compares the result with the original.

# Compiling
Compile with clang++ or g++. You should use --std=C++11 or higher. For instance,

`g++ --std=c++11 -o float_comp floats.cpp`.

on Linux, OSX, or even Linux Subsystem for Windows.

# Example Usage
Assuming `float_comp` is on your PATH:
> >>> float_comp 1 # Exactly representible
> 1
> 1
>
> >>> float_comp 1.1 # Not exactly representable; prints closest float
> 1.1
> 1.10000002
>
> >>> float_comp 1 2 # We can handle lists!
> 1
> 1
> 2
> 2
>
> >>> float_comp 1.0 # Exactly representible, but trailing zeroes are not handled
> 1.0
> 1

The actual output is color-coded.

# To-do
If you'd like to add a suggestion, feel free to make a Pull Request. I'd be quite appreciative!
