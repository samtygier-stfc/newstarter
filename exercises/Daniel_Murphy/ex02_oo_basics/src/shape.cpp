#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <map>
#include "shape.h"


std::string Shape::getType()
{
  return m_type;
}
int Shape::getSides()
{
  return m_sides;
}
int Shape::getID()
{
  return m_ID;
}


std::unique_ptr<Shape> Triangle::clone()
{
  return std::make_unique<Triangle>(*this);
}
double Triangle::getArea()
{
  return 0.5 * m_base * m_height;;
}
double Triangle::getPerimeter()
{
  return m_base + 2*sqrt(pow(m_height,2) + (pow(m_base,2)/4));
}


std::unique_ptr<Shape> Square::clone()
{
  return std::make_unique<Square>(*this);
}
double Square::getArea()
{
  return pow(m_side1,2);
}
double Square::getPerimeter()
{
  return m_side1*4;
}


std::unique_ptr<Shape> Rectangle::clone()
{
  return std::make_unique<Rectangle>(*this);
}
double Rectangle::getArea()
{
  return m_side1 * m_side2;
}
double Rectangle::getPerimeter()
{
  return (2*m_side1) + (2*m_side2);
}


std::unique_ptr<Shape> Circle::clone()
{
  return std::make_unique<Circle>(*this);
}
double Circle::getArea()
{
  return M_PI * pow(m_radius,2);
}
double Circle::getPerimeter()
{
  return 2 * M_PI * m_radius;
}


void ShapeSorter::addNew(std::unique_ptr<Shape> newShape)
{
  m_shapes.emplace_back(std::move(newShape));
}

void ShapeSorter::allOneType(std::string typeRequested)
{
  std::vector<int> typeVec;
  for (auto const& el : m_shapes)
  {
    std::string shapeType = el->getType();
    if (shapeType == typeRequested)
    {
      typeVec.push_back(el->getID());
    }
  }
  if (typeVec.size() == 0)
  {
    std::cout << "None of shape type " << typeRequested << " were found.";
  }
  else
  {
    std::cout << "The shapes of type " << typeRequested << " are:  ";
    for (auto const& el: typeVec)
    {
      std::cout << el << "  ";
    }
  }
  std::cout << "\n";
}

void ShapeSorter::matchSideNumber(int sidesRequested)
{
  std::string plural = "sides";
  if (sidesRequested == 1)
  {
    plural = "side";
  }
  std::vector<int> sideVec;
  for (auto const& el: m_shapes)
  {
    int numSides = el->getSides();
    if (numSides == sidesRequested)
    {
      sideVec.push_back(el->getID());
    }
  }
  if (sideVec.size() == 0)
  {
    std::cout << "No shapes with " << sidesRequested << " sides were found.";
  }
  else
  {
    std::cout << "The shapes with " << sidesRequested << " " << plural << " are:  ";
    for (auto const& el: sideVec)
    {
      std::cout << el << "  ";
    }
  }
  std::cout << "\n";
}

void ShapeSorter::areaDescending()
{
  std::cout << "\nShape Number      Area / sq u \n";
  std::cout << "############      ###########\n\n";

  std::vector<std::unique_ptr<Shape>> shapesByArea;
  shapesByArea.reserve(m_shapes.size());
  for (const auto& el : m_shapes)
    shapesByArea.emplace_back(el->clone());

  std::sort(shapesByArea.begin(), shapesByArea.end(), 
    [](std::unique_ptr<Shape>& a, std::unique_ptr<Shape>& b)
    { return a->getArea() > b->getArea();} );

  for (auto const&  el : shapesByArea)
  {
    int ID = el->getID();
    double area = el->getArea();
    size_t lenID = std::to_string(ID).length();
    size_t lenArea = std::to_string(area).length();
    std::cout << std::string(7-lenID, ' ') << ID << std::string(25-lenArea, ' ') << area << "\n";
  }

  std::cout << "\n";
}

void ShapeSorter::perimeterDescending()
{
  std::cout << "\nShape Number      Perimeter / u \n";
  std::cout << "############      #############\n\n";

  std::vector<std::unique_ptr<Shape>> shapesByPerimeter;
  shapesByPerimeter.reserve(m_shapes.size());
  for (const auto& el : m_shapes)
    shapesByPerimeter.emplace_back(el->clone());

  std::sort(shapesByPerimeter.begin(), shapesByPerimeter.end(),
    [](std::unique_ptr<Shape>& a, std::unique_ptr<Shape>& b)
    { return a->getPerimeter() > b->getPerimeter();} );

  for (auto const&  el : shapesByPerimeter)
  {
    int ID = el->getID();
    double perimeter = el->getPerimeter();
    size_t lenID = std::to_string(ID).length();
    size_t lenPerimeter = std::to_string(perimeter).length();
    std::cout << std::string(7-lenID, ' ') << ID << std::string(25-lenPerimeter, ' ') << perimeter << "\n";
  }

  std::cout << "\n";
}