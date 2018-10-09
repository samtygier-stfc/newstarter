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
	std::string printMessage;

public:
	Shape(double p, double a, std::string t, int s, std::string msg);
	double GetPerimeter() const;
	double GetArea() const;
	std::string GetType() const;
	int GetSides() const;
	std::string GetMessage() const;
	friend std::ostream &operator<<(std::ostream & os, const Shape &shape);
};