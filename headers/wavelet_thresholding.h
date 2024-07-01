#ifndef __WAVELET_THRESHOLDING_H__
#define __WAVELET_THRESHOLDING_H__

#include "wavelet_transform.h"

#ifndef __WAVELET_THRESHOLDING_INTERNAL_H__
typedef enum { soft, hard } threshold_t;
#endif

/**
 * @brief Retorna um tipo de thresholding equivalente ao nome requisitado.
 * @param name nome do tipo de thresholding
 * @return threshold_t
 */
threshold_t get_threshold(char* name);

/**
 * @brief Aplica um threshold a um vetor de coeficientes.
 * @param input conjunto de coeficientes a ser limitados
 * @param size tamanho do vetor de coeficientes
 * @param threshold valor do threshold a ser aplicado
 * @param type tipo de thresholding
 */
void coeffs_apply_threshold(double* input, size_t size, double threshold, threshold_t type);

/**
 * @brief Aplica um threshold a todos os coeficientes detail de uma Transformada Wavelet.
 * @param input resultado de uma Transformada Wavelet
 * @param threshold valor do threshold a ser aplicado
 * @param type tipo de thresholding
 */
void apply_threshold(DwtResult* input, double threshold, threshold_t type);

#endif