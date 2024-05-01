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

#endif