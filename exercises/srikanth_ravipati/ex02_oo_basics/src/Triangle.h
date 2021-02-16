#include "Shape.h"

class Triangle : public Shape {

private:
  double base, height;

public:
  Triangle(const std::string &, const unsigned int &, const double &, 
           const double &);
  void calculatePerimeter() override 
    { perimeter = base + 2 * sqrt(height * height + (base * base) / 4); }
  void calculateArea() override { area = 0.5 * base * height; }
};