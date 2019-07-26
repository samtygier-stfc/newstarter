#pragma once
#include "Shape.h"


class Triangle : public Shape
{
	private:
	public:
		Triangle(double base, double height);
		void printSelf() override;
		double getPerimeter() override;
		double getVolume() override;
};