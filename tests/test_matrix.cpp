#include "../src/matrix.h"
#include <gtest/gtest.h>
#include <vector>

TEST(Matrix, basicMatrix) {
  Matrix m = Matrix(4, 4,
                    std::vector<double>({1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10,
                                         11, 12, 13.5, 14.5, 15.5, 16.5}));
}
