#include "signal_base_internal.h"
#include "signal_base.h"

int sample_compare_function(const void *a, const void *b) {
    return double_compare_function(a, b);
}