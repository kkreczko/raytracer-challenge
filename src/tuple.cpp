#include "tuple.h"

bool float_equal(double x, double y) { return std::fabs(x - y) < EPSILON; }

bool Tuple::isPoint() const { return m_w == 1.0; }
bool Tuple::isVector() const { return m_w == 0.0; }

bool Tuple::operator==(const Tuple &rhs) const {
  return float_equal(this->m_x, rhs.m_x) && float_equal(this->m_y, rhs.m_y) &&
         float_equal(this->m_z, rhs.m_z) && float_equal(this->m_w, rhs.m_w);
}

Tuple &Tuple::operator+=(const Tuple &rhs) {
  m_x += rhs.m_x;
  m_y += rhs.m_y;
  m_z += rhs.m_z;
  m_w += rhs.m_w;
  return *this;
}

Tuple &Tuple::operator-=(const Tuple &rhs) {
  m_x -= rhs.m_x;
  m_y -= rhs.m_y;
  m_z -= rhs.m_z;
  m_w -= rhs.m_w;
  return *this;
}

Tuple Tuple::operator+(const Tuple &rhs) const {
  Tuple result = *this;
  result += rhs;
  return result;
}

Tuple Tuple::operator-(const Tuple &rhs) const {
  Tuple result = *this;
  result -= rhs;
  return result;
}

Tuple Tuple::operator-() const {
  return {-m_x, -m_y, -m_z, -m_w};
}

Tuple &Tuple::operator*=(const double scalar) {
  m_x *= scalar;
  m_y *= scalar;
  m_z *= scalar;
  m_w *= scalar;
  return *this;
}

Tuple Tuple::operator*(const double scalar) const {
  return {m_x * scalar, m_y * scalar,
          m_z * scalar, m_w * scalar};
}

Tuple &Tuple::operator/=(const double scalar) {
  *this *= (1 / scalar);
  return *this;
}

Tuple Tuple::operator/(const double scalar) const {
  Tuple t = *this;
  t /= scalar;
  return t;
}

double Tuple::magnitude() const {
  double vx, vy, vz, vw, result;
  vx = std::pow(m_x, 2);
  vy = std::pow(m_y, 2);
  vz = std::pow(m_z, 2);
  vw = std::pow(m_w, 2);
  result = std::sqrt(vx + vy + vz + vw);
  return result;
}

Tuple &Tuple::normalize() {
  double mag = magnitude();
  m_x /= mag;
  m_y /= mag;
  m_z /= mag;
  m_w /= mag;
  return *this;
}

double Tuple::dot(const Tuple& lhs, const Tuple &rhs) {
  double result;
  result = lhs.m_x * rhs.m_x +
           lhs.m_y * rhs.m_y +
           lhs.m_z * rhs.m_z +
           lhs.m_w * rhs.m_w;
  return result; 
}

Vector Vector::cross(const Vector &lhs, const Vector &rhs) {
  double res_x, res_y, res_z;
  res_x = lhs.m_y * rhs.m_z - lhs.m_z * rhs.m_y;
  res_y = lhs.m_z * rhs.m_x - lhs.m_x * rhs.m_z;
  res_z = lhs.m_x * rhs.m_y - lhs.m_y * rhs.m_x;
  return {res_x, res_y, res_z};
}

Tuple Tuple::operator*(const Tuple& rhs) const {
  Color result = Color(m_x * rhs.m_x,
                       m_y * rhs.m_y, 
                       m_z * rhs.m_z);
  return result;
}