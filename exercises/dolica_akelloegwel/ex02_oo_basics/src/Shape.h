#pragma once

#include <string>
#include <iostream>

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
	virtual void write(std::ostream &os) const;
	friend std::ostream &operator<<(std::ostream & os, const Shape &shape);
};