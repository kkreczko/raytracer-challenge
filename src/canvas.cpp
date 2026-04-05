#include "canvas.h"

Color &Canvas::getPixelAt(const int width, const int height) {
    return m_pixels[width][height];
}

void Canvas::writePixelAt(const Color &pixel, const int width, const int height) {
    m_pixels[width][height] = pixel;
}