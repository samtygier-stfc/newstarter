#ifndef Square_H
#define Square_H

#include"Shape.h"

class Square: public Shape {
public:
	// constructor
	Square(double side) : Shape("Square", 4), m_side(side) {}
	// deconstructor
	virtual ~Square() {}

	// interface
	double calcPerimiter() const;
	double calcArea() const;

private:
	double m_side;
};

#endif 