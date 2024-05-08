#include "prototype.h"

#include <stdio.h>
#include "utils.h"

void proto_evaluate_noise_reduction_algorithm(
    signal_t input_data, 
    signal_t noise, 
    size_t input_size,
    Wavelet wavelet,
    uint16_t depth,
    threshold_t threshold_type,
    double k,
    double m) {
    signal_t noisy_data = malloc(input_size*sizeof(*noisy_data));
    add(input_data, noise, noisy_data, input_size);

    double input_mse = mse(input_data, noisy_data, input_size);
    double input_snr = snr(input_data, noise, input_size);

    DwtResult transform = wavedec(noisy_data, input_size, wavelet, depth);

    double *coefficients_d1 = transform.detail[0];
    double threshold = calculate_threshold(coefficients_d1, input_size, k, m);
    apply_threshold(&transform, threshold, threshold_type);

    signal_t output_data = waverec(transform, wavelet);

    signal_t remaining_noise = malloc(input_size*sizeof(*remaining_noise));
    subtract(output_data, input_data, remaining_noise, input_size);

    double output_mse = mse(input_data, output_data, input_size);
    double output_snr = snr(input_data, remaining_noise, input_size);

    printf("Mother Wavelet: %s\n", wavelet.name);
    printf("Depth: %d\n", depth);
    printf("Threshold type: %s\n", threshold_type == soft ? "soft" : "hard");
    printf("Threshold value: %lf\n", threshold);
    printf("k: %lf\n", k);
    printf("m: %lf\n", m);
    printf("Input SNR: %lf\n", input_snr);
    printf("Input MSE: %lf\n", input_mse);
    printf("Output SNR: %lf\n", output_snr);
    printf("Output MSE: %lf\n", output_mse);
}
