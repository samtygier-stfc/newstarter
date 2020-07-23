#include "Shape.h"

class Circle : public Shape
{
  private: 
    double m_radius;

  public:
    Circle(double radius);

    void setRadius(double radius);

    //Accessor methods
    double getRadius() {
      return m_radius;
    }
};