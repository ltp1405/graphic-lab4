#pragma once

#include <GL/gl.h>
class Shape {
  double offsetX, offsetY, offsetZ;
  double currentAngle, rotateX, rotateY, rotateZ;

protected:
  void applyTransformation();

public:
  virtual void draw(GLuint texture) = 0;
  virtual void moveTo(double x, double y, double z);
  virtual void rotateTo(double angle, double x, double y, double z);
  virtual ~Shape() {}
};
