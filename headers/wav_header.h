/* 
  SOURCE: https://github.com/fabrizzio-gz/wav
  AUTHOR: fabrizzio-gz
*/

#ifndef WAV_HEADER_H
#define WAV_HEADER_H

#include <stdio.h>
#include "wav_types.h"

void read_header(FILE *fp, union header_data *file_bytes, char *file_name);
void print_header_data(union header_data *file_bytes);

#endif
