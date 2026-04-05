#ifndef CANVAS_H
#define CANVAS_H

#include <tuple.h>
#include <vector>

struct Canvas {
    int m_width, m_height;
    std::vector<std::vector<Color>> m_pixels;
    Canvas(int width, int height) : m_width(width), m_height(height), 
                                    m_pixels(m_width, std::vector<Color>(m_height, Color(0, 0, 0))) {}
    
    Color &getPixelAt(const int width, const int height);
    void writePixelAt(const Color &pixel, const int width, const int height);
};

#endif