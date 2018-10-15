#pragma once

#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

class Shape
{
protected:
	double m_area;
	double m_perimeter;
	std::string m_type;
	int m_numSides;
	std::string m_printMessage;
	void SetPerimeter(double perimeter);
	void SetArea(double area);
	void SetSides(int sides);
	std::string CreateBaseMessage();
	void SetMessage(std::string msg);

public:
	Shape(int n);
	~Shape();
	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
	virtual std::string GetType() const = 0;
	int GetSides() const;
	std::string GetMessage() const;
	friend std::ostream &operator<<(std::ostream & os, const Shape &shape);
};
