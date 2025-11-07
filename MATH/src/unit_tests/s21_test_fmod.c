#include <check.h>
#include <math.h>

#include "../s21_math.h"
START_TEST(fmod_test_1) {
  double x = 12.0;
  double y = 4.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(fmod_test_2) {
  double x = 0.0;
  double y = 5.5;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(fmod_test_3) {
  double x = S21_INF;
  double y = 5.5;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test_4) {
  double x = -S21_INF;
  double y = 5.5;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test_5) {
  double x = 5.8;
  double y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test_6) {
  double x = 5.8;
  double y = S21_NEGATIVE_ZERO;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test_7) {
  double x = 5.8;
  double y = S21_INF;
  double epsilon = 1e-6;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), epsilon);
}
END_TEST

START_TEST(fmod_test_8) {
  double x = 5.8;
  double y = -S21_INF;
  double epsilon = 1e-6;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), epsilon);
}
END_TEST

START_TEST(fmod_test_9) {
  double x = S21_NAN;
  double y = 12.6;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test_10) {
  double x = 5.5;
  double y = S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

Suite *add_suite_fmod(void) {
  Suite *suit = suite_create("fmod");
  TCase *tc_core = tcase_create("Core_test_fmod");

  tcase_add_test(tc_core, fmod_test_1);
  tcase_add_test(tc_core, fmod_test_2);
  tcase_add_test(tc_core, fmod_test_3);
  tcase_add_test(tc_core, fmod_test_4);
  tcase_add_test(tc_core, fmod_test_5);
  tcase_add_test(tc_core, fmod_test_6);
  tcase_add_test(tc_core, fmod_test_7);
  tcase_add_test(tc_core, fmod_test_8);
  tcase_add_test(tc_core, fmod_test_9);
  tcase_add_test(tc_core, fmod_test_10);

  suite_add_tcase(suit, tc_core);
  return suit;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = add_suite_fmod();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}