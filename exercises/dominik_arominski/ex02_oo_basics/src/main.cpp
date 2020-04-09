#include <iostream>
#include <string>
#include <cmath>

class Shape {

protected:
  std::string type;
  int nSides;

public:
  
  std::string GetType() { return this->type;};
  int GetSides() { return this->nSides;};
  
  virtual double CalculatePerimeter() {};  
  
};

class Triangle : public virtual Shape {
private:
  double height;
  double base;
public:
  double CalculatePerimeter() {
    return base + 2.0 * sqrt(pow(height, 2) + 0.25 * pow(base, 2));
  }
};

class Circle : public virtual Shape {
private:
  double radius;
public:
  Circle(double fRadius=0) : radius(fRadius) {
    type = "Circle";
    nSides =  FP_INFINITE;
  }

  double CalculatePerimeter() {
    return radius;
  }
};

class Rectangle : public virtual Shape {
protected:
  double side1;
  double side2;
public:
  Rectangle(double fSide1=0, double fSide2=0) : side1(fSide1), side2(fSide2) {
    type = "Rectangle";
    nSides = 4;
  }

  double CalculatePerimeter() {
    return 0.5 * sqrt(pow(side1, 2) + pow(side2, 2));
  }
  
};

class Square : public Rectangle {
public:
  Square(double fSide=0) : Rectangle(fSide) {
    side2 = side1;
    type = "Square";
  }

};

int main(int argn, const char ** argc) {

}
