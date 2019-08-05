#include "Shape.h"

Shape::Shape(ShapeBase *) : m_shapeBasePointer(0){}
Shape::Shape(const Shape &shape) : m_shapeBasePointer(shape.m_shapeBasePointer){}
Shape::~Shape() {
  if (m_useObj == 1) {
    delete m_shapeBasePointer;
  }
}
Shape& Shape::operator=(const Shape &source) {
  if (this != &source) {
    if (m_useObj == 1) {
      delete m_shapeBasePointer;
      m_useObj = source.m_useObj;
      m_shapeBasePointer = source.m_shapeBasePointer;
    }
  }
  return *this;
}
void Shape::makeUnique() {
  Use new_useObj;
  m_shapeBasePointer = m_shapeBasePointer->clone();
  m_useObj = new_useObj;
}