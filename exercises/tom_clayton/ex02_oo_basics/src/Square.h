#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape.h"

class Square : public Shape
{
  private: 
    double m_side1;

  public:
    Square(double side1);

    void setSide1(double side1);

    double getSide1() {
      return m_side1;
    }
};

#endif /* SQUARE_H_ */