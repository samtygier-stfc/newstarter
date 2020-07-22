#ifndef SQUARE_H
#define SQUARE_H

#include "rect.h"

class Square: public Rect {

  public:
    Square(int side): Rect(side, side) {}
};

#endif