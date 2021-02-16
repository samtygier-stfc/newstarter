#include "Shape.h"

class Rectangle : public Shape {

private:
  double side1, side2;

public:
  Rectangle(const std::string &, const unsigned int &, const double &, 
            const double &);
  Rectangle(const std::string &, const unsigned int &, const double &);
  void calculatePerimeter() override { perimeter = 2 * (side1 + side2); }
  void calculateArea() override { area = side1 * side2; }
};