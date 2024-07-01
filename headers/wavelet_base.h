#ifndef __WAVELET_BASE_H__
#define __WAVELET_BASE_H__

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

/// @brief Struct que representa uma Wavelet Mãe.
typedef struct Wavelet {
    char* name;
    double* scaling_filter;
    double* wavelet_filter;
    size_t filter_size;
} Wavelet;

/**
 * @brief Retorna uma Wavelet Mãe equivalente ao nome requisitado.
 * @param name nome da Wavelet Mãe
 * @return Wavelet
*/
Wavelet get_wavelet(char* name);

#endif