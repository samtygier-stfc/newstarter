#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
public:
  ///default constructor to handle situations when no arguments are given
  Rectangle();
	///constructor to handle squares (one side length given)
  Rectangle(double width);
	///constructor to handle rectangles with the required dimentions
  Rectangle(double width, double height);
	///override the Shape.perimeter() and .area() functions to make the function specific to rectangels
  virtual double perimeter() const override;
  virtual double area() const override;

private:
  double m_width;
  double m_height;
};
#endif // RECTANGLE_H
