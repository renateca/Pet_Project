#include "s21_math.h"

long double s21_atan(double x) {
  int sign = 0;
  int size = 0;
  long double result = 0;
  long double x_squared = 0;

  if (x < 0.0) {
    x = -x;
    sign |= 1;
  }
  if (x > s21_pow(10, 7)) {
    x = s21_pow(10, 7);
  }
  if (x > 1.0) {
    x = 1.0 / x;
    sign |= 2;
  }

  while (x > S21_PI_12) {  // Сокращение области определения
    size++;
    result = 1.0 / (x + S21_SQRT_3);
    x = ((x * S21_SQRT_3) - 1.0) * result;
  }

  x_squared = s21_pow(x, 2);  // Аппроксимация
  result = x * (0.55913709 / (1.4087812 + x_squared) + 0.60310579 -
                0.05160454 * x_squared);

  while (size > 0) {
    result += S21_PI_6;
    size--;
  }

  if (sign & 2) {
    result = S21_PI_2 - result;  // Инверсия
  }

  if (sign & 1) {
    result = -result;  // Знак
  }

  return result;
}
