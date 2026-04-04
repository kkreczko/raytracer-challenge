#include "../src/tuple.h"
#include <gtest/gtest.h>

TEST(Tuple, isPoint) {
  Tuple t = {4.3, -4.2, 3.1, 1.0};
  EXPECT_TRUE(t.isPoint());
  EXPECT_FALSE(t.isVector());
}

TEST(Tuple, isVector) {
  Tuple t = {4.3, -4.2, 3.1, 0.0};
  EXPECT_TRUE(t.isVector());
  EXPECT_FALSE(t.isPoint());
}

TEST(Tuple, identicalTuplesAreEqual) {
  Tuple a = {1, 1, 1, 1};
  Tuple b = {1, 1, 1, 1};
  Tuple c = {1, 1, 1, 0};
  EXPECT_TRUE(a == b);
  EXPECT_FALSE(a == c);
}

TEST(Point, constructPoint) {
  Point p = {4, -4, 3};
  Tuple t = {4, -4, 3, 1};
  EXPECT_TRUE(p == t);
  EXPECT_TRUE(t == p);
  EXPECT_TRUE(p.isPoint());
  EXPECT_FALSE(p.isVector());
}

TEST(Vector, constructVector) {
  Vector v = {4, -4, 3};
  Tuple t = {4, -4, 3, 0};
  EXPECT_TRUE(v == t);
  EXPECT_TRUE(t == v);
  EXPECT_TRUE(v.isVector());
  EXPECT_FALSE(v.isPoint());
}

TEST(Tuple, addTuplesIntoPoint) {
  Tuple a = {3, -2, 5, 1};
  Tuple b = {-2, 3, 1, 0};
  EXPECT_TRUE(a + b == Point(1, 1, 6));
}

TEST(Point, subtractPointsIntoVector) {
  Point a = {3, 2, 1};
  Point b = {5, 6, 7};
  EXPECT_TRUE(a - b == Vector(-2, -4, -6));
}

TEST(Point, subtractVectorFromPointIntoPoint) {
  Point a = {3, 2, 1};
  Vector b = {5, 6, 7};
  EXPECT_TRUE(a - b == Point(-2, -4, -6));
}

TEST(Vector, subtractVectorFromVectorIntoVector) {
  Vector a = {3, 2, 1};
  Vector b = {5, 6, 7};
  EXPECT_TRUE(a - b == Vector(-2, -4, -6));
}

TEST(Tuple, negateTuple) {
  Tuple a = {1, -2, 3, -4};
  EXPECT_TRUE(-a == Tuple(-1, 2, -3, 4));
}

TEST(Tuple, scalarMultiplication) {
  Tuple a = {1, -2, 3, -4};
  EXPECT_TRUE(a * 3.5 == Tuple(3.5, -7, 10.5, -14));
}

TEST(Tuple, fractionMultiplication) {
  Tuple a = {1, -2, 3, -4};
  EXPECT_TRUE(a * 0.5 == Tuple(0.5, -1, 1.5, -2));
}

TEST(Tuple, scalarDivision) {
  Tuple a = {1, -2, 3, -4};
  EXPECT_TRUE(a / 2 == Tuple(0.5, -1, 1.5, -2));
}

TEST(Vector, magnitude1) {
  Vector v = Vector(1, 0, 0);
  EXPECT_TRUE(v.magnitude() == 1);
}

TEST(Vector, magnitude2) {
  Vector v = Vector(0, 1, 0);
  EXPECT_TRUE(v.magnitude() == 1);
}

TEST(Vector, magnitude3) {
  Vector v = Vector(0, 0, 1);
  EXPECT_TRUE(v.magnitude() == 1);
}

TEST(Vector, magnitude4) {
  Vector v = Vector(1, 2, 3);
  EXPECT_TRUE(v.magnitude() == std::sqrt(14));
}

TEST(Vector, magnitude5) {
  Vector v = Vector(-1, -2, -3);
  EXPECT_TRUE(v.magnitude() == std::sqrt(14));
}

TEST(Misc, floatEqualityCheck) {
  double a = 0.1;
  double b = 0.2;
  EXPECT_TRUE(float_equal(a + b, 0.3));
}
