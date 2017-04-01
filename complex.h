//
// Created by moons on 17-3-31.
//

#ifndef FFT_COMPLEX_H
#define FFT_COMPLEX_H


#ifdef _WIN32
#ifdef libfft_EXPORTS
#define BMP_API __declspec(dllexport)
#else
#define BMP_API __declspec(dllimport)
#endif
#else
#define FFT_API
#endif


typedef struct {
    double r;
    double i;
} Complex;


extern FFT_API Complex add(Complex a, Complex b);
extern FFT_API Complex sub(Complex a, Complex b);
extern FFT_API Complex mul(Complex a, Complex b);


#endif //FFT_COMPLEX_H
