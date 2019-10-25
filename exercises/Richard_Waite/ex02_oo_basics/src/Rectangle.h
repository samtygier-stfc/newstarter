#ifndef Rectangle_H
#define Rectangle_H

#include"Shape.h"

class Rectangle : public Shape {
public:
	// constructor
	Rectangle(double width, double height) : Shape("Rectangle", 4), m_width(width), m_height(height) {}
	// deconstructor
	virtual ~Rectangle() {}

	// interface
	double calcPerimiter() const;
	double calcArea() const;

private:
	double m_width;
	double m_height;
};

#endif 