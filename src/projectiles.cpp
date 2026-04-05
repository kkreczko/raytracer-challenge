#include <chrono>
#include <iostream>
#include <thread>
#include "tuple.h"

struct Projectile {
    Point m_position;
    Vector m_velocity;

    Projectile(const Point &position, const Vector &velocity) 
                : m_position(position), m_velocity(velocity) {}
};

struct Environment {
    Vector m_gravity;
    Vector m_wind;

    Environment(const Vector &gravity, const Vector &wind) 
                : m_gravity(gravity), m_wind(wind) {}
};

Projectile tick(const Projectile &before, const Environment &env) {
    Point newPosition = before.m_position + before.m_velocity;
    Vector newVelocity = before.m_velocity + env.m_gravity + env.m_wind;
    return {newPosition, newVelocity};
}

int main() {
    Projectile proj = Projectile(Point(0, 1, 0), Vector(1, 1, 0).normalize());
    Environment env = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));

    while (!(proj.m_position.m_y <= 0)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\r\033[K" << proj.m_position << std::flush;
        proj = tick(proj, env);
    }

    std::cout << std::endl;
}