#ifndef __UTILS_H__
#define __UTILS_H__

#include <stddef.h>

double calculate_threshold(double* d1, size_t original_size, double k, double m);

double snr(double* signal, double* noise, size_t size);
double mse(double* original_signal, double* resulting_signal, size_t size);

#endif
