#include "utils_internal.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

int sign(sample_t input) {
    return input >= 0 ? 1 : -1;
}

double signal_power(signal_t signal, size_t size) {
    signal_t buffer = malloc(size*sizeof(*buffer));
    double result;

    for(int i = 0; i < size; i++) {
        buffer[i] = (double) signal[i];
    }

    unsigned ceil = pow(2, 15);

    square(buffer, buffer, size, ceil);
    result = mean(buffer, size);

    free(buffer);

    return result;
}

double mean(signal_t input, size_t size) {
    double sum = 0;

    for(int i = 0; i < size; i++) {
        sum += input[i];
    }

    return sum/size;
}

int _double_compare_function(const void *a,const void *b) {
    double *x = (double *) a;
    double *y = (double *) b;

    if (*x < *y) return -1;
    else if (*x > *y) return 1;
    return 0;
}

int _int_compare_function(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;

    return *x - *y;
}

sample_t median(signal_t input, size_t size) {
    sample_t result;
    signal_t buffer = malloc(size*sizeof(*input));
    memcpy(buffer, input, size*sizeof(*buffer));

    qsort(buffer, size, sizeof(*buffer),  sample_compare_function);

    if(size%2 == 1) {
        result = buffer[size/2];
    } else {
        result = (buffer[size/2 - 1] + buffer[size/2])/2;
    }

    free(buffer);

    return result;
}

void square(signal_t input, signal_t out, size_t size, double ceiling) {
    for(int i = 0; i < size; i++) {
        double temp = input[i]*input[i];

        temp = abs(temp) >= ceiling ? sign(temp)*(ceiling - 1) : temp;

        out[i] = (sample_t) temp;
    }
}
