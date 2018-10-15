#pragma once

#include "Shape.h"

class Triangle : public Shape
{
private:
	double m_base;
	double m_height;

public:
	Triangle(double b, double h);
	double GetPerimeter() const;
	double GetArea() const;
	std::string GetType() const;
	double GetBase() const;
	double GetHeight() const;
};

