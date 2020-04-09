#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class Shape {

protected:
  std::string type;
  int nSides;

public:
  
  std::string GetType() { return this->type;};
  int GetSides() { return this->nSides;};
  
  virtual double CalculatePerimeter() {};  
  virtual double CalculateArea() {};  
};

class Triangle : public virtual Shape {
private:
  double height;
  double base;
public:
  Triangle(double fHeight, double fBase) : height(fHeight), base(fBase) {
    type = "Triangle";
    nSides = 3;
  }
  
  double CalculatePerimeter() {
    return base + 2.0 * sqrt(pow(height, 2) + 0.25 * pow(base, 2));
  }
  double CalculateArea() {
    return 0.5 * base * height;
  }
};

class Circle : public virtual Shape {
private:
  double radius;
public:
  Circle(double fRadius=0) : radius(fRadius) {
    type = "Circle";
    nSides = 0;
  }

  double CalculatePerimeter() {
    return 2.0 * M_PI * radius;
  }
  double CalculateArea() {
    return M_PI * pow(radius, 2);
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
    return 2 * side1 + 2 * side2;
  }
  double CalculateArea() {
    return side1 * side2;
  }
  
};

class Square : public Rectangle {
public:
  Square(double fSide=0) : Rectangle(fSide) {
    side2 = side1;
    type = "Square";
  }

};

int main(int argn, const char **argc) {

  std::vector<Shape*> vec;
  vec.push_back(new Circle(1.0));
  vec.push_back(new Rectangle(2.1, 1.2));
  vec.push_back(new Circle(3.0));
  vec.push_back(new Square(5));
  vec.push_back(new Triangle(2.223, 1.127));
  
}
