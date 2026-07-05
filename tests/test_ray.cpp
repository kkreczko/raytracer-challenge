#include "../src/ray.h"
#include <gtest/gtest.h>

TEST(Ray, BasicRay) {
    Point origin = Point(1, 2, 3);
    Vector direction = Vector(4, 5, 6);
    Ray r = Ray(origin, direction);
    EXPECT_EQ(r.m_direction, direction);
    EXPECT_EQ(r.m_origin, origin);
}
