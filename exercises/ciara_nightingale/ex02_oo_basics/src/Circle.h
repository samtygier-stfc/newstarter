#include "Shape.h"

class Circle:Shape {
public:
		Circle();
		Circle(double radius);
		virtual double perimeter() const override;
		virtual double area() const override;
private:
		double m_radius;
};