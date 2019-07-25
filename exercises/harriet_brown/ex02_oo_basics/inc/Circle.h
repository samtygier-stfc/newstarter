#pragma once
#include "Shape.h"


class Circle : public Shape
{
	private:
	public:
		Circle(double radius);
		double getPerimeter();
		double getVolume();
};