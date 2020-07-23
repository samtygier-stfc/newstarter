#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>


class BaseShape {
public:
    int numberOfSides{};
    std::string type{};
    float area{0.0};
    float perimeter{ 0.0 };
    virtual float calculateArea(void) { return 0.0; }
    virtual float calculatePerimeter(void) { return 1.0; } 

    

};

class Square : public BaseShape {
  public:
    float calculateArea(void) override ;
    float calculatePerimeter(void) override ;
    float length;
    Square(float shapeLength) {
      length = shapeLength;
      numberOfSides = 4;
      type = "Square";
    }

};
float Square :: calculateArea() {
  if (area == 0.0) {
    area = length * length;

  }
  return area;
}

float Square::calculatePerimeter() {
  if (perimeter == 0.0) {
    perimeter = 4 * length;

  }
  return perimeter;
}

class Rectangle : public BaseShape {
public:
  float calculateArea(void) override;
  float calculatePerimeter(void) override;
  float length;
  float width;
  Rectangle(float shapeLength, float shapeWidth){
    length = shapeLength;
    width = shapeWidth;
    numberOfSides = 4;
    type = "Rectangle";
  }
};

float Rectangle::calculateArea() {
  if (area == 0.0) {
    area = length * width;

  }
  return area;
}

float Rectangle::calculatePerimeter() {
  if (perimeter == 0) {
    perimeter = 2 * (length + width);

  }
  return perimeter;
}
class Triangle: public BaseShape {
public:
    float base;
    float height;
    float calculateArea(void) override;
    float calculatePerimeter(void) override;
    Triangle(float shapeBase,float shapeHeight) 
    {
    base = shapeBase;
    height = shapeHeight;
    numberOfSides = 3;
    type = "Triangle";
    }
};

float Triangle ::calculateArea() {
  if (area == 0) {
    area =float ( 0.5 * base * height);

  }
  return area;
}

float Triangle::calculatePerimeter() {
  if (perimeter == 0) {
    perimeter =float( base + 2 * std::sqrt((height * height) + (base * base)* 0.25 ));

  }
  return perimeter;
}

class ShapeSorter {
  public: 
    std::vector <BaseShape*> allShapes{};
    std::vector <int> orderToReadArea;
    std::vector <int> orderToReadPerimeter;
    std::vector <int> orderToReadNumberOfSides;
  public:
    ShapeSorter(std::vector <BaseShape*> vectorOfShapes = std::vector <BaseShape*>{} ) {
      allShapes = vectorOfShapes;
      for (int i = 0; i < allShapes.size();i++) {
        (*allShapes[i]).calculateArea();
        (*allShapes[i]).calculatePerimeter();
      }
    }
    void addShape(BaseShape &newShape) {
      newShape.calculateArea();
      newShape.calculatePerimeter();
      allShapes.push_back(&newShape);
      
    }
    void displayByType(std::string shapeType);
    void displayByArea(void);
    void displayByPerimeter(void);
    void displayByNumberOfSides(void);


};
void ShapeSorter :: displayByType(std:: string shapeType) {
  int i{ 1 };
  for (auto shape : allShapes) {
    if ((*shape).type == shapeType) {
      
       (*shape).calculateArea();
       (*shape).calculatePerimeter();
      
      std::cout << i << ".";
      std::cout << std::left << std::setw(10) << (*shape).type;
      std::cout << std::setprecision(0);
      std::cout << std::setw(20) << "Number of sides: " << (*shape).numberOfSides << "  ";
      std::cout << std::fixed << std::setprecision(3);
      std::cout << std::setw(8) << "Area: " << (*shape).area << "  ";
      std::cout << std::setw(15) << "Perimeter: " << (*shape).perimeter << std::endl;
      i++;
    }
  }
}

void ShapeSorter::displayByArea(void) {
  
  if (orderToReadArea.size() == 0) {
    for (int i = 0; i < allShapes.size(); i++) {
      double maxArea{ 0 };
      int index{ 0 };
      for (int j = 0; j < allShapes.size(); j++) {
        if ((*allShapes[j]).area > maxArea && std::find(orderToReadArea.begin(), orderToReadArea.end(), j) == orderToReadArea.end()) {
          index = j;
          maxArea = (*allShapes[j]).area;
        }
      }
      orderToReadArea.push_back(index);
    }
  }
  for (int i = 0; i < orderToReadArea.size(); i++) {
   
    //BaseShape *shape = allShapes[ orderToReadArea[i] ];
    std::cout << i+1 << ".";
    std::cout << std::left << std::setw(10) << (*allShapes[orderToReadArea[i]]).type;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << (*allShapes[orderToReadArea[i]]).area << "  ";
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << (*allShapes[orderToReadArea[i]]).numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(15) << "Perimeter: " << (*allShapes[orderToReadArea[i]]).perimeter << std::endl;
    
  }
}

void ShapeSorter::displayByPerimeter(void) {
  if (orderToReadPerimeter.size() == 0) {
    for (int i = 0; i < allShapes.size(); i++) {
      double maxPerimeter{ 0 };
      int index{ 0 };
      for (int j = 0; j < allShapes.size(); j++) {
        if ((*allShapes[j]).perimeter > maxPerimeter && std::find(orderToReadPerimeter.begin(), orderToReadPerimeter.end(), j) == orderToReadPerimeter.end()) {
          index = j;
          maxPerimeter= (*allShapes[j]).perimeter;
        }
      }
      orderToReadPerimeter.push_back(index);
    }
  }
  for (int i = 0; i < orderToReadPerimeter.size(); i++) {
    BaseShape *shape = allShapes[orderToReadPerimeter[i]];
    std::cout << i + 1 << ".";
    std::cout << std::left << std::setw(10) << (*shape).type;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(15) << "Perimeter: " << (*shape).perimeter;
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << (*shape).numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << (*shape).area << "  " << std::endl;
    

  }
}


void ShapeSorter::displayByNumberOfSides(void) {
  if (orderToReadNumberOfSides.size() == 0) {
    for (int i = 0; i < allShapes.size(); i++) {
      double maxNumberOfSides{ 0 };
      int index{ 0 };
      for (int j = 0; j < allShapes.size(); j++) {
        if ((*allShapes[j]).numberOfSides > maxNumberOfSides && std::find(orderToReadNumberOfSides.begin(), orderToReadNumberOfSides.end(), j) == orderToReadNumberOfSides.end()) {
          index = j;
          maxNumberOfSides =(* allShapes[j]).numberOfSides;
        }
      }
      orderToReadNumberOfSides.push_back(index);
    }
  }
  for (int i = 0; i < orderToReadNumberOfSides.size(); i++) {
    BaseShape *shape = allShapes[orderToReadNumberOfSides[i]];
    std::cout << i + 1 << ".";
    std::cout << std::left << std::setw(10) << (*shape).type;
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << (*shape).numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << (*shape).area << "  ";
    std::cout << std::setw(15) << "Perimeter: " << (*shape).perimeter << std::endl;

  }
}

