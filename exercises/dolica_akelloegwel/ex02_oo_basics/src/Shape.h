#pragma once

#include <string>

class Shape
{
protected:
	double area;
	double perimeter;
	std::string type;
	int numSides;

public:
	Shape(double p, double a, std::string t, int s);
	double GetPerimeter();
	double GetArea();
	std::string GetType();
	int GetSides();
};