#include "Shape.h"

class Circle : public Shape {

private:
  double radius;

public:
  Circle(const std::string &, const unsigned int &, const double &);
  void calculatePerimeter() override { perimeter = 2.0 * M_PI * radius; }
  void calculateArea() override { area = M_PI * radius  * radius; }
};