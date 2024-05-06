#ifndef __WAVELET_THRESHOLDING_INTERNAL_H__
#define __WAVELET_THRESHOLDING_INTERNAL_H__

#include "signal_base.h"

typedef sample_t (*thresholding_func)(sample_t, double);

#ifndef __WAVELET_THRESHOLDING_H__
typedef enum { soft, hard } threshold_t;
#endif

thresholding_func get_thresholding_function(threshold_t type);

#endif