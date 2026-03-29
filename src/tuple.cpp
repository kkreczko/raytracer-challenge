#include "tuple.h"

double const EPSILON = VERY_SMALL_NUMBER;

bool float_equal(double x, double y) { return std::fabs(x - y) < EPSILON; }

bool Tuple::isPoint() { return m_w == 1.0; }
bool Tuple::isVector() { return m_w == 0.0; }

bool Tuple::operator==(const Tuple &rhs) {
  return float_equal(this->m_x, rhs.m_x) && float_equal(this->m_y, rhs.m_y) &&
         float_equal(this->m_z, rhs.m_z) && float_equal(this->m_w, rhs.m_w);
}
