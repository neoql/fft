#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fft.h"


#define PI 3.1415926


Complex* CreateArray(int count)
{
    int i;
    Complex *array;

    array = malloc(sizeof(Complex) * count);

    for (i = 0; i < count; i++) {
        array[i].r = sin(i * 0.1) + sin(i * 0.2);
        array[i].i = 0;
    }

    return array;
}


void Print(Complex* array, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        printf("%lf\n", mod(array[i]));
    }
}


int main()
{
    unsigned int count;
    Complex* array, *after;

    count = 128;
    array = CreateArray(count);
    after = malloc(sizeof(Complex) * count);

    fft(array, after, count);
    Print(after, count);

    free(array);
    free(after);

    return 0;
}
