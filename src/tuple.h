#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>
#include <iostream>

constexpr double EPSILON = 1e-10;

#define BLACK Color(0, 0, 0)
#define RED Color(1, 0, 0)
#define GREEN Color(0, 1, 0)
#define BLUE Color(0, 0, 1)

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

  Tuple &operator*=(double scalar);
  Tuple operator*(double scalar) const;
  Tuple operator*(const Tuple &rhs) const;

  Tuple &operator/=(double scalar);
  Tuple operator/(double scalar) const;

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
  int getXPosApprox() const;
  int getYPosApprox() const;
};

struct Vector : Tuple {
  Vector(double x, double y, double z) : Tuple(x, y, z, 0.0) {}
  Vector(const Tuple &t) : Tuple(t.m_x, t.m_y, t.m_z, 0.0) {}

  static Vector cross(const Vector &lhs, const Vector &rhs);
};

struct Color : Tuple {
  Color(double red, double green, double blue) : Tuple(red, green, blue, 0.0) {}
  Color(const Tuple &t) : Tuple(t.m_x, t.m_y, t.m_z, 0) {}

  double red() const{ return m_x; }
  double green() const { return m_y; }
  double blue() const { return m_z; }

  friend std::ostream& operator<<(std::ostream& os, const Color &c) {
    os << "red = " << c.red() << ", green = " << c.green() << ", blue = " << c.blue();
    return os;
  };
};

#endif
