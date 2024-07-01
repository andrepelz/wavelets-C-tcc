#ifndef __WAVELET_TRANSFORM_H__
#define __WAVELET_TRANSFORM_H__

#include "wavelet_base.h"
#include "signal_base.h"

/// @brief Struct que contém o resultado de uma Transformada Wavelet Direta.
typedef struct WaveletTransformResult {
    double* approximation;
    double** detail;
    uint16_t depth;
    size_t original_size;
    size_t padded_size;
} DwtResult;

/**
 * @brief Função que realiza a Transformada Wavelet Direta multinível de um sinal.
 * @param data vetor com sinal de entrada
 * @param size tamanho do vetor de entrada
 * @param wavelet wavelet mãe para decomposição
 * @param depth nível da Transformada Wavelet
 * @return DwtResult
 */
DwtResult wavedec(signal_t data, size_t size, Wavelet wavelet, uint16_t depth);

/**
 * @brief Função que realiza a Transformada Wavelet Inversa multinível de um sinal.
 * @param data struct com resultado de uma DWT
 * @param wavelet wavelet mãe para reconstrução
 * @return signal_t
 */
signal_t waverec(DwtResult data, Wavelet wavelet);

#endif