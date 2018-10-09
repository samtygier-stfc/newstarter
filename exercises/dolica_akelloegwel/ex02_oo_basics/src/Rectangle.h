#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
private:
	double width;
	double height;

public:
	Rectangle(double w, double h);
};