#ifndef SHAPEBASE_H
#define SHAPEBASE_H

#include <math.h>
#include <string>

class ShapeBase {
public:
  // constructs and initialises ShapeBase object
  ShapeBase(unsigned int, std::string);
  // functions to get member variables
  virtual double getPerimeter() const = 0;
  virtual double getArea() const = 0;
  std::string getName() const;
  unsigned int getSides() const;
private:
  unsigned int m_sides;
  std::string m_name;
};

#endif // SHAPEBASE_H