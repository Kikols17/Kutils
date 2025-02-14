#ifndef MINMAXK_H
#define MINMAXK_H

// This is the macro for the "MINMAXK" macro
/*
    MINMAXK(a, b):
        This macro returns the smaller and greater of the two numbers.
        This works for all types that support the "<" and ">" operators [ ex: int, float, double, char ]
        -> a             (first number)
        -> b             (second number)
        -> min           (variable where to store the smallest of the two numbers)
        -> max           (variable where to store the greater of the two numbers)

 */

#define MINMAXK(a, b, min, max) (min = (a<b)?(a:b), max = (a>b)?(a:b))

#endif
