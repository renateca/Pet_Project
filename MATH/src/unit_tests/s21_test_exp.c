#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(maximum) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(minimum) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(int_max) {
  double x = 2147483647;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(test_pos_less_than_one) {
  double x = 7.345e-29;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}

START_TEST(test_neg_less_than_one) {
  double x = -0.767;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}

START_TEST(test_neg) {
  double x = -13.567;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST

START_TEST(test_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST

START_TEST(test_nan_neg) {
  double x = S21_NEGATIVE_ZERO;
  ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), 1e-6);
}
END_TEST

START_TEST(test_inf_pos) {
  double x = S21_INF;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

START_TEST(test_inf_neg) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(exp(x), s21_exp(x));
}
END_TEST

Suite* add_suite_exp(void) {
  Suite* suit = suite_create("exp");
  TCase* tc_core = tcase_create("Core_test_exp");

  tcase_add_test(tc_core, maximum);
  tcase_add_test(tc_core, minimum);
  tcase_add_test(tc_core, int_max);
  tcase_add_test(tc_core, test_neg);
  tcase_add_test(tc_core, test_zero);
  tcase_add_test(tc_core, test_pos_less_than_one);
  tcase_add_test(tc_core, test_neg_less_than_one);
  tcase_add_test(tc_core, test_nan_neg);
  tcase_add_test(tc_core, test_inf_pos);
  tcase_add_test(tc_core, test_inf_neg);

  suite_add_tcase(suit, tc_core);
  return suit;
}

int main() {
  Suite* s;
  int failed = 0;
  SRunner* runner;

  s = add_suite_exp();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}