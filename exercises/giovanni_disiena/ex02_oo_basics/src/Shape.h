#ifndef SHAPE_H
#define SHAPE_H

#include "ShapeBase.h"
#include "Use.h"

class Shape {
public:
  Shape(ShapeBase *);
  Shape(const Shape &);
  ~Shape();
  Shape &operator=(const Shape &);
  void makeUnique();

private:
  Use m_useObj;
  ShapeBase *m_shapeBasePointer;
};

#endif // SHAPE_H