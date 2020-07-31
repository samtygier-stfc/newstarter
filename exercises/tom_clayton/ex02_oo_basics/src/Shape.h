#pragma once
#include <string>

class Shape
{
  protected: 
    double m_perimeter;
    double m_area;
    std::string m_type;
    int m_sides;
    
  public:

    Shape(std::string type, int sides);
    virtual ~Shape();

    std::string shapeToString();

    //Virtual functions
    virtual double calcPerimeter() = 0;
    virtual double calcArea() = 0;

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
