/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "tests.check" instead.
 */

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/my_math.h"

#define my_M6 1e-06

START_TEST(my_abs_test) {
  for (int i = -5000; i < 5000; i++) ck_assert_int_eq(abs(i), my_abs(i));
  ck_assert_int_eq(abs(INT_MIN), my_abs(INT_MIN));
  ck_assert_int_eq(abs(INT_MAX), my_abs(INT_MAX));
}
END_TEST

START_TEST(my_acos_test) {
  for (double x = -1.0; x <= 1.0; x += 0.15)
    ck_assert_ldouble_le_tol(fabsl(acos(x) - my_acos(x)), my_M6, my_M6);
}
END_TEST

START_TEST(my_asin_test) {
  for (double x = -1.0; x < 1.0; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(asin(x) - my_asin(x)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(asin(1.0) - my_asin(1.0)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(asin(-0.0) - my_asin(-0.0)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_asin(1.1));
}
END_TEST

START_TEST(my_atan_test) {
  for (double x = -100.4; x <= 100.4; x += 0.3123)
    ck_assert_ldouble_le_tol(fabsl(atan(x) - my_atan(x)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(atan(-0.0) - my_atan(-0.0)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(atan(INFINITY) - my_atan(INFINITY)), my_M6,
                           my_M6);
  ck_assert_ldouble_le_tol(fabsl(atan(-INFINITY) - my_atan(-INFINITY)), my_M6,
                           my_M6);
  ck_assert_ldouble_nan(my_atan(NAN));
}
END_TEST

START_TEST(my_ceil_test) {
  for (double x = -14567; x <= 14567; x += 0.1)
    ck_assert_ldouble_eq_tol(ceil(x), my_ceil(x), my_M6);
  ck_assert_ldouble_eq_tol(ceil(DBL_MIN), my_ceil(DBL_MIN), my_M6);
  ck_assert_ldouble_eq_tol(ceil(DBL_MAX - 1), my_ceil(DBL_MAX - 1), my_M6);
}
END_TEST

START_TEST(my_cos_test) {
  for (double x = -MY_PI * 8; x <= MY_PI * 8; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(cos(x) - my_cos(x)), my_M6, my_M6);
}
END_TEST

START_TEST(my_exp_test) {
  for (double x = -20; x <= 20; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(exp(x) - my_exp(x)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(exp(-INFINITY) - my_exp(-INFINITY)), my_M6,
                           my_M6);
  ck_assert_double_infinite(my_exp(MY_INF));
  ck_assert_double_infinite(my_exp(DBL_MAX));
}
END_TEST

START_TEST(my_fabs_test) {
  for (double x = -500.123; x <= 500.123; x += 0.5)
    ck_assert_ldouble_le_tol(fabsl(fabs(x) - my_fabs(x)), my_M6, my_M6);
  ck_assert_ldouble_eq_tol(fabs(DBL_MIN), my_fabs(DBL_MIN), my_M6);
  ck_assert_ldouble_eq_tol(fabs(DBL_MAX), my_fabs(DBL_MAX), my_M6);
}
END_TEST

START_TEST(my_floor_test) {
  for (double x = -500.0; x <= 500.0; x += 0.5)
    ck_assert_ldouble_eq_tol(floor(x), my_floor(x), my_M6);
  ck_assert_ldouble_eq_tol(floor(DBL_MIN - 1), my_floor(DBL_MIN - 1), my_M6);
  ck_assert_ldouble_eq_tol(floor(DBL_MAX), my_floor(DBL_MAX), my_M6);
}
END_TEST

START_TEST(my_fmod_test) {
  for (double x = -500.123; x <= 500.123; x += 0.5)
    for (double y = -1000.246; x <= 1000.246; x += 0.5)
      ck_assert_ldouble_le_tol(fabsl(fmod(x, y) - my_fmod(x, y)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_fmod(12.3, 0.0));
}
END_TEST

START_TEST(my_log_test) {
  for (double x = 0.0001; x <= 200.555; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(log(x) - my_log(x)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_log(-2.0));
  ck_assert_double_infinite(my_log(0.0));
}
END_TEST

START_TEST(my_pow_test_1) {
  // simple test
  for (double x = -10.12; x <= 10.12; x += 0.1) {
    for (double y = -5; y <= 5; y += 1) {
      ck_assert_ldouble_le_tol(fabsl(pow(x, y) - my_pow(x, y)), my_M6, my_M6);
    }
  }
  for (double x = -10.0; x <= 10.0; x += 1.0) {
    for (double y = -5; y <= 5; y += 1.0) {
      if (!(x == 0.0 && y < 0.0)) {
        ck_assert_ldouble_le_tol(fabsl(pow(x, y) - my_pow(x, y)), my_M6, my_M6);
      }
    }
  }
  double base = 2.3;
  double exp = INFINITY;
  ck_assert_double_infinite(my_pow(base, exp));
  exp = -INFINITY;
  ck_assert_ldouble_le_tol(fabsl(pow(base, exp) - my_pow(base, exp)), my_M6,
                           my_M6);
  base = -2.3;
  exp = 2.3;
  ck_assert_ldouble_nan(my_pow(base, exp));
  base = 2.3;
  for (double exp = 0; exp < 5.0; exp += 0.1) {
    ck_assert_ldouble_le_tol(fabsl(pow(base, exp) - my_pow(base, exp)), my_M6,
                             my_M6);
  }
}
END_TEST

START_TEST(my_pow_test_2) {
  // base = +-0.0
  double base[] = {0.0, -0.0};
  double exp[] = {0.0,  1.0, 2.0, 3.0,  -0.0, -1.0,     -2.0,
                  -3.0, 0.5, 1.2, -0.5, -2.2, INFINITY, -INFINITY};
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 14; i++) {
      ck_assert_ldouble_eq(pow(base[j], exp[i]), my_pow(base[j], exp[i]));
    }
    ck_assert_ldouble_nan(my_pow(base[j], NAN));
    ck_assert_ldouble_nan(my_pow(base[j], -NAN));
  }
}
END_TEST

START_TEST(my_pow_test_3) {
  // base = 1.0
  double base = 1.0;
  double exp[] = {0.0, 1.0, 2.0,  3.0,  -0.0,     -1.0,      -2.0, -3.0,
                  0.5, 1.2, -0.5, -2.2, INFINITY, -INFINITY, NAN,  -NAN};
  for (int i = 0; i < 16; i++) {
    ck_assert_ldouble_eq(pow(base, exp[i]), my_pow(base, exp[i]));
  }
}
END_TEST

START_TEST(my_pow_test_4) {
  // base = -1.0
  double base = -1.0;
  double exp[] = {0.0,  1.0,  2.0,  3.0,      -0.0,
                  -1.0, -2.0, -3.0, INFINITY, -INFINITY};
  for (int i = 0; i < 10; i++) {
    ck_assert_ldouble_eq(pow(base, exp[i]), my_pow(base, exp[i]));
  }
  ck_assert_ldouble_nan(my_pow(base, 1.2));
  ck_assert_ldouble_nan(my_pow(base, -1.2));
  ck_assert_ldouble_nan(my_pow(base, NAN));
  ck_assert_ldouble_nan(my_pow(base, -NAN));
}
END_TEST

START_TEST(my_pow_test_5) {
  // base = inf
  double base = MY_INF;
  double exp[] = {0.0,  1.0,  2.0, 3.0,  -0.0,     -1.0,
                  -2.0, -3.0, 1.2, -1.2, INFINITY, -INFINITY};
  for (int i = 0; i < 12; i++) {
    ck_assert_ldouble_eq(pow(base, exp[i]), my_pow(base, exp[i]));
  }
  ck_assert_ldouble_nan(my_pow(base, NAN));
  ck_assert_ldouble_nan(my_pow(base, -NAN));
}
END_TEST

START_TEST(my_pow_test_6) {
  // base = inf
  double base = -MY_INF;
  double exp[] = {0.0,  1.0,  2.0, 3.0,  -0.0,     -1.0,
                  -2.0, -3.0, 1.2, -1.2, INFINITY, -INFINITY};
  for (int i = 0; i < 12; i++) {
    ck_assert_ldouble_eq(pow(base, exp[i]), my_pow(base, exp[i]));
  }
  ck_assert_ldouble_nan(my_pow(base, NAN));
  ck_assert_ldouble_nan(my_pow(base, -NAN));
}
END_TEST

START_TEST(my_pow_test_7) {
  // base = NAN, -NAN
  double base[] = {NAN, -NAN};
  double exp[] = {1.0,  2.0, 3.0,  -1.0,     -2.0,
                  -3.0, 1.2, -1.2, INFINITY, -INFINITY};
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 10; i++) {
      ck_assert_ldouble_nan(my_pow(base[j], exp[i]));
    }
    ck_assert_ldouble_eq(pow(base[j], 0.0), my_pow(base[j], 0.0));
    ck_assert_ldouble_eq(pow(base[j], -0.0), my_pow(base[j], -0.0));
  }
}
END_TEST

START_TEST(my_sin_test) {
  for (double x = -MY_PI * 8; x <= MY_PI * 8; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(sin(x) - my_sin(x)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(sin(-0.0) - my_sin(-0.0)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(sin(0.0) - my_sin(0.0)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(sin(MY_PI) - my_sin(MY_PI)), my_M6, my_M6);
  ck_assert_ldouble_le_tol(fabsl(sin(MY_PI / 2) - my_sin(MY_PI / 2)), my_M6,
                           my_M6);
  ck_assert_ldouble_le_tol(fabsl(sin(-MY_PI / 2) - my_sin(-MY_PI / 2)), my_M6,
                           my_M6);
  ck_assert_ldouble_nan(my_sin(NAN));
  ck_assert_ldouble_nan(my_sin(INFINITY));
  ck_assert_ldouble_nan(my_sin(-INFINITY));
}
END_TEST

START_TEST(my_sqrt_test) {
  for (double x = 0.0; x <= 57.154623; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(sqrt(x) - my_sqrt(x)), my_M6, my_M6);
  ck_assert_ldouble_nan(my_sqrt(-2.0));
}
END_TEST

START_TEST(my_tan_test) {
  for (double x = -MY_PI / 2 + 0.1; x <= MY_PI / 2 - 0.1; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - my_tan(x)), my_M6, my_M6);
  for (double x = 8.0 * -MY_PI / 2 + 0.1; x <= -6 * MY_PI / 2 - 0.1; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - my_tan(x)), my_M6, my_M6);
  for (double x = -8.0 * MY_PI / 2 + 0.1; x <= 6.0 * MY_PI / 2 - 0.1; x += 0.1)
    ck_assert_ldouble_le_tol(fabsl(tan(x) - my_tan(x)), my_M6, my_M6);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("my_math.h tests");
  TCase *tc1_1 = tcase_create("Comparsions with math.h functions");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, my_abs_test);
  tcase_add_test(tc1_1, my_acos_test);
  tcase_add_test(tc1_1, my_asin_test);
  tcase_add_test(tc1_1, my_atan_test);
  tcase_add_test(tc1_1, my_ceil_test);
  tcase_add_test(tc1_1, my_cos_test);
  tcase_add_test(tc1_1, my_exp_test);
  tcase_add_test(tc1_1, my_fabs_test);
  tcase_add_test(tc1_1, my_floor_test);
  tcase_add_test(tc1_1, my_fmod_test);
  tcase_add_test(tc1_1, my_log_test);
  tcase_add_test(tc1_1, my_pow_test_1);
  tcase_add_test(tc1_1, my_pow_test_2);
  tcase_add_test(tc1_1, my_pow_test_3);
  tcase_add_test(tc1_1, my_pow_test_4);
  tcase_add_test(tc1_1, my_pow_test_5);
  tcase_add_test(tc1_1, my_pow_test_6);
  tcase_add_test(tc1_1, my_pow_test_7);
  tcase_add_test(tc1_1, my_sin_test);
  tcase_add_test(tc1_1, my_sqrt_test);
  tcase_add_test(tc1_1, my_tan_test);

  srunner_set_log(sr, "./test/test.log");
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
