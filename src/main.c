#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <math.h>

#include "utils.h"
#include "io_handling.h"
#include "wavelet_transform.h"
#include "wavelet_thresholding.h"

#define MOTHER_WAVELET "sym8"
#define INPUT_FILENAME "inputs/speech-librivox-0034/speech-librivox-0034.wav"
#define NOISE_FILENAME "inputs/speech-librivox-0034/noise_white_noise_10db.wav"
#define SIGNAL_DURATION_LIMIT_SECONDS 30
#define SIGNAL_SAMPLE_RATE 16000
#define NUM_THREADS 8
#define MAX_THREAD_COUNT 32

#define FILENAME_BUFFER_SIZE 200

void evaluate_noise_reduction_algorithm(
    signal_t input_data, 
    signal_t noise, 
    size_t input_size,
    Wavelet wavelet,
    uint16_t depth,
    threshold_t threshold_type,
    double k,
    double m,
    FILE *result_file) {
    clock_t execution_start, execution_end;

    signal_t noisy_data = malloc(input_size*sizeof(*noisy_data));
    add(input_data, noise, noisy_data, input_size);

    double input_mse = mse(input_data, noisy_data, input_size);
    double input_snr = snr(input_data, noise, input_size);

    execution_start = clock();

    DwtResult transform = wavedec(noisy_data, input_size, wavelet, depth);

    double *coefficients_d1 = transform.detail[0];
    double threshold = calculate_threshold(coefficients_d1, input_size, k, m);
    apply_threshold(&transform, threshold, threshold_type);

    signal_t output_data = waverec(transform, wavelet);

    execution_end = clock();

    signal_t remaining_noise = malloc(input_size*sizeof(*remaining_noise));
    subtract(output_data, input_data, remaining_noise, input_size);

    double output_mse = mse(input_data, output_data, input_size);
    double output_snr = snr(input_data, remaining_noise, input_size);

    // printf("Mother Wavelet: %s\n", wavelet.name);
    // printf("Depth: %d\n", depth);
    // printf("Threshold type: %s\n", threshold_type == soft ? "soft" : "hard");
    // printf("k: %lf\n", k);
    // printf("m: %lf\n", m);
    // printf("Input SNR: %lf\n", input_snr);
    // printf("Input MSE: %lf\n", input_mse);
    // printf("Output SNR: %lf\n", output_snr);
    // printf("Output MSE: %lf\n", output_mse);
    // printf("Execution Time: %lf ms\n", ((double) execution_end - execution_start)/CLOCKS_PER_SEC*1000);

    fprintf(result_file, "%s;", wavelet.name);
    fprintf(result_file, "%d;", depth);
    fprintf(result_file, "%s;", threshold_type == soft ? "soft" : "hard");
    fprintf(result_file, "%lf;", k);
    fprintf(result_file, "%lf;", m);
    fprintf(result_file, "%lf;", input_snr);
    fprintf(result_file, "%lf;", output_snr);
    fprintf(result_file, "%lf;", input_mse);
    fprintf(result_file, "%lf;", output_mse);
    fprintf(result_file, "%lf\n", ((double) execution_end - execution_start)/CLOCKS_PER_SEC*1000);
}

int main(int argc, char* argv[]) {
    if (argc != 3)
        return -1;

    Wavelet wavelet = get_wavelet(MOTHER_WAVELET);
    threshold_t threshold_type = soft;
    uint16_t depth = 5;
    double k = 1, m = 1;
    
    signal_t input_data;
    signal_t noise_data;
    size_t max_size, signal_size;

    // char *input_filename = argv[1];
    // char *noise_filename = argv[2];

    char filename_prefix[FILENAME_BUFFER_SIZE/2];
    char input_filename[FILENAME_BUFFER_SIZE];
    char noise_filename[FILENAME_BUFFER_SIZE];

    int snprintf_check = 0;

    snprintf_check += snprintf(filename_prefix, FILENAME_BUFFER_SIZE, "inputs/%s", argv[1]);
    snprintf(input_filename, FILENAME_BUFFER_SIZE, "%s/%s.wav", filename_prefix, argv[1]);
    snprintf(noise_filename, FILENAME_BUFFER_SIZE, "%s/noise_%s.wav", filename_prefix, argv[2]);

    omp_set_dynamic(0);
    omp_set_num_threads(NUM_THREADS > MAX_THREAD_COUNT ? MAX_THREAD_COUNT : NUM_THREADS);

    max_size = SIGNAL_DURATION_LIMIT_SECONDS*SIGNAL_SAMPLE_RATE;
    signal_size = read_input_files(&input_data, &noise_data, input_filename, noise_filename, max_size);

    if (signal_size < 0)
        return -1;

    // printf("Input: %s\n", input_filename);
    // printf("Noise: %s\n", noise_filename);

    FILE *result_file = fopen("results.csv", "ab");

    fprintf(result_file, "%s;%s;", argv[1], argv[2]);

    evaluate_noise_reduction_algorithm(input_data, noise_data, signal_size, wavelet, depth, threshold_type, k, m, result_file);

    free(input_data);
    free(noise_data);
    fclose(result_file);

    return 0;
}