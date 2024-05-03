#include "wavelet_base_internal.h"
#include "wavelet_transform_internal.h"

void step_transform(double *approx_in, double **approx_out, double **detail_out, size_t size, Wavelet wavelet) {
    *approx_out = malloc(size/2*sizeof(double));
    *detail_out = malloc(size/2*sizeof(double));

    double* scaling_coeffs = wavelet.dec_lo;
    double* wavelet_coeffs = wavelet.dec_hi;

    int t, j, l;

    for(t = 0; t < size/2; t++) {
        j = 2*t + 1;

        for(l = 0; l < wavelet.filter_size; l++) {
            if(j < 0) j = size - j;

            (*approx_out)[t] = scaling_coeffs[l]*approx_in[j];
            (*detail_out)[t] = wavelet_coeffs[l]*approx_in[j];

            j--;
        }
    }

    for(int i = 0; i < size/2; i++) {
        double temp = (*approx_out)[i];
        printf("%lf\t", temp);
    }

    printf("\n\n");
}

void step_inverse_transform(double *approx_in, double *detail_in, double **approx_out, size_t size, Wavelet wavelet) {
    *approx_out = malloc(2*size*sizeof(double));

    for(int i = 0; i < 2*size; i++) {
        (*approx_out)[i] = 0;
    }

    double* scaling_coeffs = wavelet.rec_lo;
    double* wavelet_coeffs = wavelet.rec_hi;

    int t, j, l;

    for(t = 0; t < 2*size; t++) {
        j = t;

        for(l = 0; l < wavelet.filter_size; l++) {
            j = j%size;

            double buffer = (j%2 == 1 ? approx_in[j/2] : 0);

            // (*approx_out)[t] = scaling_coeffs[l]*buffer + wavelet_coeffs[l]*buffer;
            buffer = scaling_coeffs[l]*buffer + wavelet_coeffs[l]*buffer;
            // buffer = scaling_coeffs[l]*buffer;
            // buffer = wavelet_coeffs[l]*buffer;
            (*approx_out)[t] += buffer;

            j++;
        }
    }

    for(int i = 0; i < 2*size; i++) {
        double temp = (*approx_out)[i];
        printf("%lf\t", temp);
    }
    
    printf("\n\n");
}
