#pragma once

#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

class Shape
{
protected:
	std::string m_printMessage;
	std::string CreateBaseMessage();
	void SetMessage(std::string msg);

public:
	Shape();
	~Shape();
	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
	virtual std::string GetType() const = 0;
	virtual int GetNumSides() const = 0;
	std::string GetMessage() const;
	friend std::ostream &operator<<(std::ostream & os, const Shape &shape);
};
