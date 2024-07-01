#ifndef __UTILS_INTERNAL_H__
#define __UTILS_INTERNAL_H__

#include <stddef.h>
#include "signal_base.h"

/**
 * @brief Função que representa o sinal de uma amostra. Retorna -1 para valores negativos e 1 para valores positivos.
 * @param input amostra que será avaliada
 * @return int
 */
int sign(sample_t input);

/**
 * @brief Calcula a potência de um sinal.
 * @param input vetor com o sinal de interesse
 * @param size tamanho do vetor de entrada
 * @return double
 */
double signal_power(signal_t signal, size_t size);

/**
 * @brief Calcula a média das amostras de um sinal.
 * @param input vetor com o sinal de interesse
 * @param size tamanho do vetor de entrada
 * @return double
 */
double mean(double* input, size_t size);

/**
 * @brief Calcula a mediana das amostras de um sinal.
 * @param input vetor com o sinal de interesse
 * @param size tamanho do vetor de entrada
 * @return double
 */
double median(double* input, size_t size);

/**
 * @brief Calcula o quadrado amostra a amostra de um sinal.
 * @param input vetor com o sinal de interesse
 * @param output vetor para armazenar a saída normalizada
 * @param size tamanho do vetor de entrada
 */
void square(double* input, double* output, size_t size);

/**
 * @brief Normaliza um vetor com inteiros 16 bit entre os valores -1 e 1.
 * @param input vetor com o sinal de interesse
 * @param output vetor para armazenar a saída normalizada
 * @param size tamanho do vetor de entrada
 */
void normalize(signal_t input, double* output, size_t size);

#endif
