#pragma once
#include "Shape.h"
#include <vector>
#include <memory>

class ShapeSorter
{
  private: 
    std::vector<std::shared_ptr<Shape>> m_shpVect;
    size_t m_vecLen;
    
  public:
    ShapeSorter(std::vector<std::shared_ptr<Shape>> shpVect);

    const void printShapesType(std::string);

    const void printShapesSides(int);

    void printSortShapesByArea();

    void printSortShapesByPerimeter();

    //Member variable accessors and mutators
    std::vector<std::shared_ptr<Shape>> getShpVect();
    int getVecLen();

    void setShpVect(std::vector<std::shared_ptr<Shape>> shpVect);
};
