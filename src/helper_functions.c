/* 
  SOURCE: https://github.com/fabrizzio-gz/wav
  AUTHOR: fabrizzio-gz
*/

#include "helper_functions.h"

#include <stdio.h>
#include <stdlib.h>


/* Machine should be little-endian to show header's numerical values correctly */
int is_bigendian() {
  union {
    char bytes[4];
    int val;
  } test;

  test.bytes[0] = 0;
  test.bytes[1] = 0;
  test.bytes[2] = 0;
  test.bytes[3] = 0xff;
 
  return test.val == 0xff;
}


/* Reverse in-place `l` elements of array `s` */
void reverse(byte *s, int l) {
  char c;
  int i;
  for (i=0; i<l/2; i++) {
    c = s[i];
    s[i] = s[l-1-i];
    s[l-1-i] = c;
  }
}
