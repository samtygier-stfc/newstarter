#pragma once
#include <string>
#include <vector>
#include <math.h>

class Shape
{
	private:
		std::string shape;
		double side1;
		double side2;
	public:
		Shape();
		void setShape(const std::string type);
		std::string getShape();
		virtual void setSide1(double side);
		virtual double getSide1();
		virtual void setSide2(double side);
		virtual double getSide2();
		virtual double getPerimeter() = 0;
		virtual double getVolume() = 0;
};
