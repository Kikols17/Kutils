#ifndef MAXK_H
#define MAXK_H

// This is the macro for the "MAXK" macro
/*
    MAXK(a, b):
        This macro returns the greater of the two numbers.
        This works for all types that support the ">" operator [ ex: int, float, double, char ]
        -> a             (first number)
        -> b             (second number)
        -> return        (the greater of the two numbers)

 */

#define MAXK(a, b) (a > b ? a : b)

#endif
