#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

#include "signal_base.h"
#include "wavelet_base.h"
#include "wavelet_thresholding.h"

void proto_evaluate_noise_reduction_algorithm(
    signal_t input_data, 
    signal_t noise, 
    size_t input_size,
    Wavelet wavelet,
    uint16_t depth,
    threshold_t threshold_type,
    double k,
    double m);

#endif