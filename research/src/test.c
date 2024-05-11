#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "wavelet_transform.h"
#include "wavelet_thresholding.h"
#include "utils.h"
#include "signal_base.h"
#include "prototype.h"
#include "wav_header.h"
#include "wav_data.h"

#define ARRAY_SIZE 16
#define ALTERNATE_ARRAY_SIZE 25
#define MOTHER_WAVELET "db2"
#define THRESHOLD_VALUE 5
#define THRESHOLD_TYPE soft
#define INPUT_FILENAME "input.wav"
#define NOISE_FILENAME "noise.wav"
#define SIGNAL_DURATION_LIMIT_SECONDS 30
#define SIGNAL_SAMPLE_RATE 16000

void generic_test() {
    sample_t base_arr[ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
    DwtResult transform;
    signal_t inverse_transform;

    sample_t *iter;
    sample_t *end = &base_arr[ARRAY_SIZE];

    for(iter = base_arr; iter != end; iter++)
        printf("%d\t", *iter);

    printf("\n\n");

    uint16_t depth = 3;

    Wavelet wavelet = get_wavelet(MOTHER_WAVELET);

    transform = wavedec(base_arr, ARRAY_SIZE, wavelet, depth);

    inverse_transform = waverec(transform, wavelet);

    end = &inverse_transform[ARRAY_SIZE];

    for(iter = inverse_transform; iter != end; iter++)
        printf("%d\t", *iter);

    printf("\n\n");
}

// void threshold_test() {
//     sample_t base_arr[ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
//     sample_t transform_arr[ALTERNATE_ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
//     Wavelet wavelet = get_wavelet(MOTHER_WAVELET);

//     coeffs_apply_threshold(base_arr, ARRAY_SIZE, THRESHOLD_VALUE, THRESHOLD_TYPE);

//     for(int i = 0; i < ARRAY_SIZE; i++) {
//         printf("%lf\t", base_arr[i]);
//     }

//     printf("\n\n");

//     DwtResult transform = wavedec(transform_arr, ALTERNATE_ARRAY_SIZE, wavelet, 3);
//     apply_threshold(&transform, THRESHOLD_VALUE, THRESHOLD_TYPE);
//     signal_t inverse_transform = waverec(transform, wavelet);

//     for(int i = 0; i < ALTERNATE_ARRAY_SIZE; i++) {
//         printf("%lf\t", inverse_transform[i]);
//     }

//     printf("\n\n");

//     double calc_arr[ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
//     double threshold;

//     int ugh = 63;

//     void *test = &ugh;

//     threshold = calculate_threshold(calc_arr, ARRAY_SIZE*2, 1, 1);

//     printf("%lf\n\n", threshold);
// }

int prototype_test() {
    // sample_t base_arr[ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
    // sample_t noise[ARRAY_SIZE] = { 4, -6, 20, 28, 3, 34, 8, 38, 37, 24, -18, 9, 23, -24, 28, 3 };
    Wavelet wavelet = get_wavelet(MOTHER_WAVELET);
    uint16_t depth = 5;
    double k = 1, m = 1;

    FILE *input_file, *noise_file;
    union header_data *input_header, *noise_header;
    signal_t input_data;
    signal_t noise_data;
    size_t input_size, noise_size, max_size;

    input_file = fopen(INPUT_FILENAME, "rb");
    noise_file = fopen(NOISE_FILENAME, "rb");

    if (input_file == NULL || noise_file == NULL)
        return -1;

    input_header = malloc(sizeof(union header_data));
    noise_header = malloc(sizeof(union header_data));

    read_header(input_file, input_header, INPUT_FILENAME);
    read_header(noise_file, noise_header, NOISE_FILENAME);

    input_size = get_data_size(input_header);
    noise_size = get_data_size(noise_header);
    max_size = SIGNAL_DURATION_LIMIT_SECONDS*SIGNAL_SAMPLE_RATE;

    if(input_size > max_size)
        noise_size = max_size;
    
    if(noise_size > max_size)
        noise_size = max_size;

    if(input_size > noise_size)
        input_size = noise_size;
    else
        noise_size = input_size;

    input_data = read_data(input_file, input_header);
    input_data = realloc(input_data, input_size*sizeof(sample_t));

    noise_data = read_data(noise_file, noise_header);
    noise_data = realloc(noise_data, noise_size*sizeof(sample_t));

    proto_evaluate_noise_reduction_algorithm(input_data, noise_data, input_size, wavelet, depth, soft, k, m);

    return 0;
}

// void alternate_test() {
//     double base_arr[ALTERNATE_ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
//     signal_t transform;
//     signal_t inverse_transform;

//     signal_t iter;
//     signal_t end = &base_arr[ALTERNATE_ARRAY_SIZE];

//     uint16_t depth = 3;

//     uint16_t depth_mod_test = pow(2, depth); // padding added to meet condition of input size being N*2^depth
//     uint16_t padding = ALTERNATE_ARRAY_SIZE%depth_mod_test != 0
//         ? depth_mod_test - ALTERNATE_ARRAY_SIZE%depth_mod_test
//         : 0;

//     uint16_t arr_size = ALTERNATE_ARRAY_SIZE + padding;
//     signal_t arr_ptr = (signal_t )malloc(
//         arr_size*sizeof(double));

//     for(int i = 0; i < arr_size; i++)
//         arr_ptr[i] = i < ALTERNATE_ARRAY_SIZE ? base_arr[i] : 0;

//     end = &arr_ptr[arr_size];

//     for(iter = arr_ptr; iter != end; iter++)
//         printf("%.2lf\t", *iter);

//     printf("\n\n");
    
//     transform = haar_transform(arr_ptr, arr_size, depth);

//     for(iter = transform; iter != end; iter++)
//         printf("%.2lf\t", *iter);

//     printf("\n\n");

//     inverse_transform = haar_inverse_transform(transform, arr_size, depth);

//     for(iter = inverse_transform; iter != end; iter++)
//         printf("%.2lf\t", *iter);

//     printf("\n\n");
// }

// int main() {
//     // generic_test();
//     // threshold_test();
//     return prototype_test();

//     return 0;
// }