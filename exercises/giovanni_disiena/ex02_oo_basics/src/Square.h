#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeBase.h"

class Square : public ShapeBase {
public:
  // constructs Square object
  Square(double length);
  // overriden functions
  double getPerimeter() const override;
  double getArea() const override;
  double getLength() const;
  double getWidth() const;

private:
  const double m_length;
};

#endif // SQUARE_H