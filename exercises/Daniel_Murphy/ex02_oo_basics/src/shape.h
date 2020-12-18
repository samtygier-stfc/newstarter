#pragma once

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
  Shape(std::string type, int sides, int ID)
    : m_type{type}, m_sides{sides}, m_ID{ID}
  {}

  std::string getType();
  int getSides();
  int getID();

  virtual std::unique_ptr<Shape> clone() = 0; 
  virtual double getArea() = 0;
  virtual double getPerimeter()= 0;
  virtual ~Shape(){};
private:
  std::string m_type;
  int m_sides;
  int m_ID;
};

class Triangle : public Shape
{
public:
  Triangle(double base, double height, int ID)
    : Shape{"Triangle", 3, ID}, m_base{base}, m_height{height}
  {}

  std::unique_ptr<Shape> clone() override;
  double getArea() override;
  double getPerimeter() override;
private:
  double m_base, m_height;
};

class Square : public Shape
{
public:
  Square(double side1, int ID)
    : Shape{"Square", 4, ID}, m_side1{side1}
  {}

  std::unique_ptr<Shape> clone() override;
  double getArea() override;
  double getPerimeter() override;
private:
  double m_side1;
};

class Rectangle: public Shape
{
public:
  Rectangle(double side1, double side2, int ID)
    : Shape{"Rectangle", 4, ID}, m_side1{side1}, m_side2{side2}
  {}

  std::unique_ptr<Shape> clone() override;
  double getPerimeter() override;
  double getArea() override;
private:
  double m_side1, m_side2;
};

class Circle : public Shape
{
public:
  Circle(double radius, int ID)
    : Shape{"Circle", 1, ID}, m_radius{radius}
  {}

  std::unique_ptr<Shape> clone() override;
  double getPerimeter() override;
  double getArea() override;
private:
  double m_radius;
};

class ShapeSorter
{
public:
  void addNew(std::unique_ptr<Shape> newShape);
  void allOneType(std::string type_requested);
  void matchSideNumber(int sides_requested);
  void areaDescending();
  void perimeterDescending();
private:
  std::vector<std::unique_ptr<Shape>> m_shapes;
};
