#ifndef CLAMPK_H
#define CLAMPK_H

// This is the macro for the "CLAMPK" macro
/*
    CLAMPK(a, min, max):
        This macro returns the value of "a" clamped between "min" and "max".
        This works for all types that support the "<" and ">" operators [ ex: int, float, double, char ]
        -> a             (value to clamp)
        -> min           (minimum value)
        -> max           (maximum value)
        -> return        (the value of "a" clamped between "min" and "max")


    CLAMPMAXK(a, max):
        This macro returns the value of "a" clamped between "-infinity" and "max".
        This works for all types that support the "<" operator [ ex: int, float, double, char ]
        -> a             (value to clamp)
        -> max           (maximum value)
        -> return        (the value of "a" clamped between "-infinity" and "max")


    CLAMPMINK(a, min):
        This macro returns the value of "a" clamped between "min" and "+infinity".
        This works for all types that support the ">" operator [ ex: int, float, double, char ]
        -> a             (value to clamp)
        -> min           (minimum value)
        -> return        (the value of "a" clamped between "min" and "+infinity")

 */

#define CLAMPK(a, min, max) ( a<min ? min:(a>max ? max:a) )
#define CLAMPMAXK(a, max) ( a>max ? max:a )
#define CLAMPMINK(a, min) ( a<min ? min:a )

#endif
