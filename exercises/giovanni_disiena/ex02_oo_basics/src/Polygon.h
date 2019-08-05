#ifndef POLYGON_H
#define POLYGON_H

#include "ShapeBase.h"

class Polygon : public ShapeBase {
public:
  virtual ShapeBase *clone() const = 0;
  virtual double calculatePerimeter() = 0;
  virtual double calculateArea() = 0;

private:
  unsigned int m_numberSides;
};

#endif // POLYGON_H