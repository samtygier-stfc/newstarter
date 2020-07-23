#include "ShapeSorter.h"
#include <memory>

int main(int argc, const char** argv) {

  std::vector<std::unique_ptr<Shape>> shp_vect;

  shp_vect.push_back(std::make_unique<Square>(3));
  shp_vect.push_back(std::make_unique<Square>(25));
  shp_vect.push_back(std::make_unique<Square>(5.765));
  shp_vect.push_back(std::make_unique<Square>(463435));
  shp_vect.push_back(std::make_unique<Square>(2345.4523));
  shp_vect.push_back(std::make_unique<Rectangle>(2,44565));
  shp_vect.push_back(std::make_unique<Rectangle>(3,5.346));
  shp_vect.push_back(std::make_unique<Rectangle>(456,434));
  shp_vect.push_back(std::make_unique<Rectangle>(3.345234,543));
  shp_vect.push_back(std::make_unique<Rectangle>(22341,4.1));
  shp_vect.push_back(std::make_unique<Circle>(2));
  shp_vect.push_back(std::make_unique<Circle>(3452));
  shp_vect.push_back(std::make_unique<Circle>(3.53713454));
  shp_vect.push_back(std::make_unique<Circle>(245));
  shp_vect.push_back(std::make_unique<Circle>(3345));
  shp_vect.push_back(std::make_unique<Triangle>(353,5.645));
  shp_vect.push_back(std::make_unique<Triangle>(545.54,24));
  shp_vect.push_back(std::make_unique<Triangle>(345,5345));
  shp_vect.push_back(std::make_unique<Triangle>(7.54,0.346256));
  shp_vect.push_back(std::make_unique<Triangle>(354,54275));

  ShapeSorter ss(shp_vect);
}