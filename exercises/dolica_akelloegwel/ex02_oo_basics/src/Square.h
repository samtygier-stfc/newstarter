#pragma once

#include "Shape.h"

class Square : public Shape
{
private:
	double m_side;

public:
	Square(double s);
	double GetSide() const;
};