#include "Shape.h"
#include <vector>
#include <memory>
#include <algorithm>

class ShapeSorter {

public:
  ShapeSorter() { };
  void areaDescent(std::vector<std::unique_ptr<Shape>> &);
  void perimeterDescent(std::vector<std::unique_ptr<Shape>> &);
  void equal_N_Sides(const std::vector<std::unique_ptr<Shape>> &, const unsigned int &);
  void sameType(const std::vector<std::unique_ptr<Shape>> &, const std::string &);
  
};