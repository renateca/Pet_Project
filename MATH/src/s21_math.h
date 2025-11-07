#ifndef S21_MATH_H
#define S21_MATH_H
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_E 2.718281828459045
#define S21_PI 3.141592653589793
#define S21_PI_12 (S21_PI / 12.F)
#define S21_PI_6 (S21_PI / 6.F)
#define S21_PI_2 (S21_PI / 2.F)
#define S21_SQRT_3 (1.732050807569F)
#define S21_EPS 1e-17
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_NEGATIVE_ZERO -0.0
#define S21_POSITIVE_ZERO 0.0
#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_SQRT_EPS 1e-20l
#define TEST_EPS 1e-6l
#define S21_ISNAN __builtin_isnan
#define S21_ISINF __builtin_isinf

int s21_abs(int x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
#endif  // S21_MATH_H