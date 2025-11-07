#include "S21_matrix.h"

void S21Matrix::get() {
  std::cout << rows_ << std::endl;
  std::cout << cols_ << std::endl;

  for (int i = 0; rows_ > i; i++) {
    for (int j = 0; cols_ > j; j++) {
      std::cout << matrix[i][j];
    }
    std::cout << "\n";
  }
}

void S21Matrix::memory_allocation(int rows, int cols) {
  if (rows < 1 || cols < 1) throw "INCORRECT SIZE ";
  rows_ = rows;
  cols_ = cols;
  matrix = new double *[rows] {};
  for (int i = 0; i < rows; i++) {
    matrix[i] = new double[cols]{};
  }
}

void S21Matrix::DelMatrix() {
  if (matrix != NULL) {
    if (matrix[0]) {
      for (int i{}; i < rows_; i++) delete[] matrix[i];
    }
    delete[] matrix;
  }
  rows_ = 0;
  cols_ = 0;
}

S21Matrix *S21Matrix::createMinor(int rows, int columns, const S21Matrix &A) {
  S21Matrix *minor = new S21Matrix{A.GetRows() - 1, A.GetCols() - 1};
  int index_rows = 0, index_columns = 0;
  for (int i = 0; i < A.GetRows(); i++) {
    if (i == rows) {
      continue;
    }
    index_columns = 0;
    for (int j = 0; j < A.GetCols(); j++) {
      if (j == columns) {
        continue;
      }
      (*minor)(index_rows, index_columns) = A(i, j);
      index_columns++;
    }
    index_rows++;
  }
  return minor;
}

void S21Matrix::check_index(int rows, int cols) {
  if (rows < 0 || rows > rows_ - 1) {
    throw std::out_of_range(
        "Invalid argument i - number of rows out of range [0:" +
        std::to_string(rows_ - 1) + "]");
  }
  if (cols < 0 || cols > cols_ - 1) {
    throw std::out_of_range(
        "Invalid argument j - number of cols out of range [0:" +
        std::to_string(cols_ - 1) + "]");
  }
}

void S21Matrix::check_index(int rows, int cols) const {
  if (rows < 0 || rows > rows_ - 1) {
    throw std::out_of_range(
        "Invalid argument i - number of rows out of range [0:" +
        std::to_string(rows_ - 1) + "]");
  }
  if (cols < 0 || cols > cols_ - 1) {
    throw std::out_of_range(
        "Invalid argument j - number of cols out of range [0:" +
        std::to_string(cols_ - 1) + "]");
  }
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows_ == rows) return;

  double **newMatrix = new double *[rows];
  for (int i = 0; i < rows; ++i) {
    newMatrix[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      if (i < rows_ && j < cols_) {
        newMatrix[i][j] = matrix[i][j];
      } else {
        newMatrix[i][j] = 0.0;
      }
    }
  }

  DelMatrix();
  matrix = newMatrix;
  rows_ = rows;
}

void S21Matrix::SetCols(int cols) {
  if (cols_ == cols) return;

  double **newMatrix = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    newMatrix[i] = new double[cols]{};
    for (int j = 0; j < cols; ++j) {
      if (i < rows_ && j < cols_) {
        newMatrix[i][j] = matrix[i][j];
      } else {
        newMatrix[i][j] = 0.0;
      }
    }
  }

  DelMatrix();
  matrix = newMatrix;
  cols_ = cols;
}

void S21Matrix::SetEl(int i, int j, double num) { matrix[i][j] = num; }