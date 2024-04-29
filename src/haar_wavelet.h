#ifndef __HAAR_WAVELET_H__
#define __HAAR_WAVELET_H__

#include <stdint.h>
#include <stddef.h>

double* haar_transform(double *data, size_t size, uint16_t depth);
double* haar_inverse_transform(double *data, size_t size, uint16_t depth);

#endif