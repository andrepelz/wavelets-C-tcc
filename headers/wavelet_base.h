#ifndef __WAVELET_BASE_H__
#define __WAVELET_BASE_H__

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

typedef struct WaveletTransformResult {
    double* approximation;
    double** detail;
    uint16_t depth;
} DwtResult;

typedef struct Wavelet {
    char* name;
    double* dec_lo;
    double* dec_hi;
    double* rec_lo;
    double* rec_hi;
    uint16_t filter_size;
} Wavelet;

Wavelet wavelet(char* name);

#endif