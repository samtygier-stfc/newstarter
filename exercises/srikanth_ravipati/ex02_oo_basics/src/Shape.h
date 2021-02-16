#include <iostream>
#include <cmath>

class Shape {

protected:
  std::string type;
  unsigned int nSides;
  double perimeter;
  double area;

public:
  Shape(const std::string &, const unsigned int &);

  virtual void calculatePerimeter(){}
  virtual void calculateArea(){}
  void calculateInfo();

  std::string getType() const { return type; }
  unsigned int get_N_Sides() const { return nSides; }
  double getPerimeter() const { return perimeter; }
  double getArea() const { return area; }

  bool isSameType(const std::string &inputType) const 
    { return type == inputType; }
  bool hasEqual_N_Sides(const unsigned int &input_N_Sides) const 
    { return nSides == input_N_Sides; }

  void printInfo() const;
};