#pragma once
#include "Shape.h"


class Rectangle : public Shape
{
	private:
	public:
		Rectangle(double width, double height);
		double getPerimeter();
		double getVolume();
};