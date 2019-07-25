#pragma once
#include "Shape.h"


class Triangle : public Shape
{
	private:
	public:
		Triangle(double base, double height);
		double getPerimeter();
		double getVolume();
};