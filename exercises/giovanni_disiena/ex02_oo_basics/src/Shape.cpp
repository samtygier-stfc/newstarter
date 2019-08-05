#include "Shape.h"

Shape::Shape(ShapeBase *shapeBasePointer) : m_shapeBasePointer(shapeBasePointer){
  ++m_shapeBasePointer->refCount;
}
Shape::Shape(const Shape &shape) : m_shapeBasePointer(shape.m_shapeBasePointer){
  ++m_shapeBasePointer->refCount;
}
Shape::~Shape() {
  if (--m_shapeBasePointer->refCount == 0) {
    delete m_shapeBasePointer;
  }
}
Shape& Shape::operator=(const Shape &source) {
  ++source.m_shapeBasePointer->refCount;
  if (--refCount == 0) {
    delete m_shapeBasePointer;
  }
  m_shapeBasePointer = source.m_shapeBasePointer;

  return *this;
}
void Shape::makeUnique() {
  if (m_shapeBasePointer->refCount > 1) {
    ShapeBase *new_shapeBasePointer = m_shapeBasePointer->clone();
    --m_shapeBasePointer->refCount;
    ++new_shapeBasePointer->refCount;
    m_shapeBasePointer = new_shapeBasePointer;
  }
}