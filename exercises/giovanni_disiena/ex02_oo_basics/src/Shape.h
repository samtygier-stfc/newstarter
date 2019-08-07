#ifndef SHAPE_H
#define SHAPE_H

#include <memory>
#include "ShapeBase.h"

class Shape {
public:
  Shape(std::shared_ptr<ShapeBase>);
  Shape(const Shape &);
  Shape &operator=(const Shape &);
  std::shared_ptr<ShapeBase> getBase() const;
private:
  std::shared_ptr<ShapeBase> m_shapeBasePointer;
};

#endif // SHAPE_H