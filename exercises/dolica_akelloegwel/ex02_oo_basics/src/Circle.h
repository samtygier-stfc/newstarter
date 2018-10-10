#pragma once

#include "Shape.h"

class Circle : public Shape
{
private:
	double m_radius;

public:
	Circle(double r);
	double GetRadius() const;
};
