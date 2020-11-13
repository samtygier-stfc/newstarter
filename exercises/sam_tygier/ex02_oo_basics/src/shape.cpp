#include "shape.h"

std::ostream &operator<<( std::ostream &os, const Shape &s ) {
      os << s.getType() << " " << s.getSides() << " " << s.getPerimeter() << " " << s.getArea();
      return os;
}
