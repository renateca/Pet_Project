#include "s21_math.h"

long double s21_acos(double x) {
  long double result = S21_PI / 2 - s21_fabs(s21_asin(x));
  return (x < 0) ? (S21_PI - (result)) : (result);
}