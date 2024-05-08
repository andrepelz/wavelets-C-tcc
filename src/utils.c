#include "utils.h"
#include "utils_internal.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

double calculate_threshold(double* d1, size_t original_size, double k, double m) {
    size_t d1_size = original_size/2;
    double* abs_d1 = malloc(d1_size*sizeof(*d1));

    memcpy(abs_d1, d1, d1_size*sizeof(*d1));

    for(int i = 0; i < d1_size; i++) {
        abs_d1[i] = fabs(abs_d1[i]);
    }

    double median_d1 = (double) median(abs_d1, d1_size);

    return k*m*median_d1/0.6745*sqrt(2*log(original_size));
}

void add(signal_t left, signal_t right, signal_t out, size_t size) {
    for(int i = 0; i < size; i++) {
        double temp = (double) left[i] + (double) right[i];

        temp = fabs(temp) >= SAMPLE_MAX_VALUE ? sign(temp)*SAMPLE_MAX_VALUE : temp;

        out[i] = (sample_t) temp;
    }
}

void subtract(signal_t left, signal_t right, signal_t out, size_t size) {
    for(int i = 0; i < size; i++) {
        double temp = (double) left[i] - (double) right[i];

        temp = fabs(temp) >= SAMPLE_MAX_VALUE ? sign(temp)*SAMPLE_MAX_VALUE : temp;

        out[i] = (sample_t) temp;
    }
}

double snr(signal_t signal, signal_t noise, size_t size) {
    double signal_power_db = 10*log10(signal_power(signal, size));
    double noise_power_db = 10*log10(signal_power(noise, size));

    return signal_power_db - noise_power_db;
}

double mse(signal_t original_signal, signal_t resulting_signal, size_t size) {
    signal_t original_buffer = malloc(size*sizeof(*original_buffer));
    double* double_buffer = malloc(size*sizeof(*double_buffer));
    double result;

    for(int i = 0; i < size; i++) {
        original_buffer[i] = (sample_t) original_signal[i];
    }

    subtract(original_buffer, resulting_signal, original_buffer, size);

    square(original_buffer, double_buffer, size);
    result = mean(double_buffer, size);

    free(original_buffer);
    free(double_buffer);

    return result;
}
