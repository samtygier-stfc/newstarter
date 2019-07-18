#include "Shape.h"

Shape::Shape(std::string type, int sidesNumber)
    : m_type{type}, m_sidesNumber{sidesNumber} {}

void Shape::printInfo() const {
  std::cout << this->getType() + " with perimeter " << this->getPerimeter()
            << " and area " << this->getArea() << "\n";
}
