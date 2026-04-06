#include "canvas.h"

int clamp(double value) {
    if (value < 0) return 0;
    if (value > 1.0) return 255;
    return static_cast<int>(std::round(value * 255));
}

Color &Canvas::getPixelAt(int x, int y) {
    return m_pixels[y][x];
}

const Color &Canvas::getPixelAt(int x, int y) const {
    return m_pixels[y][x];
}

void Canvas::writePixelAt(const Color &pixel, int x, int y) {
    m_pixels[y][x] = pixel;
}

void Canvas::writeAllPixelsTo(const Color &pixel) {
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            writePixelAt(pixel, x, y);
        }
    }
}

std::string Canvas::toPPM() const {
    std::ostringstream oss;
    oss << "P3\n" << m_width << " " << m_height << "\n255\n";
    for (int y = 0; y < m_height; y++) {
        std::ostringstream row;
        for (int x = 0; x < m_width; x++) {
            if (x > 0) row << " ";
            const Color& c = getPixelAt(x, y);
            row << clamp(c.red()) << " "
                << clamp(c.green()) << " "
                << clamp(c.blue());
        }
        std::string line = row.str();
        while (line.length() > 70) {
            int cut = line.rfind(' ', 69);
            oss << line.substr(0, cut) << "\n";
            line = line.substr(cut + 1);
        }
        oss << line << "\n";
    }
    return oss.str();
}

void Canvas::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    file << toPPM();
}
