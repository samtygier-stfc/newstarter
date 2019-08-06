#include "ShapeSorter.h"

ShapeSorter::ShapeSorter(std::vector<Shape> vecShape) : m_vecShape(vecShape), m_vecShapeSorted(vecShape){};

void ShapeSorter::printType(std::string type) const {
  unsigned counter = 0;
  for (std::vector<Shape>::const_iterator it = m_vecShape.begin();
       it != m_vecShape.end(); ++it) {
    if (it->getBase()->getName() == type) {
      std::cout << "Shape " << ++counter << ":\n\tShape is of type "
                << type
                << ", with area " << it->getBase()->getArea()
                << " and perimeter " << it->getBase()->getPerimeter()
                << std::endl;
    }
  }
}

void ShapeSorter::printSides(unsigned sides) const {
  unsigned counter = 0;
  for (std::vector<Shape>::const_iterator it = m_vecShape.begin();
     it != m_vecShape.end(); ++it) {
    if (it->getBase()->getSides() == sides) {
      std::cout << "Shape " << ++counter << ":\n\tShape is of type "
                << it->getBase()->getName() << ", with area "
                << it->getBase()->getArea() << " and perimeter "
                << it->getBase()->getPerimeter() << std::endl;
    }
  }
}

void ShapeSorter::printAreaDescending() {
  std::sort(m_vecShapeSorted.begin(), m_vecShapeSorted.end(),
            [](Shape a, Shape b) {
              return a.getBase()->getArea() > b.getBase()->getArea();
            });
  unsigned counter = 0;
  for (std::vector<Shape>::const_iterator it = m_vecShape.begin();
       it != m_vecShape.end(); ++it) {
    std::cout << "Shape " << ++counter << ":\n\tShape is of type "
              << it->getBase()->getName() << ", with area "
              << it->getBase()->getArea() << " and perimeter "
              << it->getBase()->getPerimeter() << std::endl;
  }
}

void ShapeSorter::printPerimeterDescending() {
  std::sort(m_vecShapeSorted.begin(), m_vecShapeSorted.end(),
            [](Shape a, Shape b) {
              return a.getBase()->getPerimeter() > b.getBase()->getPerimeter();
            });
  unsigned counter = 0;
  for (std::vector<Shape>::const_iterator it = m_vecShape.begin();
       it != m_vecShape.end(); ++it) {
    std::cout << "Shape " << ++counter << ":\n\tShape is of type "
              << it->getBase()->getName() << ", with area "
              << it->getBase()->getArea() << " and perimeter "
              << it->getBase()->getPerimeter() << std::endl;
  }
}
