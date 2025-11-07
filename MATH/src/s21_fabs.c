#include "s21_math.h"

long double s21_fabs(double x) {
  long double result = 0.0;

  // Проверка на NAN
  if (S21_ISNAN(x)) {
    result = x;
  } else {
    // Проверка на ноль и отрицательный ноль
    if (x == 0.0) {
      result = 0.0;
    } else {
      // Обработка отрицательной бесконечности
      if (x < 0) {
        result = -x;  // Если x отрицательное, меняем знак числа
      } else {
        result = x;
      }
    }
  }

  return result;
}
