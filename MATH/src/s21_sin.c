#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0.0;

  if (S21_ISINF(x) || S21_ISNAN(x)) {
    result = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);

    while (x > S21_PI) {
      x -= 2 * S21_PI;
    }

    while (x < -S21_PI) {
      x += 2 * S21_PI;
    }

    result = x;
    int factorial = 1;
    long double term = x;

    while (s21_fabs(term) > S21_EPS) {
      term = (-term * x * x) / ((2 * factorial + 1) * (2 * factorial));
      result += term;
      factorial++;
    }
  }

  return result;
}
