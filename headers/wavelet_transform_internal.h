#ifndef __WAVELET_TRANSFORM_INTERNAL_H__
#define __WAVELET_TRANSFORM_INTERNAL_H__

#include "wavelet_base.h"
#include "signal_base.h"

#define DEFAULT_DWT_RESULT { NULL, NULL, 0, 0, 0 }

void dwt_1L(double *approx_in, double *approx_out, double *detail_out, size_t size, Wavelet wavelet);
void idwt_1L(double *approx_in, double *detail_in, double *approx_out, size_t size, Wavelet wavelet);

#endif