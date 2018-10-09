#pragma once

#include <math.h>
#include "Shape.h"

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double r);
	double GetRadius();
};
