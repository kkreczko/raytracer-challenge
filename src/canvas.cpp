#include "canvas.h"

Color &Canvas::getPixelAt(const int x, const int y) {
    return m_pixels[y][x];
}