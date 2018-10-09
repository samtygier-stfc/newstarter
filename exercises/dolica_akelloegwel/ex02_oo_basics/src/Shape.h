#pragma once
class Shape
{
	protected:
		double area;
		double perimeter;

	public:
		Shape(double a, double p);
		double GetPerimeter();
		double GetArea();
};