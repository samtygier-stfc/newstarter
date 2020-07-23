#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <vector>
#include <memory>

class ShapeSorter
{
  private: 
    std::vector<Shape> m_shpVect;
    int m_vecLen;
    
  public:
    ShapeSorter(std::vector<Shape> shpVect);

    const void printShapesType(std::string);

    const void printShapesSides(int);

    void printSortShapesByArea();

    void printSortShapesByPerimeter();

    bool areaCompare(Shape& s1, Shape& s2);

    bool periCompare(Shape& s1, Shape& s2);

    //Member variable accessors and mutators
    std::vector<Shape> getShpVect();
    int getVecLen();

    void setShpVect(std::vector<Shape> shpVect);
};

#endif /* SHAPESORTER_H_ */
