#include "wavelet_thresholding_internal.h"

#include "utils_internal.h"
#include <stdlib.h>

sample_t hard_thresholding(sample_t input, double threshold) {
    return abs(input) > threshold ? input : 0;
}

sample_t soft_thresholding(sample_t input, double threshold) {
    return abs(input) > threshold ? input - sign(input)*threshold : 0;
}

thresholding_func get_thresholding_function(threshold_t type) {
    if(hard == type) {
        return &hard_thresholding;
    }

    if(soft == type) {
        return &soft_thresholding;
    }

    return NULL;
}
