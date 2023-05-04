#ifndef MATH_SRC_HEADERS_MY_MATH_H_
#define MATH_SRC_HEADERS_MY_MATH_H_

#include <string.h>

#define MY_INF 1.0 / 0.0
#define MY_NAN __builtin_nanf("")
#define MY_PI 3.14159265358979323846
#define MY_NULL (void *)0

long double my_fabs(double x);
int my_abs(int x);
long double my_floor(double x);
long double my_ceil(double x);
long double my_fmod(double x, double y);
long double my_exp(double x);
long double my_log(double x);
long double my_pow(double base, double exp);
long double my_sin(double x);
long double my_cos(double x);
long double my_tan(double x);
long double my_sqrt(double x);
long double my_atan(double x);
long double my_asin(double x);
long double my_acos(double x);

#endif  // MATH_SRC_HEADERS_MY_MATH_H_
