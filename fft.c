//
// Created by moons on 17-3-31.
//

#include "fft.h"
#include <math.h>
#include <stdlib.h>


#define PI 3.1415926


static Complex GetW(int k, int n)
{
    Complex w;

    w.r = cos(2 * PI / n * k);
    w.i = -1 * sin(2 * PI / n * k);

    return w;
}


static Complex * Rader(Complex *src, unsigned int count)
{
    unsigned int i, j, k, lv;
    Complex *dest;

    dest = malloc(sizeof(Complex) * count);

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
    return dest;
}


Complex * fft(Complex *src, unsigned int count)
{
    int i, j, k, l;
    Complex up, down, temp;
    Complex w;
    Complex *dest;

    dest = Rader(src, count);
    for (i = 0; i < log(count) / log(2); i++) {
        l = (int)pow(2, i);
        for (j = 0; j < count; j += 2 * l) {
            for (k = 0; k < l; k++) {
                w = GetW(count * k / 2 / l, count);
                temp = mul(dest[j + k + l], w);
                up = add(dest[j + k], temp);
                down = sub(dest[j + k], temp);
                dest[j + k] = up;
                dest[j + k + l] = down;
            }
        }
    }
    return dest;
}
