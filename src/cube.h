#pragma once
#include "shape.h"

class Cube : public Shape {
public:
  void draw(GLuint texture) override;
};
