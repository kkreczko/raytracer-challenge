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

TEST(Matrix, canInvertTrue) {
    Matrix A = Matrix(4, 4,
                      std::vector<double>(
                          {6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6}));
    EXPECT_EQ(A.det(), -2120);
    EXPECT_TRUE(A.canInvert());
}

TEST(Matrix, canInvertFalse) {
    Matrix A = Matrix(4, 4,
                      std::vector<double>({-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1,
                                           -5, 0, 0, 0, 0}));
    EXPECT_EQ(A.det(), 0);
    EXPECT_FALSE(A.canInvert());
}

TEST(Matrix, inverseBasic) {
    Matrix A = Matrix(4, 4,
                      std::vector<double>({-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6,
                                           -7, 1, -3, 7, 4}));

    Matrix B = A.inverse();
    EXPECT_EQ(A.det(), 532);
    EXPECT_EQ(A.cofactor(2, 3), -160);

    double first_expected = B[3, 2];
    EXPECT_EQ(first_expected, static_cast<double>(-160.0 / 532.0));

    double second_expected = B[2, 3];
    EXPECT_EQ(second_expected, static_cast<double>(105.0 / 532.0));

    Matrix expected_inverted =
        Matrix(4, 4,
               std::vector<double>({0.21805, 0.45113, 0.24060, -0.04511,
                                    -0.80827, -1.45677, -0.44361, 0.52068,
                                    -0.07895, -0.22368, -0.05263, 0.19737,
                                    -0.52256, -0.81391, -0.30075, 0.30639}));
    EXPECT_TRUE(B == expected_inverted);
}

TEST(Matrix, inverseSecond) {
    Matrix A = Matrix(4, 4, std::vector<double>({8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4}));
    Matrix B = A.inverse();
    Matrix expected = Matrix(4, 4, std::vector<double>({-0.15385, -0.15385, -0.28205, -0.53846, -0.07692, 0.12308, 0.02564, 0.03077, 0.35897, 0.35897, 0.43590, 0.92308, -0.69231, -0.69231, -0.76923, -1.92308}));
    EXPECT_TRUE(B == expected);
}

TEST(Matrix, inverseThird) {
    Matrix A = Matrix(4, 4, std::vector<double>({9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2}));
    Matrix B = A.inverse();
    Matrix expected = Matrix(4, 4, std::vector<double>({-0.04074, -0.07778, 0.14444, -0.22222,
                                                         -0.07778, 0.03333, 0.36667, -0.33333,
                                                         -0.02901, -0.14630, -0.10926, 0.12963,
                                                         0.17778, 0.06667, -0.26667, 0.33333}));
    EXPECT_TRUE(B == expected);
}

TEST(Matrix, multiplyByInverse) {
    Matrix A = Matrix(4, 4, std::vector<double>({3, -9, 7, 3,
                                                  3, -8, 2, -9,
                                                  -4, 4, 4, 1,
                                                  -6, 5, -1, 1}));
    Matrix B = Matrix(4, 4, std::vector<double>({ 8, 2, 2, 2,
                                                  3, -1, 7, 0,
                                                  5, 4, 6, -2,
                                                  0, 5, 0, 5}));
    Matrix C = A * B;
    EXPECT_TRUE(C * B.inverse() == A);
}
