#pragma once
#include "Shape.h"
#include <vector>
#include <memory>

class ShapeSorter
{
  private: 
    std::vector<std::shared_ptr<Shape>> m_shpVect;
    int m_vecLen;
    
  public:
    ShapeSorter(std::vector<std::shared_ptr<Shape>> shpVect);

    const void printShapesType(std::string);

    const void printShapesSides(int);

    void printSortShapesByArea();

    void printSortShapesByPerimeter();

    bool areaCompare(std::shared_ptr<Shape> s1, std::shared_ptr<Shape> s2);

    bool periCompare(std::shared_ptr<Shape> s1, std::shared_ptr<Shape> s2);

    //Member variable accessors and mutators
    std::vector<std::shared_ptr<Shape>> getShpVect();
    int getVecLen();

    void setShpVect(std::vector<std::shared_ptr<Shape>> shpVect);
};
