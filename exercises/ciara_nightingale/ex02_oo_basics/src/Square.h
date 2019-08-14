#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square : public Shape {
public:
		///Constructor to handle squares with the required dimentions.
  Square(double sideLength);
  /// Override the Shape.perimeter() and area() functions to make the function
  /// specific to squares.
  double perimeter() const override;
  double area() const override;

private:
  double const m_sideLength;
};
#endif // SQUARE_H