#ifndef SHAPEBASE_H
#define SHAPEBASE_H

#include <math.h>
#include <string>

class ShapeBase {
public:
  // constructs and initialises ShapeBase object
  ShapeBase(unsigned int sides, std::string name);
  // functions to get member variables
  virtual double getPerimeter() const = 0;
  virtual double getArea() const = 0;
  std::string getName() const;
  unsigned int getNumberOfSides() const;

private:
  unsigned int m_numberOfSides;
  std::string m_name;
};

#endif // SHAPEBASE_H