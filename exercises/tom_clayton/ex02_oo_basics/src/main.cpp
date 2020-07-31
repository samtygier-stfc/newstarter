#include "ShapeSorter.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <memory>
#include <iostream>

int main(int argc, const char** argv) {

  std::vector<std::shared_ptr<Shape>> shp_vect;
  
  std::shared_ptr<Square> sq1 = std::make_shared<Square>(3);
  std::shared_ptr<Square> sq2 = std::make_shared<Square>(4);
  std::shared_ptr<Square> sq3 = std::make_shared<Square>(3.14613452467);
  std::shared_ptr<Square> sq4 = std::make_shared<Square>(36234);
  std::shared_ptr<Square> sq5 = std::make_shared<Square>(32345);
  std::shared_ptr<Circle> c1 = std::make_shared<Circle>(3);
  std::shared_ptr<Circle> c2 = std::make_shared<Circle>(4);
  std::shared_ptr<Circle> c3 = std::make_shared<Circle>(34325);
  std::shared_ptr<Circle> c4 = std::make_shared<Circle>(0.32475);
  std::shared_ptr<Circle> c5 = std::make_shared<Circle>(34);
  std::shared_ptr<Rectangle> r1 = std::make_shared<Rectangle>(34,6);
  std::shared_ptr<Rectangle> r2 = std::make_shared<Rectangle>(3364,0.5);
  std::shared_ptr<Rectangle> r3 = std::make_shared<Rectangle>(3.45363454,0.1456);
  std::shared_ptr<Rectangle> r4 = std::make_shared<Rectangle>(0.344,2354);
  std::shared_ptr<Rectangle> r5 = std::make_shared<Rectangle>(3344,1);
  std::shared_ptr<Triangle> t1 = std::make_shared<Triangle>(34,456);
  std::shared_ptr<Triangle> t2 = std::make_shared<Triangle>(3.345,235);
  std::shared_ptr<Triangle> t3 = std::make_shared<Triangle>(343,0.31463);
  std::shared_ptr<Triangle> t4 = std::make_shared<Triangle>(1,1);
  std::shared_ptr<Triangle> t5 = std::make_shared<Triangle>(2435,1);
  shp_vect.push_back(sq1);
  shp_vect.push_back(sq2);
  shp_vect.push_back(sq3);
  shp_vect.push_back(sq4);
  shp_vect.push_back(sq5);
  shp_vect.push_back(c1);
  shp_vect.push_back(c2);
  shp_vect.push_back(c3);
  shp_vect.push_back(c4);
  shp_vect.push_back(c5);
  shp_vect.push_back(r1);
  shp_vect.push_back(r2);
  shp_vect.push_back(r3);
  shp_vect.push_back(r4);
  shp_vect.push_back(r5);
  shp_vect.push_back(t1);
  shp_vect.push_back(t2);
  shp_vect.push_back(t3);
  shp_vect.push_back(t4);
  shp_vect.push_back(t5);

  ShapeSorter ss(shp_vect);
  ss.printShapesType("Square");
  ss.printShapesType("Triangle");
  ss.printShapesSides(4);
  ss.printShapesSides(0);
  ss.printSortShapesByArea();
  ss.printSortShapesByPerimeter();
  system("PAUSE");
}