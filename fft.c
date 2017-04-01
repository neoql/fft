//
// Created by moons on 17-3-31.
//

#include "fft.h"
#include <stdlib.h>
#include <math.h>


#define PI 3.1415926


static Complex* GetW(int count)
{
    Complex* w;
    int i;

    w = malloc(sizeof(Complex) * count);
    for (i = 0; i < count; i++) {
        w[i].r = cos(2 * PI / count * i);
        w[i].i = -1 * sin(2 * PI / count * i);
    }

    return w;
}


static void Rader(Complex *src, Complex *dest, unsigned int count)
{
    unsigned int i, j, k, lv;

    j = 0;
    for (i = 0; i < count; i++) {
		dest[i] = src[j];
		lv = 0;
        while (1) {
            k = count >> ++lv;
            if (k > j) {
                j |= k;
                break;
            }
            j -= k;
        }
    }
}


void fft(Complex *src, Complex *dest, unsigned int count)
{
    int i, j, k, l;
    Complex up, down, temp;
    Complex* w;

    w = GetW(count);

    Rader(src, dest, count);
    for (i = 0; i < log(count) / log(2); i++) {
        l = (int)pow(2, i);
        for (j = 0; j < count; j += 2 * l) {
            for (k = 0; k < l; k++) {
                temp = mul(dest[j + k + l], w[count * k / 2 / l]);
                up = add(dest[j + k], temp);
                down = sub(dest[j + k], temp);
                dest[j + k] = up;
                dest[j + k + l] = down;
            }
        }
    }
    free(w);
}
