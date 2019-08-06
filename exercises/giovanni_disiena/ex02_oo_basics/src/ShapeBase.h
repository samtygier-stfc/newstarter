#ifndef SHAPEBASE_H
#define SHAPEBASE_H

#include <math.h>
#include <memory>
#include <string>

class ShapeBase {
  friend class Shape;
public:
  ShapeBase(unsigned sides, std::string name) : m_sides(sides), m_name(name){};
  virtual double getPerimeter() const = 0;
  virtual double getArea() const = 0;
  std::string getName() const;
  unsigned getSides() const;
private:
  unsigned m_sides;
  std::string m_name;
};

#endif // SHAPEBASE_H