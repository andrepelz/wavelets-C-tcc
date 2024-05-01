#ifndef __WAVELET_BASE_INTERNAL_H__
#define __WAVELET_BASE_INTERNAL_H__

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

void split(double *out, double *end);
void interleave(double *out, double *end);
double dot_product(double *buffer, double *coefficients, size_t size);

#endif