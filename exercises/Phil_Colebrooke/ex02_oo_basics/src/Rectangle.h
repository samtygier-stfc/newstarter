#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
  const double m_length;
  const double m_width;

public:
  /// Constructor
  Rectangle(double length, double width);

  /// Calculates the perimeter of the rectangle
  double getPerimeter() override;

  /// Calculates the area of the rectangle
  double getArea() override;
};

#endif // RECTANGLE_H
