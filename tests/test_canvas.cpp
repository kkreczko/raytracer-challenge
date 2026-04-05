#include "../src/canvas.h"
#include <gtest/gtest.h>

TEST(Canvas, createCanvas) {
    Canvas c = Canvas(10, 20);
    int colorCounter = 0;
    for (int  width = 0; width < 10; width++) {
        for (int height = 0; height < 20; height++) {
            if (c.getPixelAt(width, height) == Color(0, 0, 0))
                colorCounter += 1;
        } 
    }
    EXPECT_TRUE(colorCounter == 200);
    EXPECT_TRUE(c.m_height == 20);
    EXPECT_TRUE(c.m_width == 10);
}

TEST(Canvas, writePixel) {
    Canvas c = Canvas(10, 20);
    Color red = Color(1, 0, 0);
    c.writePixelAt(red, 2, 3);
    EXPECT_TRUE(c.getPixelAt(2, 3) == red);
}