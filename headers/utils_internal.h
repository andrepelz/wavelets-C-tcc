#ifndef __UTILS_INTERNAL_H__
#define __UTILS_INTERNAL_H__

#include <stddef.h>

int sign(double input);

double signal_power(double* signal, size_t size);

double mean(double* input, size_t size);
double median(double* input, size_t size);

void add(double* left, double* right, double** out, size_t size, double ceiling);
void subtract(double* left, double* right, double** out, size_t size, double ceiling);

void square(double* input, double** out, size_t size, double ceiling);

#endif
