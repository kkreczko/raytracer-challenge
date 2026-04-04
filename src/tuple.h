#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>

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

  Tuple &operator/=(const double scalar);
  Tuple operator/(const double scalar) const;

  double magnitude() const;
  Tuple &normalize();

  static double dot(const Tuple &lhs, const Tuple &rhs);
};

struct Point : Tuple {
  Point(double x, double y, double z) : Tuple(x, y, z, 1.0) {}
};

struct Vector : Tuple {
  Vector(double x, double y, double z) : Tuple(x, y, z, 0.0) {}

  static Vector cross(const Vector &lhs, const Vector &rhs);
};

#endif
