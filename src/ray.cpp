#include "ray.h"

Point Ray::position(double distance) const {
    return this->m_origin + this->m_direction * distance;
}
