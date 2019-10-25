#ifndef Shape_H
#define Shape_H
#include<string>
#include<iostream>

class Shape {
public:
	// constructor
	Shape() {}
	Shape(std::string shapeName, int nsides) : m_shapeName(shapeName), m_nsides(nsides) {}
	// deconstructor
	virtual ~Shape() {}

	// interface
	int getNsides() const { return m_nsides; }
	std::string getShapeName() const { return m_shapeName; }
	// member functions
	virtual double calcPerimiter() const = 0;
	virtual double calcArea() const = 0; // why did I have to add 0 is it a null value?
	void print() const {
		// std::ostream& out
		std::cout << "Area = " << this->calcArea() << 
			"\tPerimiter = " << this->calcPerimiter() << std::endl;
	}

private:
	std::string m_shapeName;
	int m_nsides;
};

#endif 