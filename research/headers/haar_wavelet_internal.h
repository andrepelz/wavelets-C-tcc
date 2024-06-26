#ifndef __HAAR_WAVELET_INTERNAL_H__
#define __HAAR_WAVELET_INTERNAL_H__

#include "wavelet_base.h"

#define HAAR_SCALING_COEFS { 0.5, 0.5 }
#define HAAR_WAVELET_COEFS { 0.5, -0.5 }
#define HAAR_INVERSE_SCALING_COEFS { 1.0, 1.0 }
#define HAAR_INVERSE_WAVELET_COEFS { 1.0, -1.0 }

double* haar_step_transform(double *data, double* end);
double* haar_step_inverse_transform(double *data, double* end);

#endif