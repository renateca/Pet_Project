#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <cmath>
#include <exception>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix;

 public:
  // --------------CONSTRUCTORS
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // ---------------METHODS -------------

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // --------------OPERATORS

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  S21Matrix operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  void operator+=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double num);
  void operator-=(const S21Matrix& other);
  double& operator()(int i, int j);
  double operator()(int i, int j) const;

  // --------------- OTHER METHODS

  void get();
  void memory_allocation(int rows, int cols);
  S21Matrix* createMinor(int rows, int columns, const S21Matrix& A);
  void check_index(int rows, int cols);
  void check_index(int rows, int cols) const;
  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);
  void DelMatrix();
  void SetEl(int i, int j, double num);
};

// void FillMatrix(double* seq, S21Matrix& other);

#endif