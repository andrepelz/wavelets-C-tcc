#include "wavelets_internal.h"

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
    
    return out;
}

void split(double *out, double *end) {
    size_t size = (end - out);
    double *left = malloc(size/2*sizeof(*out));
    double *right = malloc(size/2*sizeof(*out));
    double *ptr;

    double *iter_left = left;
    double *iter_right = right;

    for(ptr = out; ptr < end; ptr += 2) {
        *iter_left++ = *ptr;
        *iter_right++ = *(ptr + 1);
    }

    iter_left = left;
    iter_right = right;

    for(ptr = out; (ptr + size/2) != end; ptr++) {
        *ptr = *iter_left++;
        *(ptr + size/2) = *iter_right++;
    }

    free(left);
    free(right);
}

void interleave(double *out, double *end) {
    size_t size = (end - out);
    double *left = malloc(size/2*sizeof(*out));
    double *right = malloc(size/2*sizeof(*out));
    double *ptr = out;

    double *iter_left = left;
    double *iter_right = right;

    for( ; (ptr + size/2) != end; ptr++) {
        *iter_left++ = *ptr;
        *iter_right++ = *(ptr + size/2);
    }

    iter_left = left;
    iter_right = right;

    for(ptr = out; ptr < end; ptr += 2) {
        *ptr = *iter_left++;
        *(ptr + 1) = *iter_right++;
    }

    free(left);
    free(right);
}

double dot_product(double *buffer, double *coefficients, size_t size) {
    double sum = 0;

    for(int i = 0; i < size; i++)
        sum += buffer[i]*coefficients[i];
    
    return sum;
}
