#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
private:
	double m_width;
	double m_height;

public:
	Rectangle(double w, double h);
	double GetPerimeter() const;
	double GetArea() const;
	std::string GetType() const;
	double GetWidth();
	double GetHeight();
};
