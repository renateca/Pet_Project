#include <check.h>
#include <math.h>

#include "../s21_math.h"
START_TEST(floor_test_1) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test_2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test_3) {
  double x = -4.7;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test_4) {
  double x = 4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test_5) {
  double x = 732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test_6) {
  double x = -4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test_7) {
  double x = -732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test_8) {
  double x = S21_NEGATIVE_ZERO;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test_9) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(floor_test_10) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(floor_test_11) {
  double x = NAN;
  ck_assert_ldouble_nan(s21_floor(x));
}
END_TEST

START_TEST(floor_test_with_loop) {
  for (double x = -1000; x <= 1000; x += 0.5) {
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
  }
}
END_TEST

START_TEST(test_zero) { ck_assert_ldouble_eq(floor(0), s21_floor(0)); }
END_TEST

START_TEST(test_neg) { ck_assert_ldouble_eq(floor(-1234), s21_floor(-1234)); }
END_TEST

START_TEST(test_pos) { ck_assert_ldouble_eq(floor(1234), s21_floor(1234)); }
END_TEST

START_TEST(test_normal) { ck_assert_ldouble_eq(floor(1.7), s21_floor(1.7)); }
END_TEST

START_TEST(test_normal_negative) {
  ck_assert_int_eq(floor(-1.7), s21_floor(-1.7));
}
END_TEST

START_TEST(test_normal_negative_1) {
  ck_assert_int_eq(floor(-0.7), s21_floor(-0.7));
}
END_TEST

START_TEST(test_normal_above_1) {
  ck_assert_ldouble_eq(floor(14.7), s21_floor(14.7));
}
END_TEST
START_TEST(test_lesser_than_1) {
  ck_assert_ldouble_eq(floor(0.7), s21_floor(0.7));
}
END_TEST

START_TEST(test_positive_inf) {
  ck_assert_ldouble_eq(floor(S21_INF), s21_floor(S21_INF));
}
END_TEST
START_TEST(test_negative_inf) {
  ck_assert_ldouble_eq(floor(-S21_INF), s21_floor(-S21_INF));
}
END_TEST

START_TEST(test_nan) { ck_assert_ldouble_nan(s21_floor(S21_NAN)); }
END_TEST

START_TEST(test_negative_nan) { ck_assert_ldouble_nan(s21_floor(-S21_NAN)); }
END_TEST

START_TEST(test_high_accuracy) {
  ck_assert_ldouble_eq(floor(0.123456907912345), s21_floor(0.123456907912345));
}
END_TEST

START_TEST(test_tolerance_pos) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(floor(a * i), s21_floor(a * i), TEST_EPS);
}
END_TEST

START_TEST(test_tolerance_neg) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(floor(-a * i), s21_floor(-a * i), TEST_EPS);
}
END_TEST

Suite *add_suite_floor(void) {
  Suite *suit = suite_create("floor");
  TCase *tc_core = tcase_create("Core_test_floor");

  tcase_add_test(tc_core, floor_test_1);
  tcase_add_test(tc_core, floor_test_2);
  tcase_add_test(tc_core, floor_test_3);
  tcase_add_test(tc_core, floor_test_4);
  tcase_add_test(tc_core, floor_test_5);
  tcase_add_test(tc_core, floor_test_6);
  tcase_add_test(tc_core, floor_test_7);
  tcase_add_test(tc_core, floor_test_8);
  tcase_add_test(tc_core, floor_test_9);
  tcase_add_test(tc_core, floor_test_10);
  tcase_add_test(tc_core, floor_test_11);
  tcase_add_test(tc_core, floor_test_with_loop);
  tcase_add_test(tc_core, test_zero);
  tcase_add_test(tc_core, test_neg);
  tcase_add_test(tc_core, test_pos);
  tcase_add_test(tc_core, test_normal);
  tcase_add_test(tc_core, test_positive_inf);
  tcase_add_test(tc_core, test_negative_inf);
  tcase_add_test(tc_core, test_nan);
  tcase_add_test(tc_core, test_negative_nan);
  tcase_add_test(tc_core, test_high_accuracy);
  tcase_add_test(tc_core, test_normal_negative);
  tcase_add_test(tc_core, test_normal_negative_1);
  tcase_add_test(tc_core, test_normal_above_1);
  tcase_add_test(tc_core, test_lesser_than_1);
  tcase_add_loop_test(tc_core, test_tolerance_pos, 0, 520);
  tcase_add_loop_test(tc_core, test_tolerance_neg, 0, 520);

  suite_add_tcase(suit, tc_core);

  return suit;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = add_suite_floor();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}