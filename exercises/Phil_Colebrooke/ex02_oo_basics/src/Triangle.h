#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

#include <math.h>

class Triangle : public Shape {
private:
  const double m_base;
  const double m_height;

public:
  /// Constructor
  Triangle(double height, double base);

  /// Calculates the perimeter of the triangle
  double getPerimeter() const override;

  /// Calculates the area of the triangle
  double getArea() const override;
};

#endif // TRIANGLE_H
