#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
public:
  ///default constructor if no arguments are provided 
  Shape();
	///constructor to give the shape a type and the number of sides
  Shape(std::string type, int sides);
	///initialise the perimeter and area functions 
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
	///function to provide read only acess to the type and number of sides variables
  std::string getType() const;
  int getSides() const;

private:
  std::string m_type;
  int m_sides;
};
#endif // SHAPE_H
