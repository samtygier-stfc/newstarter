#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <map>

class Shape
{
public:
  virtual std::string get_type() = 0;
  virtual int get_sides() = 0;
  virtual double get_area() = 0;
  virtual double get_perimeter() = 0;
  virtual ~Shape() {};
};

class Triangle : public Shape
{
public:
  double b, h;
  std::string type = "Triangle";
  int sides = 3;

  Triangle(double base, double height)
    : b{base}, h{height}
  {}

  std::string get_type() override;
  int get_sides() override;
  double get_area() override;
  double get_perimeter() override;
};

class Square : public Shape
{
public:
  double s1;
  int sides = 4;
  std::string type = "Square";

  Square(double side1)
    : s1{side1}
  {}

  std::string get_type() override;
  int get_sides() override;
  double get_area() override;
  double get_perimeter() override;
};

class Rectangle: public Shape
{
public:
  std::string type = "Rectangle";
  int sides = 4;
  double s1, s2;

  Rectangle(double side1, double side2)
    : s1{side1}, s2{side2}
  {}

  std::string get_type() override;
  int get_sides() override;
  double get_perimeter() override;
  double get_area() override;
};

class Circle : public Shape
{
public:
  std::string type = "Circle";
  int sides = 1;
  double r;

  Circle(double radius)
    : r{radius}
  {}
  std::string get_type() override;
  int get_sides() override;
  double get_perimeter() override;
  double get_area() override;
};

class ShapeSorter
{
public:
  std::vector<std::unique_ptr<Shape>> shapes;
  void add_new(Triangle a);
  void add_new(Square a);
  void add_new(Rectangle a);
  void add_new(Circle a);

  void all_of_one_type(std::string type_requested);
  void match_number_of_sides(int sides_requested);
  void area_descending();
  void perimeter_descending();
};

#endif // !MAIN_H