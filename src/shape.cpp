#include <GL/gl.h>
#include <GL/glut.h>
#include <shape.h>

void Shape::moveTo(double x, double y, double z) {
  offsetX = x;
  offsetY = y;
  offsetZ = z;
}

void Shape::rotateTo(double angle, double x, double y, double z) {
  currentAngle = angle;
  rotateX = x;
  rotateY = y;
  rotateZ = z;
}

void Shape::applyTransformation() {
  glLoadIdentity();
  glTranslatef(offsetX, offsetY, offsetZ);
  glRotatef(currentAngle, rotateX, rotateY, rotateZ);
}
