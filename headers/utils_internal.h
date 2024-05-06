#ifndef __UTILS_INTERNAL_H__
#define __UTILS_INTERNAL_H__

#include <stddef.h>
#include "signal_base.h"

int sign(sample_t input);

double signal_power(signal_t signal, size_t size);

double mean(signal_t input, size_t size);
sample_t median(signal_t input, size_t size);

void square(signal_t input, signal_t out, size_t size, double ceiling);

#endif
