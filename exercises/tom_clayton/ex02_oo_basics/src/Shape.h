#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape
{
  protected: 
    double m_perimeter;
    double m_area;
    std::string m_type;
    int m_sides;
    
  public:
    Shape();

    std::string shapeToString();

    //Virtual functions
    virtual double calcPerimeter(double h, double b);
    virtual double calcArea(double h, double b);

    //Member variable accessors and mutators
    double getPerimeter();
    double getArea();
    std::string getType();
    int getSides();

    void setPerimeter(double perimeter);
    void setArea(double area);
    void setType(std::string type);
    void setSides(int sides);
};

#endif /* SHAPE_H_ */