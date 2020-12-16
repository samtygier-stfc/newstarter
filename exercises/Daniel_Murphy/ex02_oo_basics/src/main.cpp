#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <map>
#include "main.h"

std::string Triangle::get_type()
{
  return type;
}

int Triangle::get_sides()
{
  return sides;
}

double Triangle::get_area()
{
  double a = 0.5 * b * h;
  return a;
}

double Triangle::get_perimeter()
{
  double p = b + 2*sqrt(pow(h,2) + (pow(b,2)/4));
  return p;
}

std::string Square::get_type()
{
  return type;
}

int Square::get_sides()
{
  return sides;
}

double Square::get_area()
{
  return pow(s1,2);
}

double Square::get_perimeter()
{
  return s1*4;
}


std::string Rectangle::get_type()
{
  return type;
}

int Rectangle::get_sides()
{
  return sides;
}
double Rectangle::get_perimeter()
{
  double p = (2*s1) + (2*s2);
  return p;
}
double Rectangle::get_area()
{
  double a = s1 * s2;
  return a;
}


std::string Circle::get_type()
{
  return type;
}

int Circle::get_sides()
{
  return sides;
}
double Circle::get_perimeter()
{
  double p = 2 * M_PI * r;
  return p;
}
double Circle::get_area()
{
  double a = 4 * M_PI * pow(r,2);
  return a;
}


void ShapeSorter::add_new(Triangle a)
{
  shapes.emplace_back(std::make_unique<Triangle>(a.b,a.h));
}
void ShapeSorter::add_new(Square a)
{
  shapes.emplace_back(std::make_unique<Square>(a.s1));
}
void ShapeSorter::add_new(Rectangle a)
{
  shapes.emplace_back(std::make_unique<Rectangle>(a.s1,a.s2));
}
void ShapeSorter::add_new(Circle a)
{
  shapes.emplace_back(std::make_unique<Circle>(a.r));
}

void ShapeSorter::all_of_one_type(std::string type_requested)
{
  std::vector<int> type_vec;
  int number = 1;
  for (auto const& el : shapes)
  {
    std::string shape_type = el->get_type();
    if (shape_type == type_requested)
    {
      type_vec.push_back(number);
    }
    number++;
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
  int number = 1;
  for (auto const& el: shapes)
  {
    int num_sides = el->get_sides();
    if (num_sides == sides_requested)
    {
      side_vec.push_back(number);
    }
    number++;
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

  std::map<double, int> area_map;
  int number = 1;
  for (auto const&  el : shapes)
  {
    double shape_area = el->get_area();
    area_map[shape_area] = number;
    number++;
  }

  // Print areas in descending (reverse) order
  for (auto it = std::next(area_map.end(),1); it != std::prev(area_map.begin(),1); --it)
  {
    int n = it->second;
    double a = it->first;
    size_t num_len = std::to_string(n).length();
    size_t word_len = std::to_string(a).length();
    std::cout << std::string(7-num_len, ' ') << n << std::string(25-word_len, ' ') << a << "\n";
  }
  std::cout << "\n";
}

void ShapeSorter::perimeter_descending()
{
  std::cout << "\nShape Number      Perimeter / u \n";
  std::cout << "############      #############\n\n";

  std::map<double, int> perimeter_map;
  int number = 1;
  for (auto const&  el : shapes)
  {
    double shape_perimeter = el->get_perimeter();
    perimeter_map[shape_perimeter] = number;
    number++;
  }
  // Print perimeters in descending (reverse) order
  for (auto it = std::next(perimeter_map.end(),1); it != std::prev(perimeter_map.begin(),1); --it)
  {
    int n = it->second;
    double a = it->first;
    size_t num_len = std::to_string(n).length();
    size_t word_len = std::to_string(a).length();
    std::cout << std::string(7-num_len, ' ') << n << std::string(25-word_len, ' ') << a << "\n";
  }
  std::cout << "\n";
}

int main()
{
  ShapeSorter o;

  Triangle a = {1.56,7.8}; o.add_new(a);
  Triangle b = {6,4}; o.add_new(b);
  Triangle c = {123.456,456.123}; o.add_new(c);
  Square d = {7}; o.add_new(d);
  Square e = {8.765}; o.add_new(e);
  Square f = {321.654}; o.add_new(f);
  Rectangle g = {2,6.5}; o.add_new(g);
  Rectangle h = {0.12,5.23}; o.add_new(h);
  Rectangle j = {567.4,23.456}; o.add_new(j);
  Circle k = {5}; o.add_new(k);
  Circle l = {3.14}; o.add_new(l);
  Circle m = {467.543}; o.add_new(m);

  std::cout << "\n";

  // Check which shapes have4 as certain type
  std::vector<std::string> shape_types = {"Triangle","Square","Rectangle","Circle"};
  for (std::string type : shape_types)
  {
    o.all_of_one_type(type);
  }

  std::cout << "\n";

  // Check which shapes have a certain number of sides
  for (int i=1; i<5;i++)
  {
    o.match_number_of_sides(i);
  }
  std::cout << "\n";

  // Rank shapes in order of area
  o.area_descending();

  // Rank shapes in order of perimeter
  o.perimeter_descending();
}
