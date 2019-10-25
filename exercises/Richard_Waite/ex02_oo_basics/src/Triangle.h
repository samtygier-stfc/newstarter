#ifndef Triangle_H
#define Triangle_H

#include"Shape.h"

class Triangle : public Shape {
public:
	// constructor
	Triangle(double base, double height) : Shape("Triangle", 4), m_base(base), m_height(height) {}
	// deconstructor
	virtual ~Triangle() {}

	// interface
	double calcPerimiter() const;
	double calcArea() const;

private:
	double m_base;
	double m_height;
};

#endif
