#pragma once

#include "Shape.h"

class Circle : public Shape
{
private:
	double m_radius;

public:
	Circle(double r);
	double GetPerimeter() const;
	double GetArea() const;
	double GetRadius() const;
};
