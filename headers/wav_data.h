/* 
  SOURCE: https://github.com/fabrizzio-gz/wav
  AUTHOR: fabrizzio-gz
*/

#ifndef WAV_DATA_H
#define WAV_DATA_H

#include <stdio.h>
#include "wav_types.h"

short *read_data(FILE *fp_in, union header_data *header_bytes);
void write_wav(FILE *fp_out, union header_data *header_bytes, short *data, char *file_name);
size_t get_data_size(union header_data *header_bytes);

#endif

