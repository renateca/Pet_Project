#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0.0;

  if (y == 0.0) {
    result = S21_NAN;
  } else if (S21_ISINF(x) || S21_ISNAN(x) || S21_ISNAN(y)) {
    result = S21_NAN;
  } else if (S21_ISINF(y)) {
    result = x;
  } else if (x == 0.0 && y != 0) {
    result = 0.0;
  } else {
    long long int mod = 0;
    mod = x / y;
    result = x - mod * y;
  }

  return result;
}
