#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"


class Circle : public Shape
{
	private:
	public:
		Circle(double radius);
		void printSelf() override;
		double getPerimeter() override;
		double getVolume() override;
};

#endif