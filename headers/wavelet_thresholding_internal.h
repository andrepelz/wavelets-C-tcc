#ifndef __WAVELET_THRESHOLDING_INTERNAL_H__
#define __WAVELET_THRESHOLDING_INTERNAL_H__

#include "signal_base.h"

/// @brief Alias para função de thresholding.
typedef double (*thresholding_func)(double, double);

#ifndef __WAVELET_THRESHOLDING_H__
typedef enum { soft, hard } threshold_t;
#endif

/** 
 * @brief Retorna uma função de thresholding equivalente ao tipo requisitado.
 * @param type tipo de thresholding
 * @return thresholding_func
*/
thresholding_func get_thresholding_function(threshold_t type);

#endif