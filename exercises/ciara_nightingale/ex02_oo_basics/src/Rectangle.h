#include "Shape.h"

class Rectangle :Shape {
public:
		Rectangle();
		Rectangle(double width, double height);
		virtual double perimeter() const override;
		virtual double area() const override;
private:
		double m_width;
		double m_height;
};
