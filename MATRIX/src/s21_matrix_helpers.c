#include "s21_matrix.h"

// int negativ_size(int rows, int columns) { return rows < 1 || columns < 1; }

int matrix_is_null(matrix_t *A) {
  return (A == NULL || A->matrix == NULL) || (A->columns < 1 || A->rows < 1);
}

int eq_size_matrix(matrix_t *A, matrix_t *B) {
  return (A->rows != B->rows) || (A->columns != B->columns);
}

int nan_or_inf_matrix(matrix_t *A) {
  int res = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns && res != CALCULATION_ERROR; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        res = CALCULATION_ERROR;
      }
    }
  }
  return res;
}

void minors_matrix(int row, int colomns, matrix_t *A, matrix_t *res) {
  int new_row = 0, new_colomns = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    new_colomns = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == colomns) continue;
      res->matrix[new_row][new_colomns] = A->matrix[i][j];
      new_colomns++;
    }
    new_row++;
  }
}

double get_determinant(matrix_t *A) {
  double res = 0;
  if (A->rows == 1) {
    res = A->matrix[0][0];
  } else {
    matrix_t minor;
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int i = 0; i < A->columns; i++) {
      minors_matrix(0, i, A, &minor);
      if (i % 2) {
        res -= A->matrix[0][i] * get_determinant(&minor);
      } else {
        res += A->matrix[0][i] * get_determinant(&minor);
      }
    }
    s21_remove_matrix(&minor);
  }
  return res;
}

/*void s21_fill(matrix_t *matrix, double value) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = value;
    }
  }
}*/