#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0;
  if (S21_ISNAN(x) || x < 0) {
    res = S21_NAN;
  } else if (x == S21_POSITIVE_ZERO) {
    res = S21_POSITIVE_ZERO;
  } else if (x == S21_INF_POS) {
    res = S21_INF_POS;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}