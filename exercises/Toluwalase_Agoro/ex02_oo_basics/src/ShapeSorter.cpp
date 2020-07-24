#include <iostream>
#include <memory>
#include <iomanip>
#include <string>
#include "BaseShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "ShapeSorter.h"



void ShapeSorter::addShape(std::shared_ptr<BaseShape> newShape) {
  newShape-> calculateArea();
  newShape-> calculatePerimeter();
  m_allShapes.emplace_back(newShape);

}

void ShapeSorter::displayByType(std::string& shapeType) {
  int i{ 1 };
  for (auto& shape : m_allShapes) {
    if (shape->m_type == shapeType) {

      shape->calculateArea();
      shape->calculatePerimeter();

      std::cout << i << ".";
      std::cout << std::left << std::setw(10) << shape->m_type;
      std::cout << std::setprecision(0);
      std::cout << std::setw(20) << "Number of sides: " << shape->m_numberOfSides << "  ";
      std::cout << std::fixed << std::setprecision(3);
      std::cout << std::setw(8) << "Area: " << shape->m_area << "  ";
      std::cout << std::setw(15) << "Perimeter: " << shape->m_perimeter << std::endl;
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
          maxArea = m_allShapes[j]->m_area;
        }
      }
      m_orderToReadArea.emplace_back(index);
    }
  }
  for (int i = 0; i < m_orderToReadArea.size(); i++) {

    std::cout << i + 1 << ".";
    std::cout << std::left << std::setw(10) << m_allShapes[m_orderToReadArea[i]]->m_type;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << m_allShapes[m_orderToReadArea[i]]->m_area << "  ";
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << m_allShapes[m_orderToReadArea[i]]->m_numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(15) << "Perimeter: " << m_allShapes[m_orderToReadArea[i]]->m_perimeter << std::endl;

  }
}

void ShapeSorter::displayByPerimeter() {
  if (m_orderToReadPerimeter.size() == 0) {
    for (int i = 0; i < m_allShapes.size(); i++) {
      double maxPerimeter{ 0 };
      int index{ 0 };
      for (int j = 0; j < m_allShapes.size(); j++) {
        if (m_allShapes[j]->m_perimeter > maxPerimeter && std::find(m_orderToReadPerimeter.begin(), m_orderToReadPerimeter.end(), j) == m_orderToReadPerimeter.end()) {
          index = j;
          maxPerimeter = m_allShapes[j]->m_perimeter;
        }
      }
      m_orderToReadPerimeter.emplace_back(index);
    }
  }
  for (int i = 0; i < m_orderToReadPerimeter.size(); i++) {
    std::cout << i + 1 << ".";
    std::cout << std::left << std::setw(10) << m_allShapes[m_orderToReadPerimeter[i]]->m_type;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(15) << "Perimeter: " << m_allShapes[m_orderToReadPerimeter[i]]->m_perimeter;
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << m_allShapes[m_orderToReadPerimeter[i]]->m_numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << m_allShapes[m_orderToReadPerimeter[i]]->m_area << "  " << std::endl;


  }
}


void ShapeSorter::displayByNumberOfSides() {
  if (m_orderToReadNumberOfSides.size() == 0) {
    for (int i = 0; i < m_allShapes.size(); i++) {
      double maxNumberOfSides{ 0 };
      int index{ 0 };
      for (int j = 0; j < m_allShapes.size(); j++) {
        if (m_allShapes[j]->m_numberOfSides > maxNumberOfSides && std::find(m_orderToReadNumberOfSides.begin(), m_orderToReadNumberOfSides.end(), j) == m_orderToReadNumberOfSides.end()) {
          index = j;
          maxNumberOfSides = m_allShapes[j]->m_numberOfSides;
        }
      }
      m_orderToReadNumberOfSides.emplace_back(index);
    }
  }
  for (int i = 0; i < m_orderToReadNumberOfSides.size(); i++) {
    std::cout << i + 1 << ".";
    std::cout << std::left << std::setw(10) << m_allShapes[m_orderToReadNumberOfSides[i]]->m_type;
    std::cout << std::setprecision(0);
    std::cout << std::setw(20) << "Number of sides: " << m_allShapes[m_orderToReadNumberOfSides[i]]->m_numberOfSides << "  ";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(8) << "Area: " << m_allShapes[m_orderToReadNumberOfSides[i]]->m_area << "  ";
    std::cout << std::setw(15) << "Perimeter: " << m_allShapes[m_orderToReadNumberOfSides[i]]->m_perimeter << std::endl;

  }
}