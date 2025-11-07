#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 0;
  int temp = 0;
  if ((base < 0 && (int)exp - exp != 0) || (base == S21_NAN) ||
      (exp == S21_NAN)) {
    res = S21_NAN;
  } else if ((base == 1 || S21_ISNAN(exp)) || (exp == 0 || S21_ISNAN(base))) {
    res = 1.0;
  } else if ((base == S21_POSITIVE_ZERO && (exp > 0 && (int)exp % 2 != 0)) ||
             (base == 0 && (exp > 0 && (int)exp % 2 == 0)) ||
             (s21_fabs(base) > 1 && exp == S21_INF_NEG) ||
             (s21_fabs(base) < 1 && S21_ISINF(exp)) ||
             (base == S21_INF_NEG && (exp < 0 && (int)exp % 2 != 0)) ||
             (base == S21_INF_NEG && (exp < 0 && (int)exp % 2 == 0)) ||
             (base == S21_INF_POS && exp < 0)) {
    res = S21_POSITIVE_ZERO;
  } else {
    if (base < 0) {
      if ((int)exp % 2 != 0) {
        temp = 1;
      }
      base = s21_fabs(base);
    }
    res = temp ? -s21_exp(exp * s21_log(base)) : s21_exp(exp * s21_log(base));
  }
  return res;
}