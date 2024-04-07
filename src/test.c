#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "wavelets.h"

#define ARRAY_SIZE 16
#define ALTERNATE_ARRAY_SIZE 24

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

    transform = haar_transform(base_arr, ALTERNATE_ARRAY_SIZE, depth);

    for(iter = transform; iter != end; iter++)
        printf("%lf\t", *iter);

    printf("\n\n");

    inverse_transform = haar_inverse_transform(base_arr, ALTERNATE_ARRAY_SIZE, depth);

    for(iter = inverse_transform; iter != end; iter++)
        printf("%lf\t", *iter);

    printf("\n\n");
}

int main() {
    alternate_test();

    return 0;
}