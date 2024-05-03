#include "wavelet_transform.h"
#include "wavelet_transform_internal.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

DwtResult wavedec(double *data, size_t size, Wavelet wavelet, uint16_t depth) {
    DwtResult result;
    double *approx_in = NULL, *approx_out = NULL, *detail_out = NULL;
    uint16_t curr_depth = 0;

    if(size >= 2) {
        if(size/pow(2, depth - 1) < 2) {
            printf("ERROR: Transform level provided is too deep! Please provide a smaller level\n");
            return result;
        }

        result.detail = malloc(depth*sizeof(double*));
        result.depth = depth;
        result.original_size = size;

        approx_in = malloc(size*sizeof(double));
        memcpy(approx_in, data, size*sizeof(double));

        while(size >= 2 && curr_depth < depth) {
            step_transform(approx_in, &approx_out, &detail_out, size, wavelet);

            free(approx_in);
            approx_in = approx_out;

            result.detail[curr_depth] = detail_out;

            size = size/2;
            curr_depth++;
        }

        result.approximation = approx_out;

        return result;
    } else {
        printf("ERROR: Sample size of data provided is too small! Please provide a sample of at least 2 data points\n");
        return result;
    }
}

double* waverec(DwtResult data, Wavelet wavelet) {
    double *result = NULL;
    double *approx_in = NULL, *detail_in = NULL, *approx_out = NULL;
    uint16_t curr_depth = data.depth - 1;
    size_t band_size;

    band_size = data.original_size/pow(2, data.depth);

    if(data.original_size >= 2) {
        if(band_size < 2) {
            printf("ERROR: Transform level provided is too deep! Please provide a smaller level\n");
            return NULL;
        }

        approx_in = malloc(band_size*sizeof(double));
        memcpy(approx_in, data.approximation, band_size*sizeof(double));

        while(curr_depth > 0) {
            detail_in = data.detail[curr_depth];

            step_inverse_transform(approx_in, detail_in, &approx_out, band_size, wavelet);

            free(approx_in);
            approx_in = approx_out;

            band_size = band_size*2;
            curr_depth--;
        }

        result = approx_out;

        return result;
    } else {
        printf("ERROR: Sample size of data provided is too small! Please provide a sample of at least 2 data points\n");
        return NULL;
    }
}
