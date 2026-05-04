#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>
#include <iostream>

constexpr double EPSILON = 1e-5;

enum class Colors {
    Black,
    Red,
    Green,
    Blue,
};

template <typename T> constexpr bool float_equal(T x, T y) {
    return std::fabs(x - y) < EPSILON;
}

struct Tuple {
    double m_x, m_y, m_z, m_w;

    constexpr Tuple(double x, double y, double z, double w)
        : m_x(x), m_y(y), m_z(z), m_w(w) {}

    bool isPoint() const { return m_w == 1.0; }
    bool isVector() const { return m_w == 0.0; }

    bool operator==(const Tuple &rhs) const;

    Tuple &operator+=(const Tuple &rhs);
    Tuple operator+(const Tuple &rhs) const;

    Tuple &operator-=(const Tuple &rhs);
    Tuple operator-(const Tuple &rhs) const;
    Tuple operator-() const;

    Tuple &operator*=(double scalar);
    Tuple operator*(double scalar) const;
    Tuple operator*(const Tuple &rhs) const;

    Tuple &operator/=(double scalar);
    Tuple operator/(double scalar) const;

    double magnitude() const;
    Tuple normalize() const;

    static double dot(const Tuple &lhs, const Tuple &rhs);

    // std::format
    friend std::ostream &operator<<(std::ostream &os, const Tuple &t) {
        os << "x = " << t.m_x << ", y = " << t.m_y << ", z = " << t.m_z
           << ", w = " << t.m_w;
        return os;
    };
};

struct Point : Tuple {
    Point(double x, double y, double z) : Tuple(x, y, z, 1.0) {}
    Point(const Tuple &t) : Tuple(t.m_x, t.m_y, t.m_z, 1.0) {}
};

struct Vector : Tuple {
    Vector(double x, double y, double z) : Tuple(x, y, z, 0.0) {}
    Vector(const Tuple &t) : Tuple(t.m_x, t.m_y, t.m_z, 0.0) {}

    static Vector cross(const Vector &lhs, const Vector &rhs);
};

struct Color : Tuple {
    Color(double red, double green, double blue)
        : Tuple(red, green, blue, 0.0) {}
    Color(const Tuple &t) : Tuple(t.m_x, t.m_y, t.m_z, 0) {}

    double red() const { return m_x; }
    double green() const { return m_y; }
    double blue() const { return m_z; }

    friend std::ostream &operator<<(std::ostream &os, const Color &c) {
        os << "red = " << c.red() << ", green = " << c.green()
           << ", blue = " << c.blue();
        return os;
    };
};

#endif
