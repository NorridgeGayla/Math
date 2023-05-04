#ifndef MATH_SRC_HEADERS_COMMON_H_
#define MATH_SRC_HEADERS_COMMON_H_

#include "my_math.h"
#define EPS 1e-14

long double powIntExp(double base, double exp);
int getRank(double* arg);
long double removeFract(double x, long* exponent);
int my_signbit(double num);
int checkIntegerNum(double num);
int checkEvenNum(double num);

#endif  // MATH_SRC_HEADERS_COMMON_H_
