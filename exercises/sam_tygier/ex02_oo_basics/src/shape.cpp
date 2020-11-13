#include <iomanip>

#include "shape.h"

std::ostream &operator<<( std::ostream &os, const Shape &s ) {
      os << std::left << std::setw(12) << s.getType() << " "
         << std::setw(8) << s.getSides() << " "
         << std::setw(8) << s.getPerimeter() << " "
         << std::setw(8) << s.getArea();
      return os;
}
