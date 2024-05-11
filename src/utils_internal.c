#include "utils_internal.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

int sign(sample_t input) {
    return input >= 0 ? 1 : -1;
}

double signal_power(signal_t signal, size_t size) {
    double* buffer = malloc(size*sizeof(*buffer));
    double result;

    for(int i = 0; i < size; i++)
        buffer[i] = signal[i];

    square(buffer, buffer, size);
    result = mean(buffer, size);

    free(buffer);

    return result;
}

double mean(double* input, size_t size) {
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

double median(double* input, size_t size) {
    double result;
    double* buffer = malloc(size*sizeof(*input));
    memcpy(buffer, input, size*sizeof(*buffer));

    qsort(buffer, size, sizeof(*buffer),  _double_compare_function);

    if(size%2 == 1) {
        result = buffer[size/2];
    } else {
        result = (buffer[size/2 - 1] + buffer[size/2])/2;
    }

    free(buffer);

    return result;
}

void square(double* input, double* output, size_t size) {
    for(int i = 0; i < size; i++) {
        output[i] = input[i]*input[i];
    }
}

void normalize(signal_t input, double* output, size_t size) {
    for(int i = 0; i < size; i++) {
        double temp = (double) input[i];
        output[i] = temp/SAMPLE_MAX_VALUE;
    }
}
