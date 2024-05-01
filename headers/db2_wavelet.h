#ifndef __DB2_WAVELET_H__
#define __DB2_WAVELET_H__

#include "wavelet_base.h"

DwtResult db2_wavedec(double *data, size_t size, uint16_t depth);
double* db2_waverec(double *data, size_t size, uint16_t depth);

#endif