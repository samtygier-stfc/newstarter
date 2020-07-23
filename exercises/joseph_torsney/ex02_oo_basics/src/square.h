#pragma once

#include "rect.h"

class Square: public Rect {

  public:
    Square(double side): Rect(side, side) {
      type = "square";
    }
};
