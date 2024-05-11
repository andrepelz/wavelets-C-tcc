#include <string.h>
#include "wavelet_base.h"

#define HAAR_FILTER_SIZE 2
#define DB2_FILTER_SIZE 4
#define SYM8_FILTER_SIZE 16

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

    if(strcmp(name, "sym8") == 0) {
        double dec_lo[SYM8_FILTER_SIZE] = { 
            -0.0033824159510061256, -0.0005421323317911481, 0.03169508781149298, 0.007607487324917605, 
            -0.1432942383508097, -0.061273359067658524, 0.4813596512583722, 0.7771857517005235, 
            0.3644418948353314, -0.05194583810770904, -0.027219029917056003, 0.049137179673607506, 
            0.003808752013890615, -0.01495225833704823, -0.0003029205147213668, 0.0018899503327594609 };
        double dec_hi[SYM8_FILTER_SIZE] = { 
            -0.0018899503327594609, -0.0003029205147213668, 0.01495225833704823, 0.003808752013890615, 
            -0.049137179673607506, -0.027219029917056003, 0.05194583810770904, 0.3644418948353314, 
            -0.7771857517005235, 0.4813596512583722, 0.061273359067658524, -0.1432942383508097, 
            -0.007607487324917605, 0.03169508781149298, 0.0005421323317911481, -0.0033824159510061256 };

        result.filter_size = SYM8_FILTER_SIZE;

        result.scaling_filter = malloc(sizeof(dec_lo));
        result.wavelet_filter = malloc(sizeof(dec_hi));

        memcpy(result.scaling_filter, dec_lo, sizeof(dec_lo));
        memcpy(result.wavelet_filter, dec_hi, sizeof(dec_hi));
    }

    return result;
}