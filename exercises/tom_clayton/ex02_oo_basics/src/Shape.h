#include <string>

class Shape
{
  private: 
    double m_perimeter;
    double m_area;
    std::string m_type;
    int m_sides;
    
  public:
    Shape(double perimeter, double area, std::string type, int sides);

    std::string shapeToString();

    //Member variable accessors and mutators
    const double getPerimeter();
    const double getArea();
    const std::string getType();
    const int getSides();

    void setPerimeter(double perimeter);
    void setArea(double area);
    void setType(std::string type);
    void setSides(int sides);
};