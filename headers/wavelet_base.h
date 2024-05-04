#ifndef __WAVELET_BASE_H__
#define __WAVELET_BASE_H__

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

typedef struct Wavelet {
    char* name;
    double* scaling_filter;
    double* wavelet_filter;
    size_t filter_size;
} Wavelet;

Wavelet get_wavelet(char* name);

#endif