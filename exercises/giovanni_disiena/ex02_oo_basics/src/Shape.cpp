#include "Shape.h"

Shape::Shape(std::shared_ptr<ShapeBase> shapeBasePointer) : m_shapeBasePointer(shapeBasePointer){}
//Shape::Shape(const Shape &shape) : m_shapeBasePointer(shape.m_shapeBasePointer){}
Shape::~Shape() {

}
Shape& Shape::operator=(const Shape &source) {
  if (this != &source) {
    
  }
  return *this;
}

std::shared_ptr<ShapeBase> Shape::getBase() const { return m_shapeBasePointer; }
