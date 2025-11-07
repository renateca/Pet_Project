#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(sqrt_test_2) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_5) {
  double x = 0.123456;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_7) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_8) {
  double x = S21_NEGATIVE_ZERO;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_27) {
  double x = 987565.9874641213;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_36) {
  double x = S21_PI / 3;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_37) {
  double x = S21_PI / 6;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_42) {
  double x = S21_PI / 2;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_43) {
  double x = 2 * S21_PI / 3;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_44) {
  double x = 5 * S21_PI / 6;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_45) {
  double x = S21_PI;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(sqrt_test_41) {
  double x = -1.234567;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(test_pos_int_1) {
  double x = 64.;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_pos_int_2) {
  double x = 123456789;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_int_min) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}

START_TEST(test_pos_real_3) {
  double x = 4.163435e-34;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_pos_real_4) {
  double x = 1e-7;
  ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_neg_int) {
  double x = -121.;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(test_neg_real) {
  double x = -2.89;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(test_nan) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(test_pos_inf) {
  double x = S21_INF;
  ck_assert_ldouble_eq(sqrt(x), s21_sqrt(x));
}
END_TEST

START_TEST(test_neg_inf) {
  double x = -S21_INF;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

Suite* add_suite_sqrt(void) {
  Suite* suit = suite_create("sqrt");
  TCase* tc_core = tcase_create("Core_test_sqrt");

  tcase_add_test(tc_core, sqrt_test_2);
  tcase_add_test(tc_core, sqrt_test_5);
  tcase_add_test(tc_core, sqrt_test_7);
  tcase_add_test(tc_core, sqrt_test_8);
  tcase_add_test(tc_core, sqrt_test_27);
  tcase_add_test(tc_core, sqrt_test_36);
  tcase_add_test(tc_core, sqrt_test_37);
  tcase_add_test(tc_core, sqrt_test_41);
  tcase_add_test(tc_core, sqrt_test_42);
  tcase_add_test(tc_core, sqrt_test_43);
  tcase_add_test(tc_core, sqrt_test_44);
  tcase_add_test(tc_core, sqrt_test_45);
  tcase_add_test(tc_core, test_pos_int_1);
  tcase_add_test(tc_core, test_pos_int_2);
  tcase_add_test(tc_core, test_int_min);
  tcase_add_test(tc_core, test_pos_real_3);
  tcase_add_test(tc_core, test_pos_real_4);
  tcase_add_test(tc_core, test_neg_int);
  tcase_add_test(tc_core, test_neg_real);
  tcase_add_test(tc_core, test_nan);
  tcase_add_test(tc_core, test_pos_inf);
  tcase_add_test(tc_core, test_neg_inf);

  suite_add_tcase(suit, tc_core);
  return suit;
}

int main() {
  Suite* s;
  int failed = 0;
  SRunner* runner;

  s = add_suite_sqrt();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}