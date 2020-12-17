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
  std::string m_type;
  int m_sides;
  int m_ID;

  std::string get_type();
  int get_sides();
  int get_ID();


  Shape(std::string type, int sides, int ID)
    : m_type{type}, m_sides{sides}, m_ID{ID}
  {}

  virtual std::unique_ptr<Shape> clone() = 0; 
  virtual double get_area() = 0;
  virtual double get_perimeter()= 0;
  virtual ~Shape(){};

};

class Triangle : public Shape
{
public:
  double m_base, m_height;

  Triangle(double base, double height, int ID)
    : Shape{"Triangle", 3, ID}, m_base{base}, m_height{height}
  {}

  std::unique_ptr<Shape> clone() override;
  double get_area() override;
  double get_perimeter() override;
};

class Square : public Shape
{
public:
  double m_side1;

  Square(double side1, int ID)
    : Shape{"Square", 4, ID}, m_side1{side1}
  {}

  std::unique_ptr<Shape> clone() override;
  double get_area() override;
  double get_perimeter() override;
};

class Rectangle: public Shape
{
public:
  double m_side1, m_side2;

  Rectangle(double side1, double side2, int ID)
    : Shape{"Rectangle", 4, ID}, m_side1{side1}, m_side2{side2}
  {}

  std::unique_ptr<Shape> clone() override;
  double get_perimeter() override;
  double get_area() override;
};

class Circle : public Shape
{
public:
  double m_radius;

  Circle(double radius, int ID)
    : Shape{"Circle", 1, ID}, m_radius{radius}
  {}

  std::unique_ptr<Shape> clone() override;
  double get_perimeter() override;
  double get_area() override;
};

class ShapeSorter
{
public:
  std::vector<std::unique_ptr<Shape>> shapes;
  void add_new(std::unique_ptr<Shape> new_shape);

  void all_of_one_type(std::string type_requested);
  void match_number_of_sides(int sides_requested);
  void area_descending();
  void perimeter_descending();
};

#endif // !MAIN_H