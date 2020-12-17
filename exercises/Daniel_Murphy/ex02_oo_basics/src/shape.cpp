#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <map>
#include "shape.h"


std::string Shape::get_type()
{
  return m_type;
}
int Shape::get_sides()
{
  return m_sides;
}
int Shape::get_ID()
{
  return m_ID;
}


std::unique_ptr<Shape> Triangle::clone()
{
  return std::make_unique<Triangle>(*this);
}
double Triangle::get_area()
{
  return 0.5 * m_base * m_height;;
}
double Triangle::get_perimeter()
{
  return m_base + 2*sqrt(pow(m_height,2) + (pow(m_base,2)/4));
}


std::unique_ptr<Shape> Square::clone()
{
  return std::make_unique<Square>(*this);
}
double Square::get_area()
{
  return pow(m_side1,2);
}
double Square::get_perimeter()
{
  return m_side1*4;
}


std::unique_ptr<Shape> Rectangle::clone()
{
  return std::make_unique<Rectangle>(*this);
}
double Rectangle::get_area()
{
  return m_side1 * m_side2;
}
double Rectangle::get_perimeter()
{
  return (2*m_side1) + (2*m_side2);
}


std::unique_ptr<Shape> Circle::clone()
{
  return std::make_unique<Circle>(*this);
}
double Circle::get_area()
{
  return M_PI * pow(m_radius,2);
}
double Circle::get_perimeter()
{
  return 2 * M_PI * m_radius;
}


void ShapeSorter::add_new(std::unique_ptr<Shape> new_shape)
{
  shapes.emplace_back(std::move(new_shape));
}

void ShapeSorter::all_of_one_type(std::string type_requested)
{
  std::vector<int> type_vec;
  for (auto const& el : shapes)
  {
    std::string shape_type = el->get_type();
    if (shape_type == type_requested)
    {
      type_vec.push_back(el->get_ID());
    }
  }
  if (type_vec.size() == 0)
  {
    std::cout << "None of shape type " << type_requested << " were found.";
  }
  else
  {
    std::cout << "The shapes of type " << type_requested << " are:  ";
    for (auto const& el: type_vec)
    {
      std::cout << el << "  ";
    }
  }
  std::cout << "\n";
}

void ShapeSorter::match_number_of_sides(int sides_requested)
{
  std::string plural = "sides";
  if (sides_requested == 1)
  {
    plural = "side";
  }
  std::vector<int> side_vec;
  for (auto const& el: shapes)
  {
    int num_sides = el->get_sides();
    if (num_sides == sides_requested)
    {
      side_vec.push_back(el->get_ID());
    }
  }
  if (side_vec.size() == 0)
  {
    std::cout << "No shapes with " << sides_requested << " sides were found.";
  }
  else
  {
    std::cout << "The shapes with " << sides_requested << " " << plural << " are:  ";
    for (auto const& el: side_vec)
    {
      std::cout << el << "  ";
    }
  }
  std::cout << "\n";
}

void ShapeSorter::area_descending()
{
  std::cout << "\nShape Number      Area / sq u \n";
  std::cout << "############      ###########\n\n";

  std::vector<std::unique_ptr<Shape>> shapes_by_area;
  shapes_by_area.reserve(shapes.size());
  for (const auto& el : shapes)
    shapes_by_area.emplace_back(el->clone());

  struct {
      bool operator()(std::unique_ptr<Shape>& a, std::unique_ptr<Shape>& b) const
      {   
          return a->get_area() > b->get_area();
      }   

  } descending_area;

  std::sort(shapes_by_area.begin(), shapes_by_area.end(), descending_area);

  for (auto const&  el : shapes_by_area)
  {
    int ID = el->get_ID();
    double area = el->get_area();
    size_t ID_len = std::to_string(ID).length();
    size_t area_len = std::to_string(area).length();
    std::cout << std::string(7-ID_len, ' ') << ID << std::string(25-area_len, ' ') << area << "\n";
  }

  std::cout << "\n";
}

void ShapeSorter::perimeter_descending()
{
  std::cout << "\nShape Number      Perimeter / u \n";
  std::cout << "############      #############\n\n";

  std::vector<std::unique_ptr<Shape>> shapes_by_perimeter;
  shapes_by_perimeter.reserve(shapes.size());
  for (const auto& el : shapes)
    shapes_by_perimeter.emplace_back(el->clone());

  struct {
    bool operator()(std::unique_ptr<Shape>& a, std::unique_ptr<Shape>& b) const
    {   
        return a->get_perimeter() > b->get_perimeter();
    }   

  } descending_perimeter;

  std::sort(shapes_by_perimeter.begin(), shapes_by_perimeter.end(), descending_perimeter);

  for (auto const&  el : shapes_by_perimeter)
  {
    int ID = el->get_ID();
    double perimeter = el->get_perimeter();
    size_t ID_len = std::to_string(ID).length();
    size_t perimeter_len = std::to_string(perimeter).length();
    std::cout << std::string(7-ID_len, ' ') << ID << std::string(25-perimeter_len, ' ') << perimeter << "\n";
  }

  std::cout << "\n";
}