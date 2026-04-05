#ifndef CANVAS_H
#define CANVAS_H

#include <tuple.h>
#include <vector>

struct Canvas {
    int m_width, m_height;
    std::vector<std::vector<Color>> m_pixels;
    Canvas(int width, int height) : m_width(width), m_height(height), 
                                    m_pixels(m_height, std::vector<Color>(m_width, Color(0, 0, 0))) {}
    
    Color &getPixelAt(const int x, const int y) ;
};

#endif