#include <check.h>
#include <math.h>

#include "../s21_math.h"

START_TEST(abs_test_1) { ck_assert_int_eq(s21_abs(-1), abs(-1)); }
END_TEST

START_TEST(abs_test_2) { ck_assert_int_eq(s21_abs(5), abs(5)); }
END_TEST

START_TEST(abs_test_3) {
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

START_TEST(abs_test_4) { ck_assert_int_eq(s21_abs(-0xA13), abs(-0xA13)); }
END_TEST

START_TEST(abs_test_5) { ck_assert_int_eq(s21_abs(13), abs(13)); }
END_TEST

START_TEST(abs_test_6) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(abs_test_7) { ck_assert_int_eq(s21_abs(-05), abs(-05)); }
END_TEST

START_TEST(abs_test_8) {
  ck_assert_int_eq(s21_abs(-00002345670), abs(-00002345670));
}
END_TEST

START_TEST(abs_test_9) { ck_assert_int_eq(s21_abs(123456789), abs(123456789)); }
END_TEST

START_TEST(abs_test_10) { ck_assert_int_eq(s21_abs(100), abs(100)); }
END_TEST

START_TEST(abs_test_11) { ck_assert_int_eq(s21_abs(-100), abs(-100)); }
END_TEST

START_TEST(abs_test_12) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

Suite *add_suite_abs(void) {
  Suite *suit = suite_create("abs");
  TCase *tc_core = tcase_create("Core_test_abs");

  tcase_add_test(tc_core, abs_test_1);
  tcase_add_test(tc_core, abs_test_2);
  tcase_add_test(tc_core, abs_test_3);
  tcase_add_test(tc_core, abs_test_4);
  tcase_add_test(tc_core, abs_test_5);
  tcase_add_test(tc_core, abs_test_6);
  tcase_add_test(tc_core, abs_test_7);
  tcase_add_test(tc_core, abs_test_8);
  tcase_add_test(tc_core, abs_test_9);
  tcase_add_test(tc_core, abs_test_10);
  tcase_add_test(tc_core, abs_test_11);
  tcase_add_test(tc_core, abs_test_12);

  suite_add_tcase(suit, tc_core);
  return suit;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = add_suite_abs();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}