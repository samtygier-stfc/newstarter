#ifndef SHAPEBASE_H
#define SHAPEBASE_H

#include <string>

class ShapeBase {
  friend class Shape;
public:
  ShapeBase(unsigned sides, std::string name) : m_sides(sides), m_name(name), m_refCount(0){};
  virtual ShapeBase *clone() const = 0;
  virtual ~ShapeBase(); // needs to be defined to avoid compiler error
  virtual double calculatePerimeter() const = 0;
  virtual double calculateArea() const = 0;

private:
  unsigned m_refCount;
  const unsigned m_sides;
  const std::string m_name;
};

#endif // SHAPEBASE_H