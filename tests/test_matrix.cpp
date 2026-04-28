#include "../src/matrix.h"
#include <gtest/gtest.h>
#include <vector>

TEST(Matrix, basicMatrix) {
    Matrix m =
        Matrix(4, 4,
               std::vector<double>({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11,
                                    12, 13.5, 14.5, 15.5, 16.5}));
    double item1 = m[0, 0];
    double item2 = m[0, 3];
    double item3 = m[1, 0];
    double item4 = m[1, 2];
    double item5 = m[2, 2];
    double item6 = m[3, 0];
    double item7 = m[3, 2];
    EXPECT_EQ(item1, 1);
    EXPECT_EQ(item2, 4);
    EXPECT_EQ(item3, 5.5);
    EXPECT_EQ(item4, 7.5);
    EXPECT_EQ(item5, 11);
    EXPECT_EQ(item6, 13.5);
    EXPECT_EQ(item7, 15.5);
}

TEST(Matrix, twoByTwoMatrix) {
    Matrix m = Matrix(2, 2, std::vector<int>({-3, 5, 1, -2}));
    int item1 = m[0, 0];
    int item2 = m[0, 1];
    int item3 = m[1, 0];
    int item4 = m[1, 1];
    EXPECT_EQ(item1, -3);
    EXPECT_EQ(item2, 5);
    EXPECT_EQ(item3, 1);
    EXPECT_EQ(item4, -2);
}

TEST(Matrix, threeByThreeMatrix) {
    Matrix m = Matrix(3, 3, std::vector<int>({-3, 5, 0, 1, -2, -7, 0, 1, 1}));
    int item1 = m[0, 0];
    int item2 = m[1, 1];
    int item3 = m[2, 2];
    EXPECT_EQ(item1, -3);
    EXPECT_EQ(item2, -2);
    EXPECT_EQ(item3, 1);
}

TEST(Matrix, equalMatrices) {
    Matrix m1 =
        Matrix(4, 4,
               std::vector<double>({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11,
                                    12, 13.5, 14.5, 15.5, 16.5}));
    Matrix m2 =
        Matrix(4, 4,
               std::vector<double>({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11,
                                    12, 13.5, 14.5, 15.5, 16.5}));
    EXPECT_TRUE(m1 == m2);
}

TEST(Matrix, notEqualMatrices) {
    Matrix m1 =
        Matrix(4, 4,
               std::vector<double>({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11,
                                    12, 13.5, 14.5, 15.5, 16.5}));
    Matrix m2 = Matrix(4, 4,
                       std::vector<double>({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9,
                                            10, 11, 12, 69, 14.5, 15.5, 16.5}));
    EXPECT_FALSE(m1 == m2);
}

TEST(Matrix, multiplyMatrices) {
    Matrix m1 = Matrix(
        4, 4,
        std::vector<double>({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2}));
    Matrix m2 = Matrix(4, 4,
                       std::vector<double>(
                           {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8}));
    Matrix result =
        Matrix(4, 4,
               std::vector<double>({20, 22, 50, 48, 44, 54, 114, 108, 40, 58,
                                    110, 102, 16, 26, 46, 42}));
    EXPECT_EQ(m1 * m2, result);
}

TEST(Matrix, multiplyByTuple) {
    Matrix A = Matrix(
        4, 4,
        std::vector<double>({1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1}));
    Tuple b = Tuple(1, 2, 3, 1);
    Tuple expected = Tuple(18, 24, 33, 1);
    EXPECT_EQ(A * b, expected);
}

TEST(Matrix, identMatrixMultiplication) {
    Matrix A = Matrix(4, 4,
                      std::vector<double>(
                          {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32}));
    Matrix<double> identity_matrix = Matrix<double>::ident(4);
    EXPECT_EQ(A * identity_matrix, A);
}

TEST(Matrix, identMatrixMultipliedByTuple) {
    Matrix<double> identity_matrix = Matrix<double>::ident(4);
    Tuple a = Tuple(1, 2, 3, 4);
    EXPECT_EQ(identity_matrix * a, a);
}

TEST(Matrix, smolDeterminant) {
    Matrix A = Matrix(2, 2, std::vector<double>({1, 5, -3, 2}));
    EXPECT_EQ(A.det(), 17);
}

TEST(Matrix, subMatrixThreeByThree) {
    Matrix A = Matrix(3, 3, std::vector<double>({1, 5, 0, -3, 2, 7, 0, 6, -3}));
    Matrix expected = Matrix(2, 2, std::vector<double>({-3, 2, 0, 6}));
    EXPECT_EQ(A.submatrix(0, 2), expected);
}

TEST(Matrix, subMatrixFourByFour) {
    Matrix A = Matrix(4, 4,
                      std::vector<double>({-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8,
                                           2, -7, 1, -1, 1}));
    Matrix expected =
        Matrix(3, 3, std::vector<double>({-6, 1, 6, -8, 8, 6, -7, -1, 1}));
    EXPECT_EQ(A.submatrix(2, 1), expected);
}

TEST(Matrix, calculateMinor) {
    Matrix A =
        Matrix(3, 3, std::vector<double>({3, 5, 0, 2, -1, -7, 6, -1, 5}));
    EXPECT_EQ(A.minor(1, 0), 25);
}

TEST(Matrix, calculateCofactorAndMinors) {
    Matrix A =
        Matrix(3, 3, std::vector<double>({3, 5, 0, 2, -1, -7, 6, -1, 5}));
    EXPECT_EQ(A.minor(0, 0), -12);
    EXPECT_EQ(A.cofactor(0, 0), -12);
    EXPECT_EQ(A.minor(1, 0), 25);
    EXPECT_EQ(A.cofactor(1, 0), -25);
}

TEST(Matrix, threeByThreeDeterminant) {
    Matrix A = Matrix(3, 3, std::vector<double>({1, 2, 6, -5, 8, -4, 2, 6, 4}));
    EXPECT_EQ(A.cofactor(0, 0), 56);
    EXPECT_EQ(A.cofactor(0, 1), 12);
    EXPECT_EQ(A.cofactor(0, 2), -46);
    EXPECT_EQ(A.det(), -196);
}

TEST(Matrix, fourByFourDeterminant) {
    Matrix A = Matrix(4, 4,
                      std::vector<double>({-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9,
                                           6, -6, 7, 7, -9}));
    EXPECT_EQ(A.cofactor(0, 0), 690);
    EXPECT_EQ(A.cofactor(0, 1), 447);
    EXPECT_EQ(A.cofactor(0, 2), 210);
    EXPECT_EQ(A.cofactor(0, 3), 51);
    EXPECT_EQ(A.det(), -4071);
}
