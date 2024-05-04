#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "wavelet_transform.h"
#include "wavelet_thresholding.h"

#define ARRAY_SIZE 16
#define ALTERNATE_ARRAY_SIZE 25
#define MOTHER_WAVELET "db2"
#define THRESHOLD_VALUE 5
#define THRESHOLD_TYPE soft

void generic_test() {
    double base_arr[ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
    DwtResult transform;
    double *inverse_transform;

    double *iter;
    double *end = &base_arr[ARRAY_SIZE];

    uint16_t depth = 3;

    Wavelet wavelet = get_wavelet(MOTHER_WAVELET);

    transform = wavedec(base_arr, ARRAY_SIZE, wavelet, depth);

    inverse_transform = waverec(transform, wavelet);

    end = inverse_transform + ARRAY_SIZE;

    for(iter = inverse_transform; iter != end; iter++)
        printf("%lf\t", *iter);

    printf("\n\n");
}

void threshold_test() {
    double base_arr[ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
    double transform_arr[ALTERNATE_ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
    Wavelet wavelet = get_wavelet(MOTHER_WAVELET);

    coeffs_apply_threshold(base_arr, ARRAY_SIZE, THRESHOLD_VALUE, THRESHOLD_TYPE);

    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%lf\t", base_arr[i]);
    }

    printf("\n\n");

    DwtResult transform = wavedec(transform_arr, ALTERNATE_ARRAY_SIZE, wavelet, 3);
    apply_threshold(&transform, THRESHOLD_VALUE, THRESHOLD_TYPE);
    double* inverse_transform = waverec(transform, wavelet);

    for(int i = 0; i < ALTERNATE_ARRAY_SIZE; i++) {
        printf("%lf\t", inverse_transform[i]);
    }

    printf("\n\n");
}

// void alternate_test() {
//     double base_arr[ALTERNATE_ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
//     double *transform;
//     double *inverse_transform;

//     double *iter;
//     double *end = &base_arr[ALTERNATE_ARRAY_SIZE];

//     uint16_t depth = 3;

//     uint16_t depth_mod_test = pow(2, depth); // padding added to meet condition of input size being N*2^depth
//     uint16_t padding = ALTERNATE_ARRAY_SIZE%depth_mod_test != 0
//         ? depth_mod_test - ALTERNATE_ARRAY_SIZE%depth_mod_test
//         : 0;

//     uint16_t arr_size = ALTERNATE_ARRAY_SIZE + padding;
//     double *arr_ptr = (double *)malloc(
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

int main() {
    threshold_test();

    return 0;
}