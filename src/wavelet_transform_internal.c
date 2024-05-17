#include "wavelet_transform_internal.h"
#include <omp.h>

void step_transform(double *approx_in, double *approx_out, double *detail_out, size_t size, Wavelet wavelet) {
    for(int i = 0; i < size/2; i++) {
        approx_out[i] = 0;
        detail_out[i] = 0;
    }

    int t, j, l;

    #pragma omp parallel private(size, wavelet, j, l) shared(approx_in, approx_out, detail_out)
    {
        #pragma omp for
        for(t = 0; t < size/2; t++) {
            j = 2*t + 1;

            for(l = 0; l < wavelet.filter_size; l++) {
                if(j < 0) j = size - 1;

                approx_out[t] += wavelet.scaling_filter[l]*approx_in[j];
                detail_out[t] += wavelet.wavelet_filter[l]*approx_in[j];

                j--;
            }
        }
    }
}

void step_inverse_transform(double *approx_in, double *detail_in, double *approx_out, size_t size, Wavelet wavelet) {
    for(int i = 0; i < size; i++) {
        approx_out[i] = 0;
    }

    int t, j, l;

    #pragma omp parallel private(size, wavelet, j, l) shared(approx_in, detail_in, approx_out)
    {
        #pragma omp for
        for(t = 0; t < size/2; t++) {
            j = t;

            for(l = 0; l < wavelet.filter_size; l += 2) {
                j = j%(size/2);

                double even_approx_temp = wavelet.scaling_filter[l + 1]*approx_in[j];
                double even_detail_temp = wavelet.wavelet_filter[l + 1]*detail_in[j];
                double odd_approx_temp = wavelet.scaling_filter[l]*approx_in[j];
                double odd_detail_temp = wavelet.wavelet_filter[l]*detail_in[j];

                approx_out[2*t] += even_approx_temp + even_detail_temp;
                approx_out[2*t + 1] += odd_approx_temp + odd_detail_temp;

                j++;
            }
        }
    }
}
