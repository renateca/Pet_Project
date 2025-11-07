#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define ERROR 2

START_TEST(test_s21_create_matrix) {
  matrix_t my_matrix;
  int ret = s21_create_matrix(4, 4, &my_matrix);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&my_matrix);

  ret = s21_create_matrix(-4, 4, &my_matrix);
  ck_assert_int_eq(ret, 1);

  ret = s21_create_matrix(0, 4, &my_matrix);
  ck_assert_int_eq(ret, 1);

  ret = s21_create_matrix(-4, 0, &my_matrix);
  ck_assert_int_eq(ret, 1);

  long long i = 2222222222222222222;
  ret = s21_create_matrix(2, i, &my_matrix);
  ck_assert_int_eq(ret, 1);

  float g = NAN;
  ret = s21_create_matrix(2, g, &my_matrix);
  ck_assert_int_eq(ret, 1);

  ret = s21_create_matrix(g, 2, &my_matrix);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(test_s21_eq_matrix) {
  matrix_t matrix_1, matrix_2;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  int ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(10, 10, &matrix_2);
  ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  matrix_1.matrix[2][3] = -7;
  ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  matrix_1.matrix[2][3] = -7;
  matrix_2.matrix[2][3] = -7;
  ret = s21_eq_matrix(&matrix_1, &matrix_2);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_s21_sum_matrix) {
  matrix_t matrix_1, matrix_2, res_my, res_org;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  int ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 5, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 5, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      res_org.matrix[i][j] = i + j;
    }
  }
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
      res_org.matrix[i][j] = (i + j) * 2;
    }
  }
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
      res_org.matrix[i][j] = (i + j) * 2;
    }
  }
  matrix_1.matrix[0][2] = INFINITY;
  ret = s21_sum_matrix(&matrix_1, &matrix_2, &res_org);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_sub_matrix) {
  matrix_t matrix_1, matrix_2, res_my, res_org;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  int ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 5, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_2);
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      res_org.matrix[i][j] = i + j;
    }
  }
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
    }
  }
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
    }
  }
  matrix_1.matrix[2][2] = NAN;
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_mult_number) {
  matrix_t matrix_1, res_my, res_org;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &res_org);
  int ret = s21_mult_number(&matrix_1, 5, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      res_org.matrix[i][j] = (i + j) * (-3);
    }
  }
  ret = s21_mult_number(&matrix_1, -3, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
    }
  }
  ret = s21_mult_number(&matrix_1, 0, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  matrix_t matrix_2;
  s21_create_matrix(4, 4, &matrix_1);
  s21_create_matrix(4, 4, &matrix_2);
  s21_create_matrix(4, 4, &res_org);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1.matrix[i][j] = i + j;
      matrix_2.matrix[i][j] = i + j;
    }
  }
  matrix_1.matrix[2][2] = NAN;
  ret = s21_sub_matrix(&matrix_1, &matrix_2, &res_my);
  ck_assert_int_eq(ret, 2);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  matrix_t matrix = {NULL, 0, 0};
  matrix_t matrix2 = {NULL, 0, 0};
  matrix_t matrix3 = {NULL, 0, 0};

  s21_create_matrix(2, 2, &matrix);
  s21_create_matrix(3, 3, &matrix3);

  int counter = 1;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix.matrix[i][j] = counter++;
    }
  }

  double test_number = 0.5;
  int result = s21_mult_number(&matrix, test_number, &matrix2);

  ck_assert_int_eq(matrix2.matrix[0][1], 1);
  ck_assert_int_eq(matrix2.matrix[1][1], 2);
  ck_assert_int_eq(result, OK);

  s21_remove_matrix(&matrix2);

  result = s21_mult_number(&matrix3, test_number, &matrix2);

  ck_assert_int_eq(result, OK);

  matrix3.rows = 0;

  s21_remove_matrix(&matrix2);

  result = s21_mult_number(&matrix3, test_number, &matrix2);

  ck_assert_int_eq(result, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix3);
}
END_TEST

START_TEST(test_s21_mult_matrix) {
  matrix_t mat_1, mat_2, res_mat, res_org;

  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(2, 2, &res_org);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat_1.matrix[i][j] = i + j + 1;
      mat_2.matrix[i][j] = i + j + 1;
    }
  }
  res_org.matrix[0][0] = 5;
  res_org.matrix[0][1] = 8;
  res_org.matrix[1][0] = 8;
  res_org.matrix[1][1] = 13;
  int ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(3, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(3, 2, &res_org);
  ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, OK);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 7, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  ret = s21_mult_matrix(&mat_1, &mat_2, &res_mat);
  ck_assert_int_eq(ret, CALCULATION_ERROR);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
}
END_TEST

START_TEST(test_s21_transpose) {
  matrix_t mat_1, res_mat, res_org;

  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &res_org);
  mat_1.matrix[0][0] = 1;
  mat_1.matrix[0][1] = 2;
  mat_1.matrix[1][0] = 3;
  mat_1.matrix[1][1] = 4;
  res_org.matrix[0][0] = 1;
  res_org.matrix[0][1] = 3;
  res_org.matrix[1][0] = 2;
  res_org.matrix[1][1] = 4;
  int ret = s21_transpose(&mat_1, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);

  double matrix[2][2] = {
      {1, 2},
      {3, 4},
  };
  double res[2][2] = {{1, 3}, {2, 4}};
  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &res_org);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mat_1.matrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      res_org.matrix[i][j] = res[i][j];
    }
  }
  ret = s21_transpose(&mat_1, &res_mat);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_mat, &res_org);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&res_mat);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_determinant) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  int count = 1;
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = count++;
    }
  }
  matrix.matrix[2][2] = 10;
  double res = 2;
  int ret = s21_determinant(&matrix, &res);
  ck_assert_int_eq(res, -3);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_21_determinant) {
  double determinant = 0;
  matrix_t matrix = {NULL, 0, 0};
  matrix_t matrix2 = {NULL, 0, 0};

  s21_create_matrix(4, 4, &matrix);
  s21_create_matrix(1, 1, &matrix2);

  matrix.matrix[0][0] = 9;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[0][3] = 4;

  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 4;
  matrix.matrix[1][3] = 4;

  matrix.matrix[2][0] = 4;
  matrix.matrix[2][1] = 4;
  matrix.matrix[2][2] = 9;
  matrix.matrix[2][3] = 9;

  matrix.matrix[3][0] = 1;
  matrix.matrix[3][1] = 1;
  matrix.matrix[3][2] = 5;
  matrix.matrix[3][3] = 1;

  int result = s21_determinant(&matrix, &determinant);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(determinant, -578);

  matrix2.matrix[0][0] = 10;
  result = s21_determinant(&matrix2, &determinant);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(determinant, 10);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_s21_calc_complements) {
  double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t matrix, res_org, res_my;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = s21_calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  double determinant = 0;
  matrix_t matrix = {NULL, 0, 0};
  matrix_t matrix2 = {NULL, 0, 0};

  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 2, &matrix2);

  int counter = 1;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix.matrix[i][j] = counter++;
    }
  }

  int result = s21_determinant(&matrix, &determinant);

  ck_assert_int_eq(result, OK);

  result = s21_determinant(&matrix2, &determinant);

  ck_assert_int_eq(result, CALCULATION_ERROR);

  matrix2.rows = 0;

  result = s21_determinant(&matrix2, &determinant);

  ck_assert_int_eq(result, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_s21_inverse_matrix) {
  double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_t matrix, res_org, res_my;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = s21_inverse_matrix(&matrix, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_21_inverse_matrix) {
  matrix_t matrix = {NULL, 0, 0};
  matrix_t matrix2 = {NULL, 0, 0};

  s21_create_matrix(3, 3, &matrix);

  matrix.matrix[0][0] = 4;
  matrix.matrix[0][1] = -2;
  matrix.matrix[0][2] = 1;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 6;
  matrix.matrix[1][2] = -2;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 0;
  matrix.matrix[2][2] = 0;

  int result = s21_inverse_matrix(&matrix, &matrix2);
  ck_assert_int_eq(matrix2.matrix[0][0], 0);
  ck_assert_int_eq(matrix2.matrix[0][1], 0);
  ck_assert_int_eq(matrix2.matrix[0][2], 1);
  ck_assert_int_eq(matrix2.matrix[1][0], 1);
  ck_assert_int_eq(matrix2.matrix[2][0], 3);
  ck_assert_int_eq(matrix2.matrix[2][2], -13);
  ck_assert_int_eq(result, OK);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 4;
  matrix.matrix[0][2] = 1;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 7;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 3;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 1;

  s21_remove_matrix(&matrix2);

  result = s21_inverse_matrix(&matrix, &matrix2);

  ck_assert_int_eq(result, CALCULATION_ERROR);

  matrix.rows = 2;

  s21_remove_matrix(&matrix2);

  result = s21_inverse_matrix(&matrix, &matrix2);

  ck_assert_int_eq(result, CALCULATION_ERROR);

  matrix.rows = 0;

  s21_remove_matrix(&matrix2);

  result = s21_inverse_matrix(&matrix, &matrix2);

  ck_assert_int_eq(result, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  matrix_t B;
  s21_create_matrix(4, 4, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][1] = 1;
  B.matrix[2][2] = 1;
  B.matrix[3][3] = 1;
  matrix_t expected_result;
  s21_create_matrix(4, 4, &expected_result);
  expected_result.matrix[0][0] = 1;
  expected_result.matrix[1][1] = 1;
  expected_result.matrix[2][2] = 1;
  expected_result.matrix[3][3] = 1;
  matrix_t actual_result;
  s21_sum_matrix(&A, &B, &actual_result);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(expected_result.matrix[i][j],
                          actual_result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(test_s21_mult_matrix_555) {
  matrix_t matrix = {NULL, 0, 0};
  matrix_t matrix2 = {NULL, 0, 0};
  matrix_t matrix3 = {NULL, 0, 0};

  s21_create_matrix(2, 2, &matrix);
  s21_create_matrix(2, 2, &matrix2);

  int counter = 1;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix.matrix[i][j] = counter;
      matrix2.matrix[i][j] = counter++;
    }
  }

  int result = s21_mult_matrix(&matrix, &matrix2, &matrix3);

  ck_assert_int_eq(matrix3.matrix[0][0], 7);
  ck_assert_int_eq(matrix3.matrix[0][1], 10);
  ck_assert_int_eq(matrix3.matrix[1][0], 15);
  ck_assert_int_eq(matrix3.matrix[1][1], 22);
  ck_assert_int_eq(result, OK);

  matrix.columns = 1;

  s21_remove_matrix(&matrix3);

  result = s21_mult_matrix(&matrix, &matrix2, &matrix3);

  ck_assert_int_eq(result, CALCULATION_ERROR);

  //   matrix.rows = 0;

  matrix2.columns = -1;

  s21_remove_matrix(&matrix3);

  result = s21_mult_matrix(&matrix, &matrix2, &matrix3);

  ck_assert_int_eq(result, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix3);
}
END_TEST

Suite *s21_matrix_suite() {
  Suite *s = suite_create("Verter_OK");

  TCase *tc_s21_create_matrix = tcase_create("test_s21_create_matrix");
  suite_add_tcase(s, tc_s21_create_matrix);
  tcase_add_test(tc_s21_create_matrix, test_s21_create_matrix);

  TCase *tc_s21_eq_matrix_test_2 = tcase_create("s21_eq_matrix_test_2");
  suite_add_tcase(s, tc_s21_eq_matrix_test_2);
  tcase_add_test(tc_s21_eq_matrix_test_2, s21_eq_matrix_test_2);

  TCase *tc_s21_eq_matrix = tcase_create("test_s21_eq_matrix");
  suite_add_tcase(s, tc_s21_eq_matrix);
  tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix);

  TCase *tc_s21_sum_matrix = tcase_create("test_s21_sum_matrix");
  suite_add_tcase(s, tc_s21_sum_matrix);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix);

  TCase *tc_s21_sub_matrix = tcase_create("test_s21_sub_matrix");
  suite_add_tcase(s, tc_s21_sub_matrix);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix);

  TCase *tc_s21_mult_number = tcase_create("test_s21_mult_number");
  suite_add_tcase(s, tc_s21_mult_number);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number);

  TCase *tc_s21_mult_number_2 = tcase_create("test_s21_mult_number_2");
  suite_add_tcase(s, tc_s21_mult_number_2);
  tcase_add_test(tc_s21_mult_number_2, test_s21_mult_number_2);

  TCase *tc_s21_mult_matrix = tcase_create("test_s21_mult_matrix");
  suite_add_tcase(s, tc_s21_mult_matrix);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix);

  TCase *tc_s21_transpose = tcase_create("test_s21_transpose");
  suite_add_tcase(s, tc_s21_transpose);
  tcase_add_test(tc_s21_transpose, test_s21_transpose);

  TCase *tc_s21_determinant = tcase_create("test_s21_determinant");
  suite_add_tcase(s, tc_s21_determinant);
  tcase_add_test(tc_s21_determinant, test_s21_determinant);

  TCase *tc_s21_determinant_3 = tcase_create("test_s21_determinant_3");
  suite_add_tcase(s, tc_s21_determinant_3);
  tcase_add_test(tc_s21_determinant_3, test_s21_determinant_3);

  TCase *tc_21_determinant = tcase_create("test_21_determinant");
  suite_add_tcase(s, tc_21_determinant);
  tcase_add_test(tc_21_determinant, test_21_determinant);

  TCase *tc_s21_calc_complements = tcase_create("test_s21_calc_complements");
  suite_add_tcase(s, tc_s21_calc_complements);
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements);

  TCase *tc_s21_inverse_matrix = tcase_create("test_s21_inverse_matrix");
  suite_add_tcase(s, tc_s21_inverse_matrix);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix);

  TCase *tc_21_inverse_matrix = tcase_create("test_21_inverse_matrix");
  suite_add_tcase(s, tc_21_inverse_matrix);
  tcase_add_test(tc_21_inverse_matrix, test_21_inverse_matrix);

  return s;
}

int main() {
  int no_failed = 0;

  Suite *s = s21_matrix_suite();

  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}