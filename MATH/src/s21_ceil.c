#include "s21_math.h"
long double s21_ceil(double x) {
  // Преобразование x в тип long long для сохранения целой части
  long long intPart = (long long)x;
  // Инициализация переменной result
  long double result = 0.0;

  // Проверка на Inf, 0, отрицательный ноль (S21_NEGZERO) и NaN
  if (S21_ISINF(x) || x == 0 || x == S21_NEGATIVE_ZERO || S21_ISNAN(x))
    result = x;
  else {
    if (x < 0) {
      result = (long double)intPart;
    } else {
      // Если x отрицательное, проверить, равна ли x целой части intPart
      if (x == (long double)intPart)
        result = (long double)intPart;
      else
        // Если x не равна целой части intPart, увеличить intPart на 1 и
        // присвоить result
        result = (long double)(intPart + 1);
    }
  }

  return result;
}
