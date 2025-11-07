#include "s21_math.h"

long double s21_log(double x) {
  long double result;

  if (x == S21_INF_POS)
    result = x;
  else if (x < 0)
    result = S21_NAN;
  else {
    result = 0.0;
    int e_repeat = 0;

    for (; x >= S21_E; e_repeat++) x /= S21_E;

    for (int i = 0; i < 100; i++) {
      long double compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }

    result += e_repeat;
  }

  return result;
}
