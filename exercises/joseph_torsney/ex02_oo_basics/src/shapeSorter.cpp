#include "shapeSorter.h"
#include "shape.h"
#include <iostream>
#include <vector>
#include <algorithm>

ShapeSorter::ShapeSorter(std::vector<Shape*> v) : m_shapes(v) {};

void ShapeSorter::printMatching(std::string type) {
  for (auto it = m_shapes.begin(); it != m_shapes.end(); it++) {
    if (type == (*it)->getType()) {
      std::cout << (*it)->toString() << std::endl;
    }
  }
}

void ShapeSorter::printSides(int sides) {
  for (auto it = m_shapes.begin(); it != m_shapes.end(); it++) {
    if (sides == (*it)->getSides()) {
      std::cout << (*it)->toString() << std::endl;
    }
  }
}

void ShapeSorter::printAreas() {
  std::sort(m_shapes.begin(), m_shapes.end(), 
    [](const auto& a, const auto& b) -> bool {
      return a->getArea() > b->getArea();
    }
  );
  printAll();
}

void ShapeSorter::printPerimeters() {
  std::sort(m_shapes.begin(), m_shapes.end(), 
    [](const auto& a, const auto& b) -> bool {
      return a->getPerimeter() > b->getPerimeter();
    }
  );
  printAll();
}

void ShapeSorter::printAll() {
  for (auto it = m_shapes.begin(); it != m_shapes.end(); it++) {
    std::cout << (*it)->toString() << std::endl;
  }
}


