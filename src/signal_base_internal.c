#include "signal_base_internal.h"
#include "signal_base.h"

int internal_compare_function(const void *a,const void *b) {
    sample_t *x = (sample_t *) a;
    sample_t *y = (sample_t *) b;

    if (*x < *y) return -1;
    else if (*x > *y) return 1;
    return 0;
}
