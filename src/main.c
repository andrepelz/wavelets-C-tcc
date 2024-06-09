#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "utils.h"
#include "io_handling.h"
#include "wavelet_transform.h"
#include "wavelet_thresholding.h"

#define SIGNAL_DURATION_LIMIT_SECONDS 30
#define SIGNAL_SAMPLE_RATE 16000

#define FILENAME_BUFFER_SIZE 200
#define CONFIG_ALIAS_BUFFER_SIZE 50

void sub_timespec(struct timespec t1, struct timespec t2, struct timespec *td)
{
    const long NS_PER_SECOND = 1000000000;

    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;
    if (td->tv_sec > 0 && td->tv_nsec < 0)
    {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }
    else if (td->tv_sec < 0 && td->tv_nsec > 0)
    {
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }
}

signal_t* evaluate_noise_reduction_algorithm(
    signal_t input_data, 
    signal_t noise, 
    size_t input_size,
    Wavelet wavelet,
    uint16_t depth,
    threshold_t threshold_type,
    double k,
    double m,
    FILE *result_file) {
    struct timespec execution_start, execution_end, execution_time;

    signal_t noisy_data = malloc(input_size*sizeof(*noisy_data));
    add(input_data, noise, noisy_data, input_size);

    double input_mse = mse(input_data, noisy_data, input_size);
    double input_snr = snr(input_data, noise, input_size);

    clock_gettime(CLOCK_REALTIME, &execution_start);

    DwtResult transform = wavedec(noisy_data, input_size, wavelet, depth);

    double *coefficients_d1 = transform.detail[0];
    double threshold = calculate_threshold(coefficients_d1, input_size, k, m);
    apply_threshold(&transform, threshold, threshold_type);

    signal_t output_data = waverec(transform, wavelet);

    clock_gettime(CLOCK_REALTIME, &execution_end);

    signal_t remaining_noise = malloc(input_size*sizeof(*remaining_noise));
    subtract(output_data, input_data, remaining_noise, input_size);

    double output_mse = mse(input_data, output_data, input_size);
    double output_snr = snr(input_data, remaining_noise, input_size);

    sub_timespec(execution_start, execution_end, &execution_time);

    fprintf(result_file, "%lf;", input_snr);
    fprintf(result_file, "%lf;", output_snr);
    fprintf(result_file, "%lf;", input_mse);
    fprintf(result_file, "%lf;", output_mse);
    fprintf(result_file, "%lf\n", ((double) execution_time.tv_nsec)/1000000);

    signal_t* outputs = malloc(2*sizeof(signal_t));
    
    outputs[0] = noisy_data;
    outputs[1] = output_data;

    return outputs;
}

int main(int argc, char* argv[]) {
    if (argc != 8)
        return -1;

    Wavelet wavelet = get_wavelet(argv[3]);
    uint16_t depth = atof(argv[4]);
    char *thresh_type_str = argv[5];
    threshold_t threshold_type = get_threshold(thresh_type_str);
    double k = atof(argv[6]), m = atof(argv[7]);

    if(wavelet.filter_size == 0
        || threshold_type < 0 || threshold_type > 1
        || depth < 0
        || k < 0 || k > 1
        || m < 0 || m > 1)
        return -1;
    
    signal_t input_data;
    signal_t noise_data;
    size_t max_size, signal_size;

    char filename_prefix[FILENAME_BUFFER_SIZE/2];
    char input_filename[FILENAME_BUFFER_SIZE];
    char noise_filename[FILENAME_BUFFER_SIZE];
    char config_alias[CONFIG_ALIAS_BUFFER_SIZE];

    snprintf(filename_prefix, FILENAME_BUFFER_SIZE, "inputs/%s", argv[1]);
    snprintf(input_filename, FILENAME_BUFFER_SIZE, "%s/%s.wav", filename_prefix, argv[1]);
    snprintf(noise_filename, FILENAME_BUFFER_SIZE, "%s/noise_%s.wav", filename_prefix, argv[2]);

    snprintf(config_alias, CONFIG_ALIAS_BUFFER_SIZE, "%s-%d-%s-%.2lf-%.2lf",
        wavelet.name, depth, thresh_type_str, k, m);

    max_size = SIGNAL_DURATION_LIMIT_SECONDS*SIGNAL_SAMPLE_RATE;
    signal_size = read_input_files(&input_data, &noise_data, input_filename, noise_filename, max_size);

    if (signal_size < 0)
        return -1;

    FILE *result_csv_file = fopen("results.csv", "ab");
    FILE *result_wav_file = fopen("denoised.wav", "wb");

    fprintf(result_csv_file, "%s;%s;%s;", argv[1], argv[2], config_alias);

    signal_t* outputs = evaluate_noise_reduction_algorithm(input_data, noise_data, signal_size, wavelet, depth, threshold_type, k, m, result_csv_file);

    // save_output_file(outputs[0], "noisy.wav", input_filename);
    // save_output_file(outputs[1], "denoised.wav", input_filename);

    free(input_data);
    free(noise_data);
    free(outputs[0]);
    free(outputs[1]);
    fclose(result_csv_file);

    return 0;
}