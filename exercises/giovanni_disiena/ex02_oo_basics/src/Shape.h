#ifndef SHAPE_H
#define SHAPE_H

#include "ShapeBase.h"

class Shape {
public:
  Shape(ShapeBase *);
  Shape(const Shape &);
  ~Shape();
  Shape &operator=(const Shape &);
  void makeUnique();
  private:
  ShapeBase *m_shapeBasePointer;
};

#endif // SHAPE_H