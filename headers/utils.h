#ifndef __UTILS_H__
#define __UTILS_H__

#include <stddef.h>
#include "signal_base.h"

double calculate_threshold(signal_t d1, size_t original_size, double k, double m);

double snr(signal_t signal, signal_t noise, size_t size);
double mse(signal_t original_signal, signal_t resulting_signal, size_t size);

#endif
