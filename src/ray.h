#pragma once
#include "tuple.h"

struct Ray {
    Point m_origin;
    Vector m_direction;

    Ray(Point origin, Vector direction)
        : m_origin(origin), m_direction(direction) {}
};
