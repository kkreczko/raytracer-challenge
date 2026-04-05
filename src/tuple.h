#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>
#include <iostream>

constexpr double EPSILON = 1e-10;

bool float_equal(double x, double y);

struct Tuple {
  double m_x, m_y, m_z, m_w;

  Tuple(double x, double y, double z, double w)
      : m_x(x), m_y(y), m_z(z), m_w(w) {}

  bool isPoint() const;
  bool isVector() const;

  bool operator==(const Tuple &rhs) const;

  Tuple &operator+=(const Tuple &rhs);
  Tuple operator+(const Tuple &rhs) const;

  Tuple &operator-=(const Tuple &rhs);
  Tuple operator-(const Tuple &rhs) const;
  Tuple operator-() const;

  Tuple &operator*=(const double scalar);
  Tuple operator*(const double scalar) const;
  Tuple operator*(const Tuple &rhs) const;

  Tuple &operator/=(const double scalar);
  Tuple operator/(const double scalar) const;

  double magnitude() const;
  Tuple &normalize();

  static double dot(const Tuple &lhs, const Tuple &rhs);

  friend std::ostream& operator<<(std::ostream& os, const Tuple &t) {
    os << "x = " << t.m_x << ", y = " << t.m_y << ", z = " << t.m_z << ", w = " << t.m_w;
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
  double &m_red = m_x;
  double &m_green = m_y;
  double &m_blue = m_z;

  Color(double red, double green, double blue) : Tuple(red, green, blue, 0.0) {}
  Color(const Tuple &t) : Tuple(t.m_x, t.m_y, t.m_z, 0) {}

  friend std::ostream& operator<<(std::ostream& os, const Color &c) {
    os << "red = " << c.m_red << ", green = " << c.m_green << ", blue = " << c.m_blue;
    return os;
  };
};

#endif
