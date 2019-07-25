#pragma once
#include <string>
#include <math.h>

class Shape
{
	private:
		std::string shape;
		double side1;
		double side2;
		int n_sides;
	public:
		Shape();
		void setShape(const std::string type);
		std::string getShape();
		void setN_sides(int n);
		int getN_sides();
		void setSide1(double side);
		double getSide1();
		void setSide2(double side);
		double getSide2();
		virtual double getPerimeter() = 0;
		virtual double getVolume() = 0;
};
