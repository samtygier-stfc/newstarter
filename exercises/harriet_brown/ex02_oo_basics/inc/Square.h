#pragma once
#include "Shape.h"


class Square : public Shape
{
	private:
	public:
		Square(double side);
		void printSelf() override;
		double getPerimeter() override;
		double getVolume() override;
};