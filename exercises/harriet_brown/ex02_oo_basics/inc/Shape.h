#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
	private:
		std::string shapeName;
		double side1;
		double side2;
		int n_sides;
	public:
		Shape();
		void setShapeName(const std::string type);
		std::string getShapeName();
		void setN_sides(int n);
		int getN_sides();
		void setSide1(double side);
		double getSide1();
		void setSide2(double side);
		double getSide2();
		virtual void printSelf() = 0;
		virtual double getPerimeter() = 0;
		virtual double getVolume() = 0;
};

#endif