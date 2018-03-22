#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include "../hash.h"

char long_value(signed char* const trits, const int offset, const int size);
char charValue(signed char* const trits, const int offset, const int size);
char* bytes_from_trits(signed char* const trits, const int offset, const int size);
void getTrits(const char* bytes, int bytelength, signed char* const trits,
              int length);
int indexOf(char* values, char find);
signed char* trits_from_trytes(const char* trytes, int length);
void copyTrits(signed char const value, signed char* const destination, const int offset,
               const int size);
char* trytes_from_trits(signed char* const trits, const int offset, const int size);
char tryteValue(signed char* const trits, const int offset);

#endif
