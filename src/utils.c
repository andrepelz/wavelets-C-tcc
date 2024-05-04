#include "utils.h"
#include "utils_internal.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

double calculate_threshold(double* d1, size_t original_size, double k, double m) {
    double* abs_d1 = malloc(original_size/2*sizeof(double));

    memcpy(abs_d1, d1, original_size/2*sizeof(double));

    for(int i = 0; i < original_size/2; i++) {
        abs_d1[i] = abs(abs_d1[i]);
    }

    double median_d1 = median(abs_d1, original_size/2);

    return k*m*median_d1/0.6745*sqrt(2*log(original_size));
}

double snr(double* signal, double* noise, size_t size) {
    double signal_power_db = 10*log10(signal_power(signal, size));
    double noise_power_db = 10*log10(signal_power(noise, size));

    return signal_power_db - noise_power_db;
}

double mse(double* original_signal, double* resulting_signal, size_t size) {
    double* buffer = malloc(size*sizeof(double));
    double result;

    unsigned ceil = pow(2, 15);

    subtract(original_signal, resulting_signal, &buffer, size, ceil);
    square(buffer, &buffer, size, ceil);
    result = mean(buffer, size);

    free(buffer);

    return result;
}
