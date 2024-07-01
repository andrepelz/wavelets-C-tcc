#ifndef __UTILS_H__
#define __UTILS_H__

#include <stddef.h>
#include "signal_base.h"

/**
 * @brief Calcula o valor de threshold para um determinado conjunto de coeficientes detail D1, k e m.
 * @param d1 coeficientes de detail de primeiro nível D1 de uma Transformada Wavelet
 * @param original_size tamanho do sinal original
 * @param k coeficiente k
 * @param m coeficiente m
 * @return double
 */
double calculate_threshold(double* d1, size_t original_size, double k, double m);

/**
 * @brief Realiza a adição amostra a amostra entre dois sinais
 * @param left vetor contendo sinal da esquerda da subtração
 * @param right vetor contendo sinal da direita da subtração
 * @param out vetor para armazenar a saída da adição
 * @param size tamanho dos vetores de entrada
 */
void add(signal_t left, signal_t right, signal_t out, size_t size);

/**
 * @brief Realiza a subtração amostra a amostra entre dois sinais
 * @param left vetor contendo sinal da esquerda da subtração
 * @param right vetor contendo sinal da direita da subtração
 * @param out vetor para armazenar a saída da subtração
 * @param size tamanho dos vetores de entrada
 */
void subtract(signal_t left, signal_t right, signal_t out, size_t size);

/**
 * @brief Calcula a SNR entre dois sinais.
 * @param signal vetor com o sinal de interesse
 * @param noise vetor com o sinal de ruído
 * @param size tamanho dos vetores de entrada
 * @return double
 */
double snr(signal_t signal, signal_t noise, size_t size);

/**
 * @brief Calcula o MSE entre dois sinais.
 * @param original_signal vetor com o sinal original
 * @param resulting_signal vetor com o sinal resultante
 * @param size tamanho dos vetores de entrada
 * @return double
 */
double mse(signal_t original_signal, signal_t resulting_signal, size_t size);

#endif
