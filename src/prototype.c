#include <stddef.h>
#include "wavelet_base.h"
#include "wavelet_thresholding.h"
#include "utils.h"

typedef int16_t signal_t;

void proto_evaluate_noise_reduction_algorithm(
    signal_t* input_data, 
    signal_t* noise, 
    size_t input_size,
    Wavelet wavelet,
    uint16_t depth,
    threshold_t threshold_type,
    double k,
    double m) {
    signal_t* noisy_data = malloc(input_size*sizeof(*noisy_data));

    double input_mse = mse(input_data, );
    double input_snr = ;

    return;
}
