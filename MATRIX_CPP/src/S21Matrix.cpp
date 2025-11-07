#include "S21_matrix.h"
#include "s21_matrix_help.cpp"

S21Matrix::S21Matrix() : S21Matrix(3, 3) {}

S21Matrix::S21Matrix(int rows, int cols) {
  // try {
  this->memory_allocation(rows, cols);
  // } catch (const char *error) {
  //   std::cout << error + std::to_string(rows) + '\t' + std::to_string(cols)
  //             << '\n';
  //   // std::invalid_argument("ERROR");
  // }
}

S21Matrix::~S21Matrix() {
  if (matrix != NULL) DelMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix(other.matrix) {
  other.matrix = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (other.cols_ != cols_ || other.rows_ != rows_) return false;
  bool flag = true;
  for (int i{}; i < cols_; i++) {
    for (int j{}; j < rows_ && flag; j++) {
      if (fabs(other.matrix[i][j] - matrix[i][j]) > 1e-7) flag = false;
    }
  }
  return flag;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (other.cols_ != cols_ || other.rows_ != rows_)
    throw std::invalid_argument("ERROR");

  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix[i][j] += other.matrix[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (other.cols_ != cols_ || other.rows_ != rows_)
    throw std::invalid_argument("ERROR");

  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix[i][j] -= other.matrix[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      matrix[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) throw std::invalid_argument("ERROR");

  int lambda = this->cols_;
  double **result = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    result[i] = new double[other.GetCols()]{};
  }
  for (int r = 0; r < this->rows_; r++) {
    for (int c = 0; c < other.GetCols(); c++) {
      for (int l = 0; l < lambda; l++) {
        result[r][c] += this->matrix[r][l] * other.matrix[l][c];
      }
    }
  }
  for (int i = 0; i < rows_; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  matrix = result;
  this->cols_ = other.cols_;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res{this->cols_, this->rows_};
  for (int i{}; i < rows_; i++) {
    for (int j{}; j < cols_; j++) {
      res.matrix[j][i] = this->matrix[i][j];
    }
  }
  return res;
}

double S21Matrix::Determinant() {
  if (this->rows_ != this->cols_) throw "The matrix is not square.";

  double res = 0;
  if (this->rows_ == 1) {
    res = matrix[0][0];
  } else {
    S21Matrix *minor = 0;
    for (int i = 0; i < this->cols_; i++) {
      minor = createMinor(0, i, *this);
      double det = matrix[0][i] * minor->Determinant();
      if (i % 2) {
        res -= det;
      } else {
        res += det;
      }
      delete minor;
    }
    // delete minor;
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) throw "The matrix is not square.";

  S21Matrix result{rows_, cols_};
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix *minor = createMinor(i, j, *this);
      double determinant = minor->Determinant();
      result.matrix[i][j] = ((i + j) % 2 ? -1 : 1) * determinant;
      delete minor;
    }
  }

  return result;
};

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = this->Determinant();
  if (determinant == 0) {
    throw "Matrix determinant is 0.";
  }

  S21Matrix temp1 = this->CalcComplements();
  S21Matrix result = temp1.Transpose();
  result.MulNumber(1. / determinant);

  return result;
};

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix res = *this;
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix res = *this;
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix res = *this;
  res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res = *this;
  res.MulNumber(num);
  return res;
}

double &S21Matrix::operator()(int i, int j) {
  check_index(i, j);
  return matrix[i][j];
}

double S21Matrix::operator()(int i, int j) const {
  check_index(i, j);
  return matrix[i][j];
}

S21Matrix S21Matrix::operator=(const S21Matrix &other) {
  if (matrix) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }

  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  matrix = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] = 0;
    }
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

void S21Matrix::operator*=(const S21Matrix &other) { MulMatrix(other); }
void S21Matrix::operator*=(const double num) { MulNumber(num); }
void S21Matrix::operator+=(const S21Matrix &other) { SumMatrix(other); }
void S21Matrix::operator-=(const S21Matrix &other) { SubMatrix(other); }
