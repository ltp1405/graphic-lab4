#include "vector2d.h"
#include <math.h>

Vector2d::Vector2d(int x, int y) : x(x), y(y) {}

Vector2d::Vector2d() : Vector2d(0, 0) {}

int Vector2d::getX() const { return x; }

int Vector2d::getY() const { return y; }

std::ostream &operator<<(std::ostream &os, const Vector2d &v) {
  os << "(" << v.x << ", " << v.y << ")";
  return os;
}

Vector2d Vector2d::operator-(const Vector2d &other) const {
  return Vector2d(x - other.x, y - other.y);
}

double Vector2d::magnitude() const { return sqrt(x * x + y * y); }

Vector2d Vector2d::operator+(const Vector2d &other) const {
  return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator*(double scalar) const {
  return Vector2d(x * scalar, y * scalar);
}
