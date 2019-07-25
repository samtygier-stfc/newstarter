#pragma once
#include "Shape.h"


class Square : public Shape
{
	private:
	public:
		Square(double side);
		double getPerimeter() override;
		double getVolume() override;
};