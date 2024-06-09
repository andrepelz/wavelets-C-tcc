#ifndef __WAVELET_THRESHOLDING_H__
#define __WAVELET_THRESHOLDING_H__

#include "wavelet_transform.h"

#ifndef __WAVELET_THRESHOLDING_INTERNAL_H__
typedef enum { soft, hard } threshold_t;
#endif

threshold_t get_threshold(char* name);
void coeffs_apply_threshold(double* input, size_t size, double threshold, threshold_t type);
void apply_threshold(DwtResult* input, double threshold, threshold_t type);

#endif