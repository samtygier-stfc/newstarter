#ifndef Circle_H
#define Circle_H

#include"Shape.h"

class Circle : public Shape {
public:
	// constructor
	Circle(double radius) : Shape("Circle", 1), m_radius(radius) {}
	// deconstructor
	virtual ~Circle() {}

	// interface
	double calcPerimiter() const;
	double calcArea() const;

private:
	double m_radius;
};

#endif
