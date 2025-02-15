#ifndef MINK_H
#define MINK_H

// This is the macro for the "MINK" macro
/*
    MINK(a, b):
        This macro returns the smaller of the two numbers.
        This works for all types that support the "<" operator [ ex: int, float, double, char ]
        -> a             (first number)
        -> b             (second number)
        -> return        (the greater of the two numbers)

 */

#define MINK(a, b) (a<b ? a:b)

#endif
