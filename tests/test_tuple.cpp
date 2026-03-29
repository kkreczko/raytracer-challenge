#include "../src/tuple.h"
#include <gtest/gtest.h>

TEST(test_tuple, isPoint) {
  Tuple t = {4.3, -4.2, 3.1, 1.0};
  EXPECT_TRUE(t.isPoint());
  EXPECT_FALSE(t.isVector());
}

TEST(test_tuple, isVector) {
  Tuple t = {4.3, -4.2, 3.1, 0.0};
  EXPECT_TRUE(t.isVector());
  EXPECT_FALSE(t.isPoint());
}

TEST(test_point, constructPoint) {
  Point p = {4, -4, 3};
  Tuple t = {4, -4, 3, 1};
  EXPECT_TRUE(p == t);
  EXPECT_TRUE(t == p);
  EXPECT_TRUE(p.isPoint());
  EXPECT_FALSE(p.isVector());
}

TEST(test_vector, constructVector) {
  Vector v = {4, -4, 3};
  Tuple t = {4, -4, 3, 0};
  EXPECT_TRUE(v == t);
  EXPECT_TRUE(t == v);
  EXPECT_TRUE(v.isVector());
  EXPECT_FALSE(v.isPoint());
}
