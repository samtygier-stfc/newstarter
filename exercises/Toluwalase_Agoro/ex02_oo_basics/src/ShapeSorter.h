#pragma once
#include <memory>
#include <vector>
#include <string>
#include "BaseShape.h"
class ShapeSorter {
public:
  std::vector < std::shared_ptr<BaseShape>> m_allShapes{};
  std::vector <int> m_orderToReadArea;
  std::vector <int> m_orderToReadPerimeter;
  std::vector <int> m_orderToReadNumberOfSides;

  void addShape(std::shared_ptr<BaseShape> newShape);
  void displayByType(std::string& shapeType);
  void displayByArea();
  void displayByPerimeter();
  void displayByNumberOfSides();
  ShapeSorter(std::vector <std::shared_ptr<BaseShape>> vectorOfShapes = std::vector <std::shared_ptr<BaseShape>>{}) {
    m_allShapes = vectorOfShapes;
    for (int i = 0; i < m_allShapes.size(); i++) {
      m_allShapes[i]->calculateArea();
      m_allShapes[i]->calculatePerimeter();
    }
  }
};
