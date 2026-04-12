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
