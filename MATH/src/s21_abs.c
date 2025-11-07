#include "s21_math.h"

int s21_abs(int x) {
  long int result = 0;

  result = x < 0 ? -x : x;

  return result;
}
