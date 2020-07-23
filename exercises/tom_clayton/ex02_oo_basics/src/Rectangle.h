#include "Shape.h"

class Rectangle : public Shape
{
  private: 
    double m_side1;
    double m_side2;

  public:
    Rectangle(double side1, double side2);

    void setSide1(double side1);

    void setSide2(double side2);


    //Accessor methods
    double getSide1() {
      return m_side1;
    }

    double getSide2() {
      return m_side2;
    }
};