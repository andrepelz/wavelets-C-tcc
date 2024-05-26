#ifndef __IO_HANDLING_H__
#define __IO_HANDLING_H__

#include "signal_base.h"
#include <stdlib.h>

size_t read_input_files(signal_t *input_data, signal_t *noise_data, char *input_filename, char *noise_filename, size_t max_size);
void save_output_file(signal_t output_data, char *output_filename, char* input_filename);

#endif
