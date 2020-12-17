#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory>
#include <map>
#include "shape.cpp"

int main()
{
  ShapeSorter o;

  o.add_new(std::make_unique<Triangle>(1.56,7.8,1));
  o.add_new(std::make_unique<Triangle>(6,4,2));
  o.add_new(std::make_unique<Triangle>(123.456,456.123,3));
  o.add_new(std::make_unique<Square>(7,4));
  o.add_new(std::make_unique<Square>(8.765,5));
  o.add_new(std::make_unique<Square>(321.654,6));
  o.add_new(std::make_unique<Rectangle>(2,6.5,7));
  o.add_new(std::make_unique<Rectangle>(0.12,5.23,8));
  o.add_new(std::make_unique<Rectangle>(567.4,23.456,9));
  o.add_new(std::make_unique<Circle>(5,1000));
  o.add_new(std::make_unique<Circle>(3.14,111));
  o.add_new(std::make_unique<Circle>(467.543,120));

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
