#include "io_handling.h"

#include <stdio.h>

#include "wav_header.h"
#include "wav_data.h"

size_t read_input_files(signal_t *input_data, signal_t *noise_data, char *input_filename, char *noise_filename, size_t max_size) {
    FILE *input_file, *noise_file;
    union header_data *input_header, *noise_header;
    size_t input_size, noise_size, result_size;

    input_file = fopen(input_filename, "rb");
    noise_file = fopen(noise_filename, "rb");

    if (input_file == NULL || noise_file == NULL)
        return -1;

    input_header = malloc(sizeof(union header_data));
    noise_header = malloc(sizeof(union header_data));

    read_header(input_file, input_header, input_filename);
    read_header(noise_file, noise_header, noise_filename);

    input_size = get_data_size(input_header);
    noise_size = get_data_size(noise_header);

    if(input_size > max_size)
        input_size = max_size;
    
    if(noise_size > max_size)
        noise_size = max_size;

    result_size = input_size > noise_size ? noise_size : input_size;

    *input_data = read_data(input_file, input_header);
    *input_data = realloc(*input_data, result_size*sizeof(sample_t));

    *noise_data = read_data(noise_file, noise_header);
    *noise_data = realloc(*noise_data, result_size*sizeof(sample_t));

    free(input_file);
    free(input_header);
    free(noise_file);
    free(noise_header);

    return result_size;
}