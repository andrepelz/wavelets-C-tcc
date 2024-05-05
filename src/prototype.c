#include <stddef.h>
#include "wavelet_base.h"
#include "wavelet_thresholding.h"

void proto_evaluate_noise_reduction_algorithm(
    double* input_data, 
    double* noise, 
    size_t input_size,
    Wavelet wavelet,
    uint16_t depth,
    threshold_t threshold_type,
    double k,
    double m) {
    double* noisy_data = malloc(input_size*sizeof());

    return;
}
