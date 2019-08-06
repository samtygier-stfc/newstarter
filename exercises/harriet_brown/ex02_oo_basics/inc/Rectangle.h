#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"


class Rectangle : public Shape
{
	private:
	public:
		Rectangle(double width, double height);
		void printSelf() override;
		double getPerimeter() override;
		double getVolume() override;
};

#endif