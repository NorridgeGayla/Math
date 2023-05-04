#include "../headers/common.h"

long double powIntExp(double base, double exp) {
  long double result = 1.0;
  if (exp < 0.0) {
    exp *= -1.0;
    base = 1.0 / base;
  }
  if (exp >= 0.0) {
    while (exp-- && result != MY_INF) {
      result *= base;
    }
  }
  return result;
}

int getRank(double* arg) {
  int rank = 0;
  if (my_floor(my_fabs(*arg)) > 9) {
    while (my_floor(my_fabs(*arg)) > 9) {
      *arg /= 10.0;
      rank++;
    }
  } else {
    while ((int)my_floor(my_fabs(*arg)) == 0) {
      *arg *= 10.0;
      rank--;
    }
  }
  return rank;
}

long double removeFract(double x, long* exponent) {
  unsigned long input = 0;
  memcpy(&input, &x, 8);
  *exponent = ((input >> 52) & 0x7ff) - 1023;
  if (*exponent >= 0) {
    long bits = 52 - *exponent;
    if (bits > 0) {
      unsigned long mask = 0xffffffffffffffff << bits;
      unsigned long output = input & mask;
      memcpy(&x, &output, 8);
    }
  } else {
    x = 0.0;
  }
  return x;
}

int my_signbit(double num) {
  int result = 0;
  unsigned long input = 0;
  memcpy(&input, &num, 8);
  input >>= 63;
  result = input & 0x1;
  return result;
}

int checkIntegerNum(double num) {
  return my_fabs(num) == my_floor(my_fabs(num));
}

int checkEvenNum(double num) { return my_fmod(my_fabs(num), 2.0) == 0.0; }
