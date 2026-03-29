#include "tuple.h"

bool Tuple::isPoint() { return m_w == 1.0; }
bool Tuple::isVector() { return m_w == 0.0; }

bool Tuple::operator==(const Tuple &rhs) {
  return this->m_x == rhs.m_x && this->m_y == rhs.m_y && this->m_z == rhs.m_z &&
         this->m_w == rhs.m_w;
}
