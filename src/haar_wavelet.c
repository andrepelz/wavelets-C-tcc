#include "haar_wavelet.h"
#include "haar_wavelet_internal.h"
#include "wavelet_base.h"

#include <stdio.h>
#include <math.h>

double* haar_transform(double *data, size_t size, uint16_t depth) {
    double *out, *end;
    uint16_t curr_depth = 0;

    if(size >= 2) {
        if(size/pow(2, depth - 1) < 2) {
            printf("ERROR: Transform level provided is too deep! Please provide a smaller level\n");
            return NULL;
        }

        while(size >= 2 && curr_depth < depth) {
            end = data + size;
            out = haar_step_transform(data, end);
            size = size/2;
            curr_depth++;
        }

        return out;
    } else {
        printf("ERROR: Sample size of data provided is too small! Please provide a sample of at least 2 data points\n");
        return NULL;
    }
}

double* haar_inverse_transform(double *data, size_t size, uint16_t depth) {
    double *out, *end;
    size_t band_size;

    band_size = size/pow(2, depth - 1);

    if(size >= 2) {
        if(band_size < 2) {
            printf("ERROR: Transform level provided is too deep! Please provide a smaller level\n");
            return NULL;
        }

        while(band_size <= size) {
            end = data + band_size;
            out = haar_step_inverse_transform(data, end);
            band_size = band_size*2;
        }

        return out;
    } else {
        printf("ERROR: Sample size of data provided is too small! Please provide a sample of at least 2 data points\n");
        return NULL;
    }
}
