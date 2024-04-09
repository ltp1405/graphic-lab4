#pragma once

#include <ostream>
class Vector2d {
  int x;
  int y;

public:
  Vector2d(int x, int y);
  Vector2d();
  int getX() const;
  int getY() const;
  friend std::ostream &operator<<(std::ostream &os, const Vector2d &v);
  Vector2d operator-(const Vector2d &other) const;
  double magnitude() const;
  Vector2d operator+(const Vector2d &other) const;
  Vector2d operator*(double scalar) const;
};

std::ostream &operator<<(std::ostream &os, const Vector2d &v);
