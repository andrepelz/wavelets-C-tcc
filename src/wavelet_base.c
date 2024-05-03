#include <string.h>
#include "wavelet_base.h"

#define HAAR_FILTER_SIZE 2
#define DB2_FILTER_SIZE 4

Wavelet get_wavelet(char* name) {
    Wavelet result;

    result.name = name;

    if(strcmp(name, "haar") == 0) {
        double dec_lo[HAAR_FILTER_SIZE] = { 0.7071067811865476, 0.7071067811865476 };
        double dec_hi[HAAR_FILTER_SIZE] = { -0.7071067811865476, 0.7071067811865476 };

        result.filter_size = HAAR_FILTER_SIZE;

        result.scaling_filter = malloc(sizeof(dec_lo));
        result.wavelet_filter = malloc(sizeof(dec_hi));

        memcpy(result.scaling_filter, dec_lo, sizeof(dec_lo));
        memcpy(result.wavelet_filter, dec_hi, sizeof(dec_hi));
    }

    if(strcmp(name, "db2") == 0) {
        double dec_lo[DB2_FILTER_SIZE] = { -0.12940952255126037, 0.2241438680420134, 0.8365163037378079, 0.48296291314453416 };
        double dec_hi[DB2_FILTER_SIZE] = { -0.48296291314453416, 0.8365163037378079, -0.2241438680420134, -0.12940952255126037 };

        result.filter_size = DB2_FILTER_SIZE;

        result.scaling_filter = malloc(sizeof(dec_lo));
        result.wavelet_filter = malloc(sizeof(dec_hi));

        memcpy(result.scaling_filter, dec_lo, sizeof(dec_lo));
        memcpy(result.wavelet_filter, dec_hi, sizeof(dec_hi));
    }

    return result;
}