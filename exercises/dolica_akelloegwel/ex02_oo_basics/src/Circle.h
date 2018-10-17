#pragma once

#include "Shape.h"

class Circle : public Shape
{
private:
	double m_radius;

public:
	explicit Circle(double r);
	double GetPerimeter() const override;
	double GetArea() const override;
	std::string GetType() const override;
	int GetNumSides() const override;
	double GetRadius() const;
	std::string GetMessage() const override;
};
