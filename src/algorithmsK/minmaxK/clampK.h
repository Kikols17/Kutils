#ifndef CLAMPK_H
#define CLAMPK_H

// This is the macro for the "CLAMPK" macro
/*
    CLAMPK(a, b, c):
        This macro returns the value of "a" clamped between "b" and "c".
        This works for all types that support the "<" and ">" operators [ ex: int, float, double, char ]
        -> a             (value to clamp)
        -> b             (minimum value)
        -> c             (maximum value)
        -> return        (the value of "a" clamped between "b" and "c")

 */

#define CLAMPK(a, b, c) ( (a<b) ? b:((a>c) ? (c:a)) )

#endif
