#ifndef __IO_HANDLING_H__
#define __IO_HANDLING_H__

#include "signal_base.h"
#include <stdlib.h>

/**
 * @brief Função que lê arquivos de áudio de entrada.
 * @param input_data vetor para armazenar sinal de voz limpa de entrada
 * @param noise_data vetor para armazenar sinal de ruído
 * @param input_filename nome do arquivo de áudio de voz limpa de entrada
 * @param noise_filename nome do arquivo de áudio de ruído
 * @param max_size tamanho máximo para os vetores de entrada
 * @return size_t
 */ 
size_t read_input_files(signal_t *input_data, signal_t *noise_data, char *input_filename, char *noise_filename, size_t max_size);

/**
 *  @brief Função que salva um sinal de saída em um arquivo de áudio WAV.
 *  @param output_data vetor armazenando sinal de saída com ruído reduzido
 *  @param output_filename nome do arquivo de áudio de voz limpa de entrada (usado para montar header WAV da saída)
 *  @param input_filename nome do arquivo de áudio de saída
 */ 
void save_output_file(signal_t output_data, char *output_filename, char* input_filename);

#endif
