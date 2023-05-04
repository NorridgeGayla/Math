#include "../headers/my_math.h"

#include "../headers/common.h"

long double my_asin(double x) {
  long double result = 0.0;
  if (x > 1.0 - EPS && x < 1.0 + EPS) {
    result = MY_PI / 2;
  } else if (x == -1.0) {
    result = -MY_PI / 2;
  } else if (x == 0.0 && my_signbit(x)) {
    result = -0.0;
  } else if (my_fabs(x) <= 1.0) {
    long double step = x;
    result += step;
    int i = 1;
    do {
      step *= my_pow(2 * i - 1, 2) * my_pow(x, 2) / (2 * i * (2 * i + 1));
      result += step;
      i++;
    } while (my_fabs(step) > EPS && i < 1e+05);
  } else {
    result = MY_NAN;
  }
  return result;
}

long double my_acos(double x) { return MY_PI / 2 - my_asin(x); }

long double my_atan(double x) {
  long double result = 0.0;
  long double step = 0.0;
  int i = 1;
  long double coef = MY_PI / 2;
  if (x == 0.0 && my_signbit(x)) {
    result = -0.0;
  } else if (x == MY_INF) {
    result = MY_PI / 2;
  } else if (x == -MY_INF) {
    result = -MY_PI / 2;
  } else if (x != x) {
    result = MY_NAN;
  } else if (my_fabs(x) <= 1.0) {
    step = x;
    result += step;
    do {
      step *= (-1) * my_pow(x, 2) * (2 * i - 1) / (double)(2 * i + 1);
      result += step;
      i++;
    } while (my_fabs(step) > EPS && i < 1e+06);
  } else {
    if (x <= -1.0) {
      coef *= -1;
    }
    step = -1.0 / x;
    result += coef + step;
    do {
      step *= (-1) * (2 * i - 1) / ((double)(2 * i + 1) * my_pow(x, 2));
      result += step;
      i++;
    } while (my_fabs(step) > EPS);
  }
  return result;
}

long double my_sqrt(double x) {
  long double result = 0.0;
  if (x < -EPS) {
    result = -MY_NAN;
  } else {
    result = my_pow(x, 0.5);
  }
  return result;
}

long double my_tan(double x) {
  long double result;
  result = my_sin(x) / my_cos(x);
  return result;
}

long double my_cos(double x) {
  x = my_fmod(x, 2 * MY_PI);
  long double result = 0.0;
  long double step = 1.0;
  result += step;
  int i = 1;
  do {
    step *= (-1) * my_pow(x, 2) / ((2 * i - 1) * (2 * i));
    result += step;
    i++;
  } while (my_fabs(step) > EPS);
  return result;
}

long double my_sin(double x) {
  long double result = 0.0;
  if (x == 0 && my_signbit(x)) {
    result = -0.0;
  } else if (x != x || x == MY_INF || x == -MY_INF) {
    result = MY_NAN;
  } else {
    if (x == 0.0 || x == MY_PI) {
      result = 0.0;
    } else if (x == MY_PI / 2) {
      result = 1.0;
    } else if (x == -MY_PI / 2) {
      result = -1.0;
    } else {
      x = my_fmod(x, 2.0 * MY_PI);
      if (x > MY_PI / 2 && x < MY_PI) {
        result = my_sin(MY_PI - x);
      } else if (x > MY_PI && x < 3 * MY_PI / 2) {
        result = -my_sin(x - MY_PI);
      } else if (x > 3 * MY_PI / 2 && x < 2 * MY_PI) {
        result = -my_sin(2 * MY_PI - x);
      } else {
        long double step = x;
        result += step;
        int i = 1;
        do {
          step *= (-1) * my_pow(x, 2) / ((2 * i) * (2 * i + 1));
          result += step;
          i++;
        } while (my_fabs(step) > 1e-100);
      }
    }
  }
  return result;
}

int my_abs(int x) { return x >= EPS ? x : -x; }

long double my_ceil(double x) {
  long exponent = 0;
  long double result = removeFract(x, &exponent);
  if (exponent < 0)
    result = x > 0;
  else if (x > 0 && x != result)
    result += 1.0;
  return result;
}

long double my_exp(double x) {
  long double result;
  if (x == MY_INF) {
    result = MY_INF;
  } else if (x == -MY_INF) {
    result = 0.0;
  } else {
    result = 1.0;
    long double num = x;
    long double i = 1.0;
    long double step = 1.0;
    while (my_fabs(step) > EPS && my_fabs(step) != MY_INF) {
      step *= num / i;
      result += step;
      i++;
    }
    if (my_fabs(step) == MY_INF) {
      result = MY_INF;
    }
  }
  return result;
}

long double my_fabs(double x) {
  x = x >= EPS ? x : -x;
  return (long double)x;
}

long double my_floor(double x) {
  long exponent = 0;
  long double result = removeFract(x, &exponent);
  if (exponent < 0)
    result = x < 0.0 ? -1 : 0.0;
  else if (x < 0 && x != result)
    result -= 1.0;
  return result;
}

long double my_fmod(double x, double y) {
  long double n, result;
  if (x < -EPS && y < -EPS) {
    n = my_floor(my_fabs(x / y));
  } else if (x < -EPS || y < -EPS) {
    n = (-1) * my_floor(my_fabs(x / y));
  } else {
    n = my_floor(my_fabs(x / y));
  }
  result = x - n * y;
  if (y == 0) {
    result = 0 / 0.0;
  }
  return result;
}

long double my_log(double x) {
  long double res = 0.0;
  long double step = 0.0;
  int i = 1;
  if (my_fabs(x) < EPS) {
    res = -MY_INF;
  } else if (x < -EPS) {
    res = -MY_NAN;
  } else if (my_floor(x) < 1 || my_floor(x) > 10) {
    int rank = getRank(&x);
    res = my_log(x) + rank * my_log(10);
  } else {
    step = (x - 1) / (x + 1);
    res += step;
    do {
      step *= (2 * i - 1) * my_pow((x - 1) / (x + 1), 2) / (double)(2 * i + 1);
      res += step;
      i++;
    } while (my_fabs(step) > EPS);
    res *= 2;
  }
  return res;
}

long double my_pow(double base, double exp) {
  long double result = 0.0;
  if (exp == 0.0 || base == 1.0) {
    result = 1.0;
  } else if (exp != exp || base != base) {
    result = MY_NAN;
  } else if (base == 0.0 && my_signbit(base) == 0) {
    if (exp > 0.0 || exp == MY_INF) {
      result = 0.0;
    } else if (exp < 0.0 || exp == -MY_INF) {
      result = MY_INF;
    }
  } else if (base == 0.0 && my_signbit(base)) {
    if ((exp > 0.0 && (checkEvenNum(exp) || checkIntegerNum(exp) == 0)) ||
        exp == MY_INF) {
      result = 0.0;
    } else if (exp > 0.0 && checkEvenNum(exp) == 0) {
      result = -0.0;
    } else if ((exp < 0.0 &&
                (checkEvenNum(exp) || checkIntegerNum(exp) == 0)) ||
               exp == -MY_INF) {
      result = MY_INF;
    } else if (exp < 0.0 && checkEvenNum(exp) == 0) {
      result = -MY_INF;
    }
  } else if (base == -1.0 && (exp == MY_INF || exp == -MY_INF)) {
    result = 1.0;
  } else if (base == MY_INF) {
    if (exp > 0.0 || exp == MY_INF) {
      result = MY_INF;
    } else if (exp < 0.0 || exp == -MY_INF) {
      result = 0.0;
    }
  } else if (base == -MY_INF) {
    if ((exp > 0.0 && (checkEvenNum(exp) || checkIntegerNum(exp) == 0)) ||
        exp == MY_INF) {
      result = MY_INF;
    } else if (exp > 0.0 && checkEvenNum(exp) == 0) {
      result = -MY_INF;
    } else if ((exp < 0.0 &&
                (checkEvenNum(exp) || checkIntegerNum(exp) == 0)) ||
               exp == -MY_INF) {
      result = 0.0;
    } else if (exp < 0.0 && checkEvenNum(exp) == 0) {
      result = -0.0;
    }
  } else if (exp == MY_INF) {
    result = MY_INF;
  } else if (exp == -MY_INF) {
    result = 0.0;
  } else if (checkIntegerNum(exp)) {
    result = powIntExp(base, exp);
  } else if (checkIntegerNum(exp) == 0) {
    if (base < 0.0) {
      result = MY_NAN;
    } else {
      result = my_exp(exp * my_log(base));
    }
  }
  return result;
}
