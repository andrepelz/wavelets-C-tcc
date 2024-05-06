#include "wavelet_thresholding_internal.h"
#include "wavelet_thresholding.h"

#include <math.h>

void coeffs_apply_threshold(double* input, size_t size, double threshold, threshold_t type) {
    thresholding_func func = get_thresholding_function(type);

    for(int i = 0; i < size; i++) {
        input[i] = (*func)(input[i], threshold);
    }
}

void apply_threshold(DwtResult* input, double threshold, threshold_t type) {
    for(int curr_depth = 0; curr_depth < input->depth; curr_depth++) {
        size_t band_size = input->original_size/pow(2, curr_depth + 1);
        
        coeffs_apply_threshold(input->detail[curr_depth], band_size, threshold, type);
    }
}