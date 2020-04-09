#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

class Shape {

protected:
  std::string type;
  int nSides;

public:
  
  std::string GetType() const { return type;};
  int GetSides() const { return nSides;};
  
  virtual double CalculatePerimeter() const { return 0;};  
  virtual double CalculateArea() const { return 0;};  

  friend std::ostream& operator<<(std::ostream& out, const Shape& shape) {
    return out << shape.GetType() << "\t" << shape.GetSides() << "\t" << shape.CalculateArea() << "\t" << shape.CalculatePerimeter();
  }
  
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
  
  double CalculatePerimeter() const {
    return base + 2.0 * sqrt(pow(height, 2) + 0.25 * pow(base, 2));
  }
  double CalculateArea() const {
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

  double CalculatePerimeter() const {
    return 2.0 * M_PI * radius;
  }
  double CalculateArea() const {
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

  double CalculatePerimeter() const {
    return 2 * side1 + 2 * side2;
  }
  double CalculateArea() const {
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

class ShapeSorter {

public:
  void PrintByArea(std::vector<Shape*> vec) {
    sort(vec.begin(), vec.end(), [](const Shape* lhs, const Shape* rhs) {
	  return lhs->CalculateArea() > rhs->CalculateArea();
      });
    std::cout << "Type\tNumber of sides\tArea\tPerimeter" << std::endl;    
    for (auto shape : vec) {
  	std::cout << *shape << std::endl;   
    }
  }
  
  void PrintByPerimeter(std::vector<Shape*> vec) {
    sort(vec.begin(), vec.end(), [](const Shape* lhs, const Shape* rhs) {
	return lhs->CalculatePerimeter() > rhs->CalculatePerimeter();
      });
    std::cout << "Type\tNumber of sides\tArea\tPerimeter" << std::endl;
    for (auto shape : vec) {
  	std::cout << *shape << std::endl;   
    }
  }
  
  
  void PrintMatchingShapes(std::vector<Shape*> vec, std::string type) {
  std::cout << "Type\tNumber of sides\tArea\tPerimeter" << std::endl;
    for (auto shape : vec) {
      if (!type.compare(shape->GetType())) {
  	std::cout << *shape << std::endl;
      }      
    }
  }
  
  void PrintMatchingShapes(std::vector<Shape*> vec, int nSides) {
    std::cout << "Type\tNumber of sides\tArea\tPerimeter" << std::endl;
    for (auto shape : vec) {
      if (nSides == shape->GetSides()) {
	std::cout << *shape << std::endl;
      }     
    }
  }
};

int main(int argn, const char **argc) {

  std::vector<Shape*> vec;
  vec.push_back(new Circle(1.0));
  vec.push_back(new Rectangle(2.1, 1.2));
  vec.push_back(new Circle(3.0));
  vec.push_back(new Square(5));
  vec.push_back(new Triangle(2.223, 1.127));
  
  ShapeSorter sorter;

  std::cout << "Printing shapes with three sides:" << std::endl;
  sorter.PrintMatchingShapes(vec, 3);
  std::cout << "Printing shapes that match 'circle':" << std::endl;
  sorter.PrintMatchingShapes(vec, "Circle");
  std::cout << "Printing shapes by area:" << std::endl;
  sorter.PrintByArea(vec);
  std::cout << "Printing shapes by perimeter:" << std::endl;
  sorter.PrintByPerimeter(vec);

  return 0;
}
