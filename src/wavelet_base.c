#include <string.h>
#include "wavelet_base.h"

#define HAAR_FILTER_SIZE 2
#define DB2_FILTER_SIZE 4

Wavelet wavelet(char* name) {
    Wavelet result;

    result.name = name;

    if(strcmp(name, "haar") == 0) {
        double dec_lo[HAAR_FILTER_SIZE] = { 0.7071067811865476, 0.7071067811865476 };
        double dec_hi[HAAR_FILTER_SIZE] = { -0.7071067811865476, 0.7071067811865476 };
        double rec_lo[HAAR_FILTER_SIZE] = { 0.7071067811865476, -0.7071067811865476 };
        double rec_hi[HAAR_FILTER_SIZE] = { 0.7071067811865476, 0.7071067811865476 };

        result.filter_size = HAAR_FILTER_SIZE;

        result.dec_lo = malloc(sizeof(dec_lo));
        result.dec_hi = malloc(sizeof(dec_hi));
        result.rec_lo = malloc(sizeof(rec_lo));
        result.rec_hi = malloc(sizeof(rec_hi));

        memcpy(result.dec_lo, dec_lo, sizeof(dec_lo));
        memcpy(result.dec_hi, dec_hi, sizeof(dec_hi));
        memcpy(result.rec_lo, rec_lo, sizeof(rec_lo));
        memcpy(result.rec_hi, rec_hi, sizeof(rec_hi));
    }

    if(strcmp(name, "db2") == 0) {
        double dec_lo[DB2_FILTER_SIZE] = { -0.12940952255126037, 0.2241438680420134, 0.8365163037378079, 0.48296291314453416 };
        double dec_hi[DB2_FILTER_SIZE] = { -0.48296291314453416, 0.8365163037378079, -0.2241438680420134, -0.12940952255126037 };
        double rec_lo[DB2_FILTER_SIZE] = { 0.48296291314453416, 0.8365163037378079, 0.2241438680420134, -0.12940952255126037 };
        double rec_hi[DB2_FILTER_SIZE] = { -0.12940952255126037, -0.2241438680420134, 0.8365163037378079, -0.48296291314453416 };

        result.filter_size = DB2_FILTER_SIZE;

        result.dec_lo = malloc(sizeof(dec_lo));
        result.dec_hi = malloc(sizeof(dec_hi));
        result.rec_lo = malloc(sizeof(rec_lo));
        result.rec_hi = malloc(sizeof(rec_hi));

        memcpy(result.dec_lo, dec_lo, sizeof(dec_lo));
        memcpy(result.dec_hi, dec_hi, sizeof(dec_hi));
        memcpy(result.rec_lo, rec_lo, sizeof(rec_lo));
        memcpy(result.rec_hi, rec_hi, sizeof(rec_hi));
    }

    return result;
}