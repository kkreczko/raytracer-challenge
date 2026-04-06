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

TEST(Canvas, writePixel) {
    Canvas c = Canvas(10, 20);
    Color red = Color(1, 0, 0);
    c.writePixelAt(red, 2, 3);
    EXPECT_TRUE(c.getPixelAt(2, 3) == red);
}

TEST(Canvas, writeAllPixels) {
    Canvas c = Canvas(10, 20);
    Color red = Color(1, 0, 0);
    c.writeAllPixelsTo(red);
    int redCounter = 0;
    for (int x = 0; x < c.m_width; x++) {
        for (int y = 0; y < c.m_height; y++) {
            if (c.getPixelAt(x, y) == red) redCounter++;
        }
    }
    EXPECT_EQ(redCounter, 200);
}

TEST(CanvasPPM, canvasToPPMBasic) {
    Canvas c = Canvas(5, 3);
    std::string ppm = c.toPPM();
    std::istringstream stream(ppm);
    std::string line1, line2, line3;
    std::getline(stream, line1);
    std::getline(stream, line2);
    std::getline(stream, line3);
    EXPECT_EQ(line1, "P3");
    EXPECT_EQ(line2, "5 3");
    EXPECT_EQ(line3, "255");
}

TEST(CanvasPPM, canvasToPPM) {
    Canvas c = Canvas(5, 3);
    Color c1 = Color(1.5, 0, 0);
    Color c2 = Color(0, 0.5, 0);
    Color c3 = Color(-0.5, 0, 1);
    c.writePixelAt(c1, 0, 0);
    c.writePixelAt(c2, 2, 1);
    c.writePixelAt(c3, 4, 2);
    std::string ppm = c.toPPM();
    std::istringstream stream(ppm);
    std::string line1, line2, line3, line4, line5, line6;
    std::getline(stream, line1);
    std::getline(stream, line2);
    std::getline(stream, line3);
    std::getline(stream, line4);
    std::getline(stream, line5);
    std::getline(stream, line6);
    EXPECT_EQ(line4, "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
    EXPECT_EQ(line5, "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0");
    EXPECT_EQ(line6, "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");
}

TEST(CanvasPPM, splittingLines) {
    Canvas c = Canvas(10, 2);
    c.writeAllPixelsTo(Color(1, 0.8, 0.6));
    std::string ppm = c.toPPM();
    std::istringstream stream(ppm);
    std::string line1, line2, line3, line4, line5, line6, line7;
    std::getline(stream, line1);
    std::getline(stream, line2);
    std::getline(stream, line3);
    std::getline(stream, line4);
    std::getline(stream, line5);
    std::getline(stream, line6);
    std::getline(stream, line7);
    EXPECT_EQ(line4, "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    EXPECT_EQ(line5, "153 255 204 153 255 204 153 255 204 153 255 204 153");
    EXPECT_EQ(line6, "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    EXPECT_EQ(line7, "153 255 204 153 255 204 153 255 204 153 255 204 153");
}

TEST(CanvasPPM, ppmEndsWithNewLine) {
    Canvas c = Canvas(5, 3);
    std::string ppm = c.toPPM();
    EXPECT_EQ(ppm.back(), '\n');
}