#ifndef __UTILS_INTERNAL_H__
#define __UTILS_INTERNAL_H__

#include <stddef.h>
#include "signal_base.h"

int sign(sample_t input);

double signal_power(signal_t signal, size_t size);

double mean(double* input, size_t size);
double median(double* input, size_t size);

void square(double* input, double* output, size_t size);

void normalize(signal_t input, double* output, size_t size);

#endif
