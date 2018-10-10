#pragma once

#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

class Shape
{
protected:
	double area;
	double perimeter;
	std::string type;
	int numSides;
	std::string printMessage;
	void SetPerimeter(double p);
	void SetArea(double a);
	void SetSides(int s);
	std::string CreateBaseMessage();
	void SetMessage(std::string msg);

public:
	Shape(std::string t, int n);
	double GetPerimeter() const;
	double GetArea() const;
	std::string GetType() const;
	int GetSides() const;
	std::string GetMessage() const;
	friend std::ostream &operator<<(std::ostream & os, const Shape &shape);
};