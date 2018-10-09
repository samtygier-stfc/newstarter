#pragma once

#include "Shape.h"

class Square : public Shape
{
private:
	double side;

public:
	Square(double s);
	double GetSide() const;
	void write(std::ostream& os) const;
};