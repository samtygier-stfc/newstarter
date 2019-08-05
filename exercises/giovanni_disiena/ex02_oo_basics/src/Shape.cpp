#include "Shape.h"

Shape::Shape(ShapeBase *shapeBasePointer) : m_shapeBasePointer(shapeBasePointer){};
Shape::Shape(const Shape &shape) : m_shapeBasePointer(shape.m_shapeBasePointer->clone()){};
Shape::~Shape() { delete m_shapeBasePointer; }
Shape& Shape::operator=(const Shape &source) {
  ShapeBase *newPointer = source->clone(); // exception possible
  delete m_shapeBasePointer;
  m_shapeBasePointer = newPointer;

  return *this;
}