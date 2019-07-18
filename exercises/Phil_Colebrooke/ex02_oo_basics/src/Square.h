#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
  const double m_sideLength;

public:
  /// Constructor
  Square(double sideLength);

  /// Calculates the perimeter of the square
  double getPerimeter() const override;

  /// Calculates the area of the square
  double getArea() const override;
};

#endif // SQUARE_H
