#include "wavelet_base_internal.h"
#include "haar_wavelet_internal.h"

double* haar_step_transform(double *data, double* end) {
    double *out = data;
    double *even = data;
    double *odd = data + 1;
    double *buffer = malloc( 2*sizeof(*data) );

    double scaling_coefs[2] = HAAR_SCALING_COEFS;
    double wavelet_coefs[2] = HAAR_WAVELET_COEFS;

    for( ; data != end && (data + 1) != end; data += 2) {
        for(int i = 0; i < 2; i++)
            buffer[i] = *(data + i);
        
        *even = dot_product(buffer, scaling_coefs, 2);
        *odd = dot_product(buffer, wavelet_coefs, 2);

        even += 2;
        odd += 2;
    }

    split(out, end);

    free(buffer);

    for(double *iter = out; iter != end - (end - out)/2; iter++) {
        printf("%lf\t", *iter);
    }

    printf("\n\n");

    return out;
}

double* haar_step_inverse_transform(double *data, double* end) {
    double *out = data;
    double *even = data;
    double *odd = data + 1;
    double *buffer = malloc( 2*sizeof(*data) );

    double scaling_coefs[2] = HAAR_INVERSE_SCALING_COEFS;
    double wavelet_coefs[2] = HAAR_INVERSE_WAVELET_COEFS;

    interleave(out, end);

    for( ; data != end && (data + 1) != end; data += 2) {
        for(int i = 0; i < 2; i++)
            buffer[i] = *(data + i);
        
        *even = dot_product(buffer, scaling_coefs, 2);
        *odd = dot_product(buffer, wavelet_coefs, 2);

        even += 2;
        odd += 2;
    }
    
    free(buffer);

    for(double *iter = out; iter != end; iter++) {
        printf("%lf\t", *iter);
    }

    printf("\n\n");
    
    return out;
}
