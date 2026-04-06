#ifndef CANVAS_H
#define CANVAS_H

#include <tuple.h>
#include <vector>
#include <fstream>
#include <sstream>

int clamp(double value);

struct Canvas {
    int m_width, m_height;
    std::vector<std::vector<Color>> m_pixels;
    Canvas(int width, int height) : m_width(width), m_height(height), 
                                    m_pixels(m_height, std::vector<Color>(m_width, Color(0, 0, 0))) {}
    
    Color &getPixelAt(int x, int y);
    const Color& getPixelAt(int x, int y) const;
    void writePixelAt(const Color &pixel, int x, int y);
    void writeAllPixelsTo(const Color &pixel);

    std::string toPPM() const;
    void saveToFile(const std::string& filename) const;
};

#endif