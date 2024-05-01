#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "haar_wavelet.h"

#define ARRAY_SIZE 16
#define ALTERNATE_ARRAY_SIZE 25

void reference_test() {
    double base_arr[ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
    double *transform;
    double *inverse_transform;

    double *iter;
    double *end = &base_arr[ARRAY_SIZE];

    uint16_t depth = 3;

    transform = haar_transform(base_arr, ARRAY_SIZE, depth);

    for(iter = transform; iter != end; iter++)
        printf("%lf\t", *iter);

    printf("\n\n");

    inverse_transform = haar_inverse_transform(base_arr, ARRAY_SIZE, depth);

    for(iter = inverse_transform; iter != end; iter++)
        printf("%lf\t", *iter);

    printf("\n\n");
}

void alternate_test() {
    double base_arr[ALTERNATE_ARRAY_SIZE] = { 32, 10, 20, 38, 37, 28, 38, 34, 18, 24, 18, 9, 23, 24, 28, 34 };
    double *transform;
    double *inverse_transform;

    double *iter;
    double *end = &base_arr[ALTERNATE_ARRAY_SIZE];

    uint16_t depth = 3;

    uint16_t depth_mod_test = pow(2, depth); // padding added to meet condition of input size being N*2^depth
    uint16_t padding = ALTERNATE_ARRAY_SIZE%depth_mod_test != 0
        ? depth_mod_test - ALTERNATE_ARRAY_SIZE%depth_mod_test
        : 0;

    uint16_t arr_size = ALTERNATE_ARRAY_SIZE + padding;
    double *arr_ptr = (double *)malloc(
        arr_size*sizeof(double));

    for(int i = 0; i < arr_size; i++)
        arr_ptr[i] = i < ALTERNATE_ARRAY_SIZE ? base_arr[i] : 0;

    end = &arr_ptr[arr_size];

    for(iter = arr_ptr; iter != end; iter++)
        printf("%.2lf\t", *iter);

    printf("\n\n");
    
    transform = haar_transform(arr_ptr, arr_size, depth);

    for(iter = transform; iter != end; iter++)
        printf("%.2lf\t", *iter);

    printf("\n\n");

    inverse_transform = haar_inverse_transform(transform, arr_size, depth);

    for(iter = inverse_transform; iter != end; iter++)
        printf("%.2lf\t", *iter);

    printf("\n\n");
}

void new_thing() {
    Wavelet db2 = wavelet("db2");

    printf("=== WAVELET ===\nName: %s\nFilters: \n", db2.name);

    for(int i = 0; i < db2.filter_size; i++) {
        printf("%lf", db2.dec_lo[i]);
        printf(i == db2.filter_size - 1 ? "\n" : "\t");
    }

    for(int i = 0; i < db2.filter_size; i++) {
        printf("%lf", db2.dec_hi[i]);
        printf(i == db2.filter_size - 1 ? "\n" : "\t");
    }

    for(int i = 0; i < db2.filter_size; i++) {
        printf("%lf", db2.rec_lo[i]);
        printf(i == db2.filter_size - 1 ? "\n" : "\t");
    }

    for(int i = 0; i < db2.filter_size; i++) {
        printf("%lf", db2.rec_hi[i]);
        printf(i == db2.filter_size - 1 ? "\n" : "\t");
    }
}

int main() {
    new_thing();

    return 0;
}