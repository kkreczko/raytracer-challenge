#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>

#define VERY_SMALL_NUMBER std::pow(10, -10)

bool float_equal(double x, double y);

class Tuple {
  double m_x, m_y, m_z, m_w;

public:
  Tuple(double x, double y, double z, double w)
      : m_x(x), m_y(y), m_z(z), m_w(w) {}

  bool isPoint();
  bool isVector();

  virtual ~Tuple() = default;

  bool operator==(const Tuple &rhs) const;
  Tuple &operator+(const Tuple &rhs);
  Tuple &operator-(const Tuple &rhs);
  Tuple &operator-();
};

class Point : public Tuple {
public:
  Point(double x, double y, double z) : Tuple(x, y, z, 1.0) {}
};

class Vector : public Tuple {
public:
  Vector(double x, double y, double z) : Tuple(x, y, z, 0.0) {}
};

#endif
