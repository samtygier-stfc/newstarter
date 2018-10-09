#pragma once

#include "Shape.h"
#include <math.h>

class Triangle : public Shape
{
private:
	double base;
	double height;

public:
	Triangle(double b, double h);
	double GetBase();
	double GetHeight();
	void write(std::ostream& os) const;
};

