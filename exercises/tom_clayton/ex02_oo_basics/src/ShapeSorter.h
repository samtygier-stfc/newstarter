#pragma once
#include "Shape.h"
#include <vector>
#include <memory>

class ShapeSorter
{

  typedef std::vector<std::shared_ptr<Shape>>::size_type VecSz;

  private: 
    std::vector<std::shared_ptr<Shape>> m_shpVect;
    VecSz m_vecLen;
    
  public:
    ShapeSorter(std::vector<std::shared_ptr<Shape>> shpVect);

    const void printShapesType(std::string);

    const void printShapesSides(int);

    void printSortShapesByArea();

    void printSortShapesByPerimeter();

    //Member variable accessors and mutators
    std::vector<std::shared_ptr<Shape>> getShpVect();
    VecSz getVecLen();

    void setShpVect(std::vector<std::shared_ptr<Shape>> shpVect);
};
