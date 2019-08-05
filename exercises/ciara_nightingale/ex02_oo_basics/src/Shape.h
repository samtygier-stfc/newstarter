#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
public:
  Shape();
  Shape(std::string type, int sides);
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  std::string getType() const;
  int getSides() const;

private:
  std::string m_type;
  int m_sides;
};
#endif // SHAPE_H
