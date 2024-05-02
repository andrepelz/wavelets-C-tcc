#include "wavelet_transform.h"

#include <stdio.h>
#include <math.h>

DwtResult wavedec(double *data, size_t size, Wavelet wavelet, uint16_t depth) {
    double *data_copy = malloc(size*sizeof(double));
    memcpy(data_copy, data, sizeof(size*sizeof(double)));

    DwtResult result;

    result.detail = malloc(depth*sizeof(double*));
    result.depth = depth;

    double *approx, *detail;
    uint16_t curr_depth = 0;

    approx = data_copy;

    if(size >= 2) {
        if(size/pow(2, depth - 1) < 2) {
            printf("ERROR: Transform level provided is too deep! Please provide a smaller level\n");
            return;
        }

        while(size >= 2 && curr_depth < depth) {
            step_transform(approx, size, detail);
            size = size/2;
            curr_depth++;
        }

        result.approximation = malloc(size*sizeof(double));
        memcpy(result.approximation, approx, size*sizeof(double));

        free(data_copy);

        return result;
    } else {
        printf("ERROR: Sample size of data provided is too small! Please provide a sample of at least 2 data points\n");
        return;
    }
}

double* waverec(DwtResult data, size_t size, Wavelet wavelet, uint16_t depth) {
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
