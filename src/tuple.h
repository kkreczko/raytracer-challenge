#ifndef TUPLE_H
#define TUPLE_H

class Tuple {
  double m_x, m_y, m_z, m_w;

public:
  Tuple(double x, double y, double z, double w)
      : m_x(x), m_y(y), m_z(z), m_w(w) {}

  bool isPoint();
  bool isVector();

  virtual ~Tuple() = default;

  bool operator==(const Tuple &rhs);
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
