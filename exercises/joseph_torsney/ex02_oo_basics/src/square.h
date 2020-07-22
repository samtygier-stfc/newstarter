#ifndef SQUARE_H
#define SQUARE_H

#include "rect.h"

class Square: public Rect {

  public:
    Square(double side): Rect(side, side) {
      type = "square";
    }
};

#endif