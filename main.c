#include <stdio.h>
#include <stdlib.h>
#include "fft.h"


Complex* CreateSinArray(int count)
{
    int i;
    Complex *array;

    array = malloc(sizeof(Complex) * count);

    for (i = 0; i < count; i++) {
        array[i].r = i * 0.1;
        array[i].i = 0;
    }

    return array;
}


void Print(Complex* array, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        printf("%lf\n", array[i].r);
    }
}


int main()
{
    int count;
    Complex* array, *after;

    count = 8;
    array = CreateSinArray(count);
    after = malloc(sizeof(Complex) * count);

    fft(array, after, count);
    Print(after, count);

    free(array);
    free(after);

    return 0;
}