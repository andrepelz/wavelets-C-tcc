#include "wavelet_thresholding_internal.h"

#include "utils_internal.h"
#include <stdlib.h>

double hard_thresholding(double input, double threshold) {
    return fabs(input) > threshold ? input : 0;
}

double soft_thresholding(double input, double threshold) {
    return fabs(input) > threshold ? input - sign(input)*threshold : 0;
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
