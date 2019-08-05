#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
  ShapeBase *clone() const override;
  double calculatePerimeter() override;
  double calculateArea() override;

private:
  // something here
};

#endif // RECTANGLE_H