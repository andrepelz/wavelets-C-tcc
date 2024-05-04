#ifndef __WAVELET_TRANSFORM_H__
#define __WAVELET_TRANSFORM_H__

#include "wavelet_base.h"

typedef struct WaveletTransformResult {
    double* approximation;
    double** detail;
    uint16_t depth;
    size_t original_size;
    size_t padded_size;
} DwtResult;

DwtResult wavedec(double *data, size_t size, Wavelet wavelet, uint16_t depth);
double* waverec(DwtResult data, Wavelet wavelet);

#endif