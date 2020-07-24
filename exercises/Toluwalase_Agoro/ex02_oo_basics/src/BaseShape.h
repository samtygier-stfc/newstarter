#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>


class BaseShape {
  public:
    int m_numberOfSides{0};
    std::string m_type;
    double m_area{0.0};
    double m_perimeter{ 0.0 };
    virtual double calculateArea()=0;
    virtual double calculatePerimeter() = 0;
    BaseShape(int numberOfSides, std::string type) : m_numberOfSides{ numberOfSides }, m_type{ type } {
    }
};
/*
class Square : public BaseShape {
  public:
    double calculateArea() override ;
    double calculatePerimeter() override ;
    double m_length;
    Square(double shapeLength) : BaseShape(4, "Square"), m_length{shapeLength}{
    }

};
double Square :: calculateArea() {
  if (m_area == 0.0) {
    m_area = m_length * m_length;

  }
  return m_area;
}

double Square::calculatePerimeter() {
  if (m_perimeter == 0.0) {
    m_perimeter = 4 * m_length;

  }
  return m_perimeter;
}

class Rectangle : public BaseShape {
public:
  double calculateArea() override;
  double calculatePerimeter() override;
  double m_length;
  double m_width;
  Rectangle(double shapeLength, double shapeWidth) : BaseShape(4, "Rectangle"), m_length{ shapeLength }, m_width{shapeWidth} {
  }
};

double Rectangle::calculateArea() {
  if (m_area == 0.0) {
    m_area = m_length * m_width;

  }
  return m_area;
}

double Rectangle::calculatePerimeter() {
  if (m_perimeter == 0) {
    m_perimeter = 2 * (m_length + m_width);

  }
  return m_perimeter;
}
class Triangle: public BaseShape {
public:
    double m_base;
    double m_height;
    double calculateArea() override;
    double calculatePerimeter() override;
    Triangle(double shapeBase, double shapeHeight) : BaseShape(3, "Triangle"), m_base{ shapeBase }, m_height{shapeHeight}{
    }
};

double Triangle ::calculateArea() {
  if (m_area == 0) {
    m_area =  ( 0.5 * m_base * m_height);

  }
  return m_area;
}

double Triangle::calculatePerimeter() {
  if (m_perimeter == 0) {
    m_perimeter =( m_base + 2 * std::sqrt((m_height * m_height) + (m_base * m_base)* 0.25 ));

  }
  return m_perimeter;
}

class ShapeSorter {
  public: 
    std::vector <BaseShape*> m_allShapes{};
    std::vector <int> m_orderToReadArea;
    std::vector <int> m_orderToReadPerimeter;
    std::vector <int> m_orderToReadNumberOfSides;

    ShapeSorter(std::vector <BaseShape*> vectorOfShapes = std::vector <BaseShape*>{}) {
      m_allShapes = vectorOfShapes;
      for (int i = 0; i < m_allShapes.size();i++) {
        m_allShapes[i]-> calculateArea();
        m_allShapes[i]-> calculatePerimeter();
      }
    }
    void addShape(BaseShape& newShape);
    void displayByType(std::string &shapeType);
    void displayByArea();
    void displayByPerimeter();
    void displayByNumberOfSides();


};
void ShapeSorter::addShape(BaseShape& newShape) {
  newShape.calculateArea();
  newShape.calculatePerimeter();
  m_allShapes.push_back(&newShape);

}

void ShapeSorter :: displayByType(std:: string &shapeType) {
  int i{ 1 };
  for (auto &shape : m_allShapes) {
    if ( shape-> m_type == shapeType) {
      
       shape-> calculateArea();
       shape-> calculatePerimeter();
      
      std::cout << i << ".";
      std::cout << std::left << std::setw(10) << shape-> m_type;
      std::cout << std::setprecision(0);
      std::cout << std::setw(20) << "Number of sides: " << shape-> m_numberOfSides << "  ";
      std::cout << std::fixed << std::setprecision(3);
      std::cout << std::setw(8) << "Area: " << shape-> m_area << "  ";
      std::cout << std::setw(15) << "Perimeter: " << shape-> m_perimeter << std::endl;
      i++;
    }
  }
}

void ShapeSorter::displayByArea() {
  
  if (m_orderToReadArea.size() == 0) {
    for (int i = 0; i < m_allShapes.size(); i++) {
      double maxArea{ 0 };
      int index{ 0 };
      for (int j = 0; j < m_allShapes.size(); j++) {
        if (m_allShapes[j]->m_area > maxArea && std::find(m_orderToReadArea.begin(), m_orderToReadArea.end(), j) == m_orderToReadArea.end()) {
          index = j;
          maxArea = m_allShapes[j]-> m_area;
        }
      }
      m_orderToReadArea.push_back(index);
    }
  }
  for (int i = 0; i < m_orderToReadArea.size(); i++) {
   
    std::cout << i+1 << ".";
    std::cout << std::left << std::setw(10) << m_allShapes[m_orderToReadArea[i]]-> m_type;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << m_allShapes[m_orderToReadArea[i]]-> m_area << "  ";
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << m_allShapes[m_orderToReadArea[i]]-> m_numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(15) << "Perimeter: " << m_allShapes[m_orderToReadArea[i]]-> m_perimeter << std::endl;
    
  }
}

void ShapeSorter::displayByPerimeter() {
  if (m_orderToReadPerimeter.size() == 0) {
    for (int i = 0; i < m_allShapes.size(); i++) {
      double maxPerimeter{ 0 };
      int index{ 0 };
      for (int j = 0; j < m_allShapes.size(); j++) {
        if (m_allShapes[j]-> m_perimeter > maxPerimeter && std::find(m_orderToReadPerimeter.begin(), m_orderToReadPerimeter.end(), j) == m_orderToReadPerimeter.end()) {
          index = j;
          maxPerimeter= m_allShapes[j]-> m_perimeter;
        }
      }
      m_orderToReadPerimeter.push_back(index);
    }
  }
  for (int i = 0; i < m_orderToReadPerimeter.size(); i++) {
    BaseShape *shape = m_allShapes[m_orderToReadPerimeter[i]];
    std::cout << i + 1 << ".";
    std::cout << std::left << std::setw(10) << shape-> m_type;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(15) << "Perimeter: " << shape-> m_perimeter;
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << shape-> m_numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << shape-> m_area << "  " << std::endl;
    

  }
}


void ShapeSorter::displayByNumberOfSides() {
  if (m_orderToReadNumberOfSides.size() == 0) {
    for (int i = 0; i < m_allShapes.size(); i++) {
      double maxNumberOfSides{ 0 };
      int index{ 0 };
      for (int j = 0; j < m_allShapes.size(); j++) {
        if (m_allShapes[j]-> m_numberOfSides > maxNumberOfSides && std::find(m_orderToReadNumberOfSides.begin(), m_orderToReadNumberOfSides.end(), j) == m_orderToReadNumberOfSides.end()) {
          index = j;
          maxNumberOfSides = m_allShapes[j]-> m_numberOfSides;
        }
      }
      m_orderToReadNumberOfSides.push_back(index);
    }
  }
  for (int i = 0; i < m_orderToReadNumberOfSides.size(); i++) {
    BaseShape *shape = m_allShapes[m_orderToReadNumberOfSides[i]];
    std::cout << i + 1 << ".";
    std::cout << std::left << std::setw(10) << shape-> m_type;
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << shape-> m_numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << shape-> m_area << "  ";
    std::cout << std::setw(15) << "Perimeter: " << shape-> m_perimeter << std::endl;

  }
}

*/