//
// Created by moons on 17-3-31.
//

#include "complex.h"


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
