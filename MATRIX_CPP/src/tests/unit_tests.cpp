#include "../S21_matrix.h"
#include "gtest/gtest.h"

void fillMatrix(double *seq, S21Matrix &other) {
  int n = 0;
  for (int i = 0; i < other.GetRows(); i++) {
    for (int j = 0; j < other.GetCols(); j++) {
      // other(i, j) = seq[n++];
      other.SetEl(i, j, seq[n++]);
    }
  }
}

TEST(S21MatrixTests, constructors_test) {
  S21Matrix mat1;
  S21Matrix mat2{3, 3};
  S21Matrix mat3{mat2};
  ASSERT_TRUE(mat1.GetCols() == mat2.GetCols());
  ASSERT_TRUE(mat2.GetCols() == mat3.GetCols());
  int rows = mat3.GetRows();
  int cols = mat3.GetCols();
  S21Matrix mat4{std::move(mat3)};
  ASSERT_TRUE(mat4.GetRows() == rows);
  ASSERT_TRUE(mat4.GetCols() == cols);
  ASSERT_TRUE(mat3.GetRows() == 0);
  ASSERT_TRUE(mat3.GetCols() == 0);
}

TEST(S21MatrixTests, EqualTest) {
  int size = 4;
  S21Matrix mat1{size, size};
  S21Matrix mat2{size, size};
  S21Matrix mat3{size, size};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat1(i, j) = 1;
      mat2(i, j) = 1;
      mat3(i, j) = 2;
    }
  }
  ASSERT_TRUE(mat1.EqMatrix(mat2));
  ASSERT_FALSE(mat2.EqMatrix(mat3));
}

TEST(S21MatrixTests, SumTest) {
  int size = 4;
  S21Matrix mat1{size, size};
  S21Matrix mat2{size, size};
  S21Matrix mat3{size, size};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat1(i, j) = 1;
      mat2(i, j) = 1;
      mat3(i, j) = 2;
    }
  }
  mat1.SumMatrix(mat2);
  ASSERT_TRUE(mat1.EqMatrix(mat3));
}

TEST(S21MatrixTests, SubTest) {
  int size = 4;
  S21Matrix mat1{size, size};
  S21Matrix mat2{size, size};
  S21Matrix mat3{size, size};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat1(i, j) = 1;
      mat2(i, j) = 1;
      mat3(i, j) = 0;
    }
  }
  mat1.SubMatrix(mat2);
  ASSERT_TRUE(mat1.EqMatrix(mat3));
}

TEST(S21MatrixTests, MulTest) {
  int size = 2;
  S21Matrix mat1{size, size};
  S21Matrix mat2{size, size};
  S21Matrix mat3{size, size};
  S21Matrix mat4{size, size};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat1(i, j) = 2;
      mat2(i, j) = 3;
      mat3(i, j) = 6;
      mat4(i, j) = 36;
    }
  }
  mat1.MulNumber(3);
  ASSERT_TRUE(mat1.EqMatrix(mat3));
  mat3.MulMatrix(mat2);
  ASSERT_TRUE(mat3.EqMatrix(mat4));
}

TEST(S21MatrixTests, TransTest) {
  int size = 2;
  S21Matrix mat1{size, size};
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;
  S21Matrix mat2 = mat1.Transpose();
  ASSERT_TRUE(mat2(0, 0) == 1);
  ASSERT_TRUE(mat2(0, 1) == 3);
  ASSERT_TRUE(mat2(1, 0) == 2);
  ASSERT_TRUE(mat2(1, 1) == 4);
}

TEST(S21MatrixTests, CompTest) {
  int size = 2;
  S21Matrix mat1{size, size};
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;
  S21Matrix complement = mat1.CalcComplements();
  ASSERT_TRUE(complement(0, 0) == 4);
  ASSERT_TRUE(complement(0, 1) == -3);
  ASSERT_TRUE(complement(1, 0) == -2);
  ASSERT_TRUE(complement(1, 1) == 1);
}

TEST(S21MatrixTests, DetTest) {
  int size = 2;
  S21Matrix mat1{size, size};
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;
  double det = mat1.Determinant();
  ASSERT_TRUE(det == -2);
}

TEST(S21MatrixTests, InverseTest) {
  int size = 2;
  S21Matrix mat1{size, size};
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;
  S21Matrix mat2 = mat1.InverseMatrix();
  ASSERT_TRUE(mat2(0, 0) == -2);
  ASSERT_TRUE(mat2(0, 1) == 1);
  ASSERT_TRUE(mat2(1, 0) == 1.5);
  ASSERT_TRUE(mat2(1, 1) == -0.5);
  mat1.MulMatrix(mat2);
  ASSERT_TRUE(mat1(0, 0) == 1);
  ASSERT_TRUE(mat1(0, 1) == 0);
  ASSERT_TRUE(mat1(1, 0) == 0);
  ASSERT_TRUE(mat1(1, 1) == 1);
}

TEST(S21MatrixTests, OperSumTest) {
  int size = 4;
  S21Matrix mat1{size, size};
  S21Matrix mat2{size, size};
  S21Matrix mat3{size, size};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat1(i, j) = 1;
      mat2(i, j) = 1;
      mat3(i, j) = 2;
    }
  }
  S21Matrix mat4 = mat1 + mat2;
  ASSERT_TRUE(mat4.EqMatrix(mat3));
}

TEST(S21MatrixTests, OperSubTest) {
  int size = 4;
  S21Matrix mat1{size, size};
  S21Matrix mat2{size, size};
  S21Matrix mat3{size, size};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat1(i, j) = 1;
      mat2(i, j) = 1;
      mat3(i, j) = 0;
    }
  }
  S21Matrix mat4 = mat1 - mat2;
  ASSERT_TRUE(mat4.EqMatrix(mat3));
}

TEST(S21MatrixTests, OperMulTest) {
  int size = 2;
  S21Matrix mat1{size, size};
  S21Matrix mat2{size, size};
  S21Matrix mat3{size, size};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat1(i, j) = 2;
      mat2(i, j) = 3;
      mat3(i, j) = 12;
    }
  }
  S21Matrix mat4 = mat1 * mat2;
  ASSERT_TRUE(mat4.EqMatrix(mat3));
}

TEST(S21MatrixTests, OperEqualTest) {
  int size = 4;
  S21Matrix mat1{size, size};
  S21Matrix mat2{size, size};
  S21Matrix mat3{size, size};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      mat1(i, j) = 1;
      mat2(i, j) = 1;
      mat3(i, j) = 2;
    }
  }
  ASSERT_TRUE(mat1 == mat2);
  ASSERT_FALSE(mat2 == mat3);
}

TEST(S21MatrixTests, BaseAssigmentTest) {
  S21Matrix mat1{2, 2};
  S21Matrix mat2{5, 7};
  mat1(0, 0) = 5;
  mat2(0, 0) = 40;
  mat1 = mat2;
  ASSERT_TRUE(mat1(0, 0) == 40);
  ASSERT_TRUE(mat1.GetRows() == 5);
  ASSERT_TRUE(mat1.GetCols() == 7);
}

TEST(S21MatrixTests, SumAssigmentTest) {
  S21Matrix mat1{2, 2};
  S21Matrix mat2{2, 2};
  mat1(0, 0) = 5;
  mat2(0, 0) = 40;
  mat1 += mat2;
  ASSERT_TRUE(mat1(0, 0) == 45);
}

TEST(S21MatrixTests, SubAssigmentTest) {
  S21Matrix mat1{2, 2};
  S21Matrix mat2{2, 2};
  mat1(0, 0) = 5;
  mat2(0, 0) = 40;
  mat1 -= mat2;
  ASSERT_TRUE(mat1(0, 0) == -35);
}

TEST(S21MatrixTests, MulAssigmentTest) {
  S21Matrix mat1{2, 2};
  S21Matrix mat2{2, 2};
  mat1(0, 0) = 5;
  mat2(0, 0) = 40;
  mat1 *= mat2;
  ASSERT_TRUE(mat1(0, 0) == 200);
}

TEST(S21MatrixTests, RoundBraceOperatorTest) {
  S21Matrix mat1{1, 2};
  mat1(0, 0) = 4;
  mat1(0, 1) = 5;
  const S21Matrix mat2{mat1};
  ASSERT_TRUE(mat1(0, 0) == mat2(0, 0));
  ASSERT_TRUE(mat1(0, 1) == mat2(0, 1));
}

TEST(S21MatrixTests, LineCoverage) {
  S21Matrix mat1{1, 2};
  S21Matrix mat2{3, 4};
  S21Matrix nullMatrix;
  try {
    mat1.EqMatrix(mat2);
  } catch (...) {
  }
  try {
    mat1.SumMatrix(mat2);
  } catch (...) {
  }
  try {
    mat1.SubMatrix(mat2);
  } catch (...) {
  }
  try {
    mat1.MulMatrix(mat2);
  } catch (...) {
  }
  try {
    mat1.CalcComplements();
  } catch (...) {
  }
  try {
    mat1.InverseMatrix();
  } catch (...) {
  }
  try {
    nullMatrix.Determinant();
  } catch (...) {
  }
  try {
    mat1 + mat2;
  } catch (...) {
  }
  try {
    mat1 - mat2;
  } catch (...) {
  }
  try {
    mat1 *mat2;
  } catch (...) {
  }
  try {
    mat1 == mat2;
  } catch (...) {
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}