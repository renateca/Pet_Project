#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(fabs_test_1) { ck_assert_ldouble_eq(s21_fabs(1.0), fabs(1.0)); }
END_TEST

START_TEST(fabs_test_2) {
  ck_assert_ldouble_eq(s21_fabs(-1.000005), fabs(-1.000005));
}
END_TEST

START_TEST(fabs_test_3) { ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0)); }
END_TEST

START_TEST(fabs_test_4) { ck_assert_ldouble_eq(s21_fabs(-0.0), fabs(-0.0)); }
END_TEST

START_TEST(fabs_test_5) {
  ck_assert_ldouble_eq(s21_fabs(S21_INF), fabs(S21_INF));
}
END_TEST

START_TEST(fabs_test_6) {
  ck_assert(isinf(-S21_INF));
  ck_assert(s21_fabs(-S21_INF) == fabs(-S21_INF));
}
END_TEST

START_TEST(fabs_test_7) { ck_assert_ldouble_nan(s21_fabs(S21_NAN)); }
END_TEST

START_TEST(fabs_test_8) {
  ck_assert_ldouble_eq(s21_fabs(1000.042), fabs(1000.042));
}
END_TEST

START_TEST(fabs_test_9) {
  ck_assert_ldouble_eq(s21_fabs(-1000.042), fabs(-1000.042));
}
END_TEST

START_TEST(fabs_test_10) {
  ck_assert_ldouble_eq(s21_fabs(987633.465), fabs(987633.465));
}
END_TEST

Suite *add_suite_fabs(void) {
  Suite *suit = suite_create("fabs");
  TCase *tc_core = tcase_create("Core_test_fabs");

  tcase_add_test(tc_core, fabs_test_1);
  tcase_add_test(tc_core, fabs_test_2);
  tcase_add_test(tc_core, fabs_test_3);
  tcase_add_test(tc_core, fabs_test_4);
  tcase_add_test(tc_core, fabs_test_5);
  tcase_add_test(tc_core, fabs_test_6);
  tcase_add_test(tc_core, fabs_test_7);
  tcase_add_test(tc_core, fabs_test_8);
  tcase_add_test(tc_core, fabs_test_9);
  tcase_add_test(tc_core, fabs_test_10);

  suite_add_tcase(suit, tc_core);
  return suit;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = add_suite_fabs();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}