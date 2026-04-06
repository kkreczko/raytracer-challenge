#ifndef CANVAS_H
#define CANVAS_H

#include <tuple.h>
#include <vector>
#include <fstream>

int clamp(double value) {
    if (value < 0) return 0;
    if (value > 1.0) return 255;
    return static_cast<int>(std::round(value * 255));
}

struct Canvas {
    int m_width, m_height;
    std::vector<std::vector<Color>> m_pixels;
    Canvas(int width, int height) : m_width(width), m_height(height), 
                                    m_pixels(m_width, std::vector<Color>(m_height, Color(0, 0, 0))) {}
    
    Color &getPixelAt(const int width, const int height);
    void writePixelAt(const Color &pixel, const int width, const int height);
    void writeAllPixelsTo(const Color &pixel);

    std::string toPPM() const;
    void saveToFile(const std::string& filename) const;
};

#endif