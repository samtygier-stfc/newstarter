#ifndef SHAPE_H
#define SHAPE_H

#include <ostream>
#include <string>

class Shape{
public:
	virtual std::string getType() const = 0;
	virtual signed int getSides() const = 0;
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
};

std::ostream &operator<<( std::ostream &os, const Shape &s );

#endif
