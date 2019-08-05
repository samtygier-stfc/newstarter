#ifndef SHAPEBASE_H
#define SHAPEBASE_H

class ShapeBase {
  friend class Shape;
public:
  ShapeBase() : refCount(0){};
  virtual ShapeBase *clone() const = 0;
  virtual ~ShapeBase(); // needs to be defined to avoid compiler error
  virtual double calculatePerimeter() = 0;
  virtual double calculateArea() = 0;

private:
  unsigned refCount;
};

#endif // SHAPEBASE_H