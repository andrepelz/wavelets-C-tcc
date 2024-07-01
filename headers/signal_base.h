#ifndef __SIGNAL_BASE_H__
#define __SIGNAL_BASE_H__

#include <stdint.h>

#define SAMPLE_MAX_VALUE 32767

/// @brief Tipo representando uma amostra de sinal.
typedef int16_t sample_t;
/// @brief Tipo representando um sinal.
typedef sample_t* signal_t;

#endif