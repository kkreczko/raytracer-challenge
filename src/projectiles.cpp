#include "canvas.h"
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
  Canvas canvas = Canvas(1920, 1080);
  canvas.writeAllPixelsTo(BLACK);
  Projectile proj =
      Projectile(Point(0, 0.001, 0), Vector(1, 1, 0).normalize() * 23);
  Environment env = Environment(Vector(0, -0.1, 0), Vector(-0.01, 0, 0));

  while (!(proj.m_position.m_y <= 0)) {
    int x = proj.m_position.getXPosApprox();
    int y = canvas.m_height - proj.m_position.getYPosApprox();
    if (x >= 0 && x < canvas.m_width && y >= 0 && y < canvas.m_height)
      canvas.writePixelAt(RED, x, y);
    proj = tick(proj, env);
  }

  canvas.saveToFile("projectile.ppm");
}
