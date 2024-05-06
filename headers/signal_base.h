#ifndef __SIGNAL_BASE_H__
#define __SIGNAL_BASE_H__

#include <stdint.h>

typedef int16_t sample_t;
typedef sample_t* signal_t;

int sample_compare_function(const void* a, const void* b);

#endif