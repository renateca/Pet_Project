#include "s21_matrix.h"

#include "s21_matrix_helpers.c"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    result->matrix = NULL;
    return INCORRECT_MATRIX;
  }
  int res = OK;
  double **matrix = (double **)calloc(rows, sizeof(double *));
  double *values = (double *)calloc(rows * columns, sizeof(double));
  if (matrix && values) {
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; i < rows; i++) {
      matrix[i] = values + columns * i;
    }
    result->matrix = matrix;
  } else {
    res = INCORRECT_MATRIX;
    result->matrix = NULL;
  }
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    if (A->matrix[0]) free(A->matrix[0]);
    free(A->matrix);
    if (A->rows) A->rows = 0;

    if (A->columns) A->columns = 0;

    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (matrix_is_null(A) || eq_size_matrix(A, B) || matrix_is_null(B))
    return FAILURE;

  int res = SUCCESS;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns && res != FAILURE; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        res = FAILURE;
      }
    }
  }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (matrix_is_null(A) || matrix_is_null(B)) return INCORRECT_MATRIX;
  if (nan_or_inf_matrix(A) || nan_or_inf_matrix(B) || eq_size_matrix(A, B))
    return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (matrix_is_null(A) || matrix_is_null(B)) return INCORRECT_MATRIX;
  if (nan_or_inf_matrix(A) || nan_or_inf_matrix(B) || eq_size_matrix(A, B))
    return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (matrix_is_null(A)) return INCORRECT_MATRIX;
  if (nan_or_inf_matrix(A)) return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (matrix_is_null(A) || matrix_is_null(B)) return INCORRECT_MATRIX;
  if (nan_or_inf_matrix(A) || nan_or_inf_matrix(B) || (A->columns != B->rows))
    return CALCULATION_ERROR;

  s21_create_matrix(A->rows, B->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      double var = 0;
      for (int g = 0; g < A->columns; g++) {
        var += A->matrix[i][g] * B->matrix[g][j];
      }
      result->matrix[i][j] = var;
    }
  }
  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (matrix_is_null(A)) return INCORRECT_MATRIX;

  s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (matrix_is_null(A) || A->rows == 0) return INCORRECT_MATRIX;
  if (nan_or_inf_matrix(A) || A->columns != A->rows) return CALCULATION_ERROR;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else
    *result = get_determinant(A);

  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (matrix_is_null(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);

  matrix_t minor;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      minors_matrix(i, j, A, &minor);
      result->matrix[i][j] =
          get_determinant(&minor) * (double)((i + j) % 2 ? -1 : 1);
      s21_remove_matrix(&minor);
    }
  }
  // s21_remove_matrix(&minor);
  return 0;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (matrix_is_null(A) || A->rows == 0) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  double det = 0;
  s21_determinant(A, &det);
  if (det == 0) return CALCULATION_ERROR;
  matrix_t tmp_1, tmp_2;
  s21_calc_complements(A, &tmp_1);
  s21_transpose(&tmp_1, &tmp_2);
  s21_mult_number(&tmp_2, 1 / det, result);

  s21_remove_matrix(&tmp_1);
  s21_remove_matrix(&tmp_2);

  return OK;
}

// int main(){
//     matrix_t x, y, res;
//     s21_create_matrix(3, 3, &x);

//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             x.matrix[i][j] = j + 1;
//         }
//     }

//     s21_create_matrix(3, 3, &y);

//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             y.matrix[i][j] = j + 1;
//         }
//     }

//     s21_create_matrix(3, 3, &res);
//     // s21_remove_matrix(&x);
//     // s21_remove_matrix(&y);
//     // s21_sum_matrix(&x, &y, &res);

//     double det = 0;
//     int a = s21_inverse_matrix(&y, &res);
//     int b = s21_determinant(&y, &det);
//     printf("%d"  "%d", a, b);

//     for (int i = 0; i < 3; i++){
//        printf("\n");
//       for (int j = 0; j < 3; j++){
//           printf("%f  ", res.matrix[i][j]);
//         }
//     }

//     return 0;
// }