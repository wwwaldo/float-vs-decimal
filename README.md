# float-vs-decimal
Checks if a decimal value has exact representation in floating point (well, to machine epsilon, anyway).

# Why?
32, 64-bit floating point is internally represented with base 2 instead of base 10, and this is the source of many representation errors. It can be confusing to learn about floating point arithmetic when you don't even know the true values of the floats you're adding!

# How?
It casts the input string into a float, then back again, with `std::numeric_limits<float>::max_digits10` amount of precision, and compares the result with the original.

# Compiling
Run the `install.sh` script in the terminal from the project directory, e.g. with `./install.sh`.

You should have `g++` installed.

# Example Usage
Assuming `float-vs-decimal` is on your PATH:

    >>> float-vs-decimal 1 # Exactly representible
    1
    1

    >>> float-vs-decimal 1.1 # Not exactly representable; prints closest float
    1.1
    1.10000002
    
    >>> float-vs-decimal 1 2 # We can handle lists!
    1
    1
    2
    2

    >>> float-vs-decimal 1.0 # Exactly representible, but trailing zeroes are not handled
    1.0
    1

    >>> float-vs-decimal --double 1.1 # handle double precision
    1.1
    1.1000000000000001 

The actual output is color-coded.

# TODO 
If you'd like to add a suggestion, feel free to make an issue/pull request.
