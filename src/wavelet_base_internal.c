#include "wavelet_base_internal.h"

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