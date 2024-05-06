#ifndef __UTILS_H__
#define __UTILS_H__

#include <stddef.h>
#include "signal_base.h"

double calculate_threshold(double* d1, size_t original_size, double k, double m);

void add(signal_t left, signal_t right, signal_t out, size_t size);
void subtract(signal_t left, signal_t right, signal_t out, size_t size);

double snr(signal_t signal, signal_t noise, size_t size);
double mse(signal_t original_signal, signal_t resulting_signal, size_t size);

#endif
