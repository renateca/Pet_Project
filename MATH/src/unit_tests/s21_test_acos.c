#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(task_s21_acos) {
  double nul = 0;
  double f = 1.02165484;
  double w = 0.354;
  double minus_w = -0.354;
  double ff = 0.1256154;
  double minus_f = -0.1256154;
  double big_f = 1256154123456789;
  double minus_big_f = -1256154123456789;
  ck_assert_ldouble_nan(s21_acos(f));
  ck_assert_double_eq_tol(s21_acos(w), acos(w), 1e-6);
  ck_assert_double_eq_tol(s21_acos(nul), acos(nul), 1e-6);
  ck_assert_double_eq_tol(s21_acos(minus_w), acos(minus_w), 1e-6);
  ck_assert_double_eq_tol(s21_acos(ff), acos(ff), 1e-6);
  ck_assert_double_eq_tol(s21_acos(minus_f), acos(minus_f), 1e-6);
  ck_assert_double_nan(s21_acos(big_f));
  ck_assert_double_nan(s21_acos(minus_big_f));
}
END_TEST

Suite *add_suite_acos(void) {
  Suite *suit = suite_create("acos");
  TCase *tc_core = tcase_create("Core_test_acos");

  tcase_add_test(tc_core, task_s21_acos);

  suite_add_tcase(suit, tc_core);
  return suit;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = add_suite_acos();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}