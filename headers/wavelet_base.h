#ifndef __WAVELET_BASE_H__
#define __WAVELET_BASE_H__

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

typedef struct WaveletTransformResult {
    double* approximation;
    double** detail;
    uint16_t depth;
    size_t original_size;
} DwtResult;

typedef struct Wavelet {
    char* name;
    double* scaling_filter;
    double* wavelet_filter;
    uint16_t filter_size;
} Wavelet;

Wavelet get_wavelet(char* name);

#endif