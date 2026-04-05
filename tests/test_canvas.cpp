#include "../src/canvas.h"
#include <gtest/gtest.h>

TEST(Canvas, createCanvas) {
    Canvas c = Canvas(10, 20);
    int colorCounter = 0;
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            if (c.getPixelAt(x, y) == Color(0, 0, 0))
                colorCounter += 1;
        } 
    }
    EXPECT_TRUE(colorCounter == 200);
    EXPECT_TRUE(c.m_height == 20);
    EXPECT_TRUE(c.m_width == 10);
}