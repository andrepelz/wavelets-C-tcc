#include <string.h>
#include "wavelet_base.h"

#define HAAR_FILTER_SIZE 2
#define DB2_FILTER_SIZE 4
#define SYM2_FILTER_SIZE 4
#define DB5_FILTER_SIZE 10
#define SYM5_FILTER_SIZE 10
#define DB8_FILTER_SIZE 16
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

    if(strcmp(name, "sym2") == 0) {
        double dec_lo[SYM2_FILTER_SIZE] = { -0.12940952255092145, 0.22414386804185735, 0.836516303737469, 0.48296291314469025 };
        double dec_hi[SYM2_FILTER_SIZE] = { -0.48296291314469025, 0.836516303737469, -0.22414386804185735, -0.12940952255092145 };

        result.filter_size = SYM2_FILTER_SIZE;

        result.scaling_filter = malloc(sizeof(dec_lo));
        result.wavelet_filter = malloc(sizeof(dec_hi));

        memcpy(result.scaling_filter, dec_lo, sizeof(dec_lo));
        memcpy(result.wavelet_filter, dec_hi, sizeof(dec_hi));
    }

    if(strcmp(name, "db5") == 0) {
        double dec_lo[DB5_FILTER_SIZE] = { 
            0.0033357252854737712, -0.012580751999081999, -0.006241490212798274, 0.07757149384004572, -0.032244869584638375,
            -0.24229488706638203, 0.13842814590132074, 0.7243085284377729, 0.6038292697971896, 0.16010239797419293
        };
        double dec_hi[DB5_FILTER_SIZE] = { 
            -0.16010239797419293, 0.6038292697971896, -0.7243085284377729, 0.13842814590132074, 0.24229488706638203,
            -0.032244869584638375, -0.07757149384004572, -0.006241490212798274, 0.012580751999081999, 0.0033357252854737712
        };

        result.filter_size = DB5_FILTER_SIZE;

        result.scaling_filter = malloc(sizeof(dec_lo));
        result.wavelet_filter = malloc(sizeof(dec_hi));

        memcpy(result.scaling_filter, dec_lo, sizeof(dec_lo));
        memcpy(result.wavelet_filter, dec_hi, sizeof(dec_hi));
    }

    if(strcmp(name, "sym5") == 0) {
        double dec_lo[SYM5_FILTER_SIZE] = { 
            0.027333068345077982, 0.029519490925774643, -0.039134249302383094, 0.1993975339773936, 0.7234076904024206,
            0.6339789634582119, 0.01660210576452232, -0.17532808990845047, -0.021101834024758855, 0.019538882735286728
        };
        double dec_hi[SYM5_FILTER_SIZE] = { 
            -0.019538882735286728, -0.021101834024758855, 0.17532808990845047, 0.01660210576452232, -0.6339789634582119,
            0.7234076904024206, -0.1993975339773936, -0.039134249302383094, -0.029519490925774643, 0.027333068345077982
        };

        result.filter_size = SYM5_FILTER_SIZE;

        result.scaling_filter = malloc(sizeof(dec_lo));
        result.wavelet_filter = malloc(sizeof(dec_hi));

        memcpy(result.scaling_filter, dec_lo, sizeof(dec_lo));
        memcpy(result.wavelet_filter, dec_hi, sizeof(dec_hi));
    }

    if(strcmp(name, "db8") == 0) {
        double dec_lo[DB8_FILTER_SIZE] = { 
            -0.00011747678412476953, 0.0006754494064505693, -0.00039174037337694705, -0.004870352993451574,
            0.008746094047405777, 0.013981027917398282, -0.044088253930794755, -0.017369301001807547,
            0.12874742662047847, 0.0004724845739132828, -0.2840155429615469, -0.015829105256349306,
            0.5853546836542067, 0.6756307362972898, 0.31287159091429995, 0.05441584224310401
        };
        double dec_hi[DB8_FILTER_SIZE] = { 
            -0.05441584224310401, 0.31287159091429995, -0.6756307362972898, 0.5853546836542067,
            0.015829105256349306, -0.2840155429615469, -0.0004724845739132828, 0.12874742662047847,
            0.017369301001807547, -0.044088253930794755, -0.013981027917398282, 0.008746094047405777,
            0.004870352993451574, -0.00039174037337694705, -0.0006754494064505693, -0.00011747678412476953
        };

        result.filter_size = DB8_FILTER_SIZE;

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