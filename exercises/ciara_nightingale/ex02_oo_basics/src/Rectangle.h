#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
public:
	///Constructor to handle rectangles with the required dimentions.
  Rectangle(double width, double height);
	///Override the Shape.perimeter() and area() functions to make the function specific to rectangels.
  double perimeter() const override;
  double area() const override;

private:
  double const m_width;
  double const m_height;
};
#endif // RECTANGLE_H
