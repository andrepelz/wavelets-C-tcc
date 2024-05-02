#ifndef __WAVELET_TRANSFORM_H__
#define __WAVELET_TRANSFORM_H__

#include "wavelet_base.h"

DwtResult wavedec(double *data, size_t size, Wavelet wavelet, uint16_t depth);
double* waverec(DwtResult data, size_t size, Wavelet wavelet, uint16_t depth);

#endif