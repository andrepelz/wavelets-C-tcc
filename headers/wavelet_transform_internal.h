#ifndef __WAVELET_TRANSFORM_INTERNAL_H__
#define __WAVELET_TRANSFORM_INTERNAL_H__

#include "wavelet_base.h"
#include "signal_base.h"

#define DEFAULT_DWT_RESULT { NULL, NULL, 0, 0, 0 }

/**
 * @brief Função que realiza a Transformada Wavelet Direta de nível único de um sinal.
 * @param approx_in sinal de entrada da transforamda (sinal original/approximation intermediário)
 * @param approx_out vetor para armazenar coeficientes approximation de saída
 * @param detail_out vetor para armazenar coeficientes detail de saída
 * @param size tamanho do sinal de entrada
 * @param wavelet Wavelet Mãe
 */
void dwt_1L(double *approx_in, double *approx_out, double *detail_out, size_t size, Wavelet wavelet);

/**
 * @brief Função que realiza a Transformada Wavelet Inversa de nível único de um sinal.
 * @param approx_in coeficientes approximation de entrada
 * @param detail_in coeficientes detail de entrada
 * @param approx_out vetor para armazenar sinal de saída (sinal resultante/approximation intermediário)
 * @param size tamanho dos sinais de entrada
 * @param wavelet Wavelet Mãe
 */
void idwt_1L(double *approx_in, double *detail_in, double *approx_out, size_t size, Wavelet wavelet);

#endif