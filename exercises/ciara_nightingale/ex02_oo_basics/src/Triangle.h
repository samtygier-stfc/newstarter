#include "Shape.h"

class Triangle:Shape {
public:
		Triangle();
		Triangle(double base, double height);
		double perimeter() const override;
		double area() const override;
private:
		double m_base;
		double m_height;
};
