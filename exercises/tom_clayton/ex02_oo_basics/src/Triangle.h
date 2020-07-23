#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape
{
  private: 
    double m_height;
    double m_base;

  public:
    Triangle(double height, double base);

    void setBase(double base);

    void setHeight(double height);

    double calcPerimeter(double height, double base);

    //Accessor methods
    double getBase() {
      return m_base;
    }

    double getHeight() {
      return m_height;
    }
};

#endif /* TRIANGLE_H_ */