#include "wavelet_transform.h"
#include "wavelet_transform_internal.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

DwtResult wavedec(signal_t data, size_t size, Wavelet wavelet, uint16_t depth) {
    DwtResult result = DEFAULT_DWT_RESULT;
    double *approx_in = NULL;
    double *approx_out = NULL;
    double *detail_out = NULL;
    uint16_t curr_depth = 0;

    if(size >= 2) {
        if(size/pow(2, depth - 1) < 2) {
            printf("ERROR: Transform level provided is too deep! Please provide a smaller level\n");
            return result;
        }

        result.detail = malloc(depth*sizeof(*result.detail));
        result.depth = depth;
        result.original_size = size;
        
        uint16_t depth_mod_test = pow(2, depth);
        uint16_t padding = size%depth_mod_test != 0
            ? depth_mod_test - size%depth_mod_test
            : 0;

        result.padded_size = size + padding;
        size += padding;

        while(size >= 2 && curr_depth < depth) {
            approx_in = malloc(size*sizeof(*approx_in));
            approx_out = malloc(size/2*sizeof(*approx_out));
            detail_out = malloc(size/2*sizeof(*detail_out));

            if(curr_depth == 0) {
                for(int i = 0; i < size; i++) {
                    approx_in[i] = (double) data[i];
                }
            }

            step_transform(approx_in, approx_out, detail_out, size, wavelet);

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

signal_t waverec(DwtResult data, Wavelet wavelet) {
    signal_t result = NULL;
    double *approx_in = NULL;
    double *detail_in = NULL;
    double *approx_out = NULL;
    uint16_t curr_depth = data.depth;
    size_t band_size;

    band_size = data.padded_size/pow(2, data.depth);

    if(data.original_size >= 2) {
        if(band_size < 2) {
            printf("ERROR: Transform level provided is too deep! Please provide a smaller level\n");
            return NULL;
        }

        approx_in = malloc(band_size*sizeof(*approx_in));
        memcpy(approx_in, data.approximation, band_size*sizeof(*approx_in));

        while(curr_depth > 0) {
            approx_out = malloc(2*band_size*sizeof(*approx_out));
            detail_in = data.detail[curr_depth - 1];

            step_inverse_transform(approx_in, detail_in, approx_out, band_size*2, wavelet);

            free(approx_in);
            approx_in = approx_out;

            band_size = band_size*2;
            curr_depth--;
        }

        result = malloc(data.original_size*sizeof(*result));

        for(int i = 0; i < data.original_size; i++)
            result[i] = (sample_t) approx_out[i];

        return result;
    } else {
        printf("ERROR: Sample size of data provided is too small! Please provide a sample of at least 2 data points\n");
        return NULL;
    }
}
