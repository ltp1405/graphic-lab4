#include <GL/freeglut_std.h>
#include <GL/gl.h>

#include "cone.h"

void Cone::draw() {
  applyTransformation();
  glutSolidCone(1, 1, 20, 20);
}
