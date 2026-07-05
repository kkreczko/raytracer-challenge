#include "../src/ray.h"
#include <gtest/gtest.h>

TEST(Ray, BasicRay) {
    Point origin = Point(1, 2, 3);
    Vector direction = Vector(4, 5, 6);
    Ray r = Ray(origin, direction);
    EXPECT_EQ(r.m_direction, direction);
    EXPECT_EQ(r.m_origin, origin);
}

TEST(Ray, CalculatePosition) {
    Ray r = Ray(Point(2, 3, 4), Vector(1, 0, 0));
    EXPECT_EQ(r.position(0), Point(2, 3, 4));
    EXPECT_EQ(r.position(1), Point(3, 3, 4));
    EXPECT_EQ(r.position(-1), Point(1, 3, 4));
    EXPECT_EQ(r.position(2.5), Point(4.5, 3, 4));
}
