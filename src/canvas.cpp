#include "canvas.h"

int clamp(double value) {
    if (value < 0) return 0;
    if (value > 1.0) return 255;
    return static_cast<int>(std::round(value * 255));
}

Color &Canvas::getPixelAt(const int width, const int height) {
    return m_pixels[height][width];
}

void Canvas::writePixelAt(const Color &pixel, const int width, const int height) {
    m_pixels[height][width] = pixel;
}

void Canvas::writeAllPixelsTo(const Color &pixel) {}

std::string Canvas::toPPM() const {
    std::ostringstream oss;
    oss << "P3\n" << m_width << " " << m_height << "\n255\n";
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            const Color& c = m_pixels[y][x];
            oss << clamp(c.red()) << " "
                << clamp(c.green()) << " "
                << clamp(c.blue());
            if (x < m_width - 1) oss << " ";
        }
        oss << "\n";
    }
    return oss.str();
}

void Canvas::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    file << toPPM();
}
