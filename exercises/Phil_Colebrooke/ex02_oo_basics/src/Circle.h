#ifndef CIRCLE_H
#define CIRCLE_H

#define _USE_MATH_DEFINES

#include "Shape.h"

#include <cmath>

class Circle : public Shape {
private:
  const double m_radius;

public:
  /// Constructor
  Circle(double radius);

  /// Calculates the circumference of the circle
  double getPerimeter() override;

  /// Calculates the area of the circle
  double getArea() override;
};

#endif // CIRCLE_H
