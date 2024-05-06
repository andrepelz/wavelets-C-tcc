#include "wavelet_transform_internal.h"

void step_transform(double *approx_in, double **approx_out, double **detail_out, size_t size, Wavelet wavelet) {
    *approx_out = malloc(size/2*sizeof(**approx_out));
    *detail_out = malloc(size/2*sizeof(**detail_out));

    for(int i = 0; i < size/2; i++) {
        (*approx_out)[i] = 0;
        (*detail_out)[i] = 0;
    }

    int t, j, l;

    for(t = 0; t < size/2; t++) {
        j = 2*t + 1;

        for(l = 0; l < wavelet.filter_size; l++) {
            if(j < 0) j = size - 1;

            (*approx_out)[t] += wavelet.scaling_filter[l]*approx_in[j];
            (*detail_out)[t] += wavelet.wavelet_filter[l]*approx_in[j];

            j--;
        }
    }
}

void step_inverse_transform(double *approx_in, double *detail_in, double **approx_out, size_t size, Wavelet wavelet) {
    *approx_out = malloc(size*sizeof(**approx_out));

    for(int i = 0; i < size; i++) {
        (*approx_out)[i] = 0;
    }

    int t, j, l;

    for(t = 0; t < size; t++) {
        j = t;

        for(l = 0; l < wavelet.filter_size; l++) {
            j = j%(size);

            double approx_temp = wavelet.scaling_filter[l]*(j%2 == 1 ? approx_in[(j - 1)/2] : 0);
            double detail_temp = wavelet.wavelet_filter[l]*(j%2 == 1 ? detail_in[(j - 1)/2] : 0);

            (*approx_out)[t] += approx_temp + detail_temp;

            j++;
        }
    }
}
