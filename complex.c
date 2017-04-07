//
// Created by moons on 17-3-31.
//

#include "complex.h"
#include <math.h>


Complex add(Complex a, Complex b)
{
    Complex result;

    result.r = a.r + b.r;
    result.i = a.i + b.i;

    return result;
}


Complex sub(Complex a, Complex b)
{
    Complex result;

    result.r = a.r - b.r;
    result.i = a.i - b.i;

    return result;
}


Complex mul(Complex a, Complex b)
{
    Complex result;

    result.r = a.r * b.r - a.i * b.i;
    result.i = a.r * b.i + a.i * b.r;

    return result;
}


double mod(Complex x)
{
    return sqrt(x.r * x.r + x.i * x.i);
}
