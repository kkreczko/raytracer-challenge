#include "canvas.h"

Color &Canvas::getPixelAt(const int width, const int height) {
    return m_pixels[width][height];
}

void Canvas::writePixelAt(const Color &pixel, const int width, const int height) {
    m_pixels[width][height] = pixel;
}

void Canvas::writeAllPixelsTo(const Color &pixel) {}

std::string Canvas::toPPM() const {
    
}

void Canvas::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    file << toPPM();
}
