#ifndef __UTILS_H__
#define __UTILS_H__

#include <stddef.h>

double snr(double* signal, double* noise, size_t size);
double mse(double* original_signal, double* resulting_signal, size_t size);

#endif
