#ifndef __WAVELET_TRANSFORM_INTERNAL_H__
#define __WAVELET_TRANSFORM_INTERNAL_H__

#include "wavelet_base.h"

void step_transform(double *approx_in, double **approx_out, double **detail_out, size_t size, Wavelet wavelet);
void step_inverse_transform(double *approx_in, double *detail_in, double **approx_out, size_t size, Wavelet wavelet);

#endif