#ifndef SHAPEBASE_H
#define SHAPEBASE_H

#include <math.h>
#include <string>

class ShapeBase {
  friend class Shape;
public:
  ShapeBase(unsigned sides, std::string name) : m_sides(sides), m_name(name), m_refCount(0){};
  virtual ShapeBase *clone() const = 0;
  virtual double getPerimeter() const = 0;
  virtual double getArea() const = 0;
  std::string getName() const;
  unsigned getSides() const;
  unsigned getCount() const;
private:
  unsigned m_refCount;
  const unsigned m_sides;
  const std::string m_name;
};

#endif // SHAPEBASE_H