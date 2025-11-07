#ifndef _S21_MATRIX_H
#define _S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum res_code { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_transpose(matrix_t *A, matrix_t *result);

/*Проверка на отрицательность значений. ЕСли один из параметров меньше 1, вернет
 * 1*/
int negativ_size(int rows, int columns);

/*Провека матриц на  NULL. Если матрица NULL, вернет 1*/
int matrix_is_null(matrix_t *A);

/*Проверяет равенство сторон матриц. Если они не равны вернет 1*/
int eq_size_matrix(matrix_t *A, matrix_t *B);

/*Проверка матриц на NAN and INF. Если проверка не пройдет вернет 1*/
int nan_or_inf_matrix(matrix_t *A);

/*Создает минор матрицы в новую матрицу*/
void minors_matrix(int row, int colomns, matrix_t *A, matrix_t *res);

/*Основная функция для нахождения определителя. Вся работы происходит тут*/
double get_determinant(matrix_t *A);

void s21_fill(matrix_t *matrix, double value);

// 0 - OK
// 1 - Ошибка, некорректная матрица
// 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т.д.)

#endif