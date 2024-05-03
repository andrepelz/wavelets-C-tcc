#include "wavelet_base_internal.h"
#include "wavelet_transform_internal.h"

void step_transform(double *approx_in, double **approx_out, double **detail_out, size_t size, Wavelet wavelet) {
    *approx_out = malloc(size/2*sizeof(double));
    *detail_out = malloc(size/2*sizeof(double));

    for(int i = 0; i < size/2; i++) {
        (*approx_out)[i] = 0;
    }

    for(int i = 0; i < size/2; i++) {
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
    *approx_out = malloc(2*size*sizeof(double));

    for(int i = 0; i < 2*size; i++) {
        (*approx_out)[i] = 0;
    }

    double* scaling_coeffs = wavelet.scaling_filter;
    double* wavelet_coeffs = wavelet.wavelet_filter;

    int t, j, l;

    for(t = 0; t < 2*size; t++) {
        j = t;

        for(l = 0; l < wavelet.filter_size; l++) {
            j = j%(2*size);

            double approx_buffer = wavelet.scaling_filter[l]*(j%2 == 1 ? approx_in[(j - 1)/2] : 0);
            double detail_buffer = wavelet.wavelet_filter[l]*(j%2 == 1 ? detail_in[(j - 1)/2] : 0);

            (*approx_out)[t] += approx_buffer + detail_buffer;

            j++;
        }
    }
}
