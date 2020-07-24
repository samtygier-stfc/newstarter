#pragma once
#include "BaseShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "ShapeSorter.h"
#include <memory>


int main(int, char **)
{
  Square smallSquare{4};
  Square largeSquare{ 6 };
  Square largerSquare{ 8 };
  Square largestSquare{ 10 };

  Triangle smallTriangle{ 3,4 };
  Triangle largeTriangle{ 6,8 };
  Triangle largestTriangle{ 10,12 };

  Rectangle smallRectangle{ 2,3 };
  Rectangle largeRectangle{ 4,5 };
  Rectangle largerRectangle{ 6,7 };
  Rectangle largestRectangle{ 8,10 };
  Circle smallCircle{ 3 };
  Circle largeCircle{ 7 };
  Circle largestCircle{ 10 };

  
  
  //std::cout << allShapes[1]->type;
  ShapeSorter varietyOfShapes{  };
  varietyOfShapes.addShape(smallSquare);
  varietyOfShapes.addShape(smallRectangle);
  varietyOfShapes.addShape(smallTriangle);
  varietyOfShapes.addShape(smallCircle);
  varietyOfShapes.addShape(largeSquare);
  varietyOfShapes.addShape(largeTriangle);
  varietyOfShapes.addShape(largeCircle);
  varietyOfShapes.addShape(largeRectangle);
  varietyOfShapes.addShape(largerRectangle);
  varietyOfShapes.addShape(largerSquare);
  varietyOfShapes.addShape(largestCircle);
  varietyOfShapes.addShape(largestRectangle);
  varietyOfShapes.addShape(largestSquare);
  varietyOfShapes.addShape(largestTriangle);








  Square squareShape{ 20 };
  varietyOfShapes.addShape(squareShape);
  Rectangle rectangleShape{ 20,15 };
  varietyOfShapes.addShape(rectangleShape);
  Triangle triangleShape{ 20,20 };
  varietyOfShapes.addShape(triangleShape);
  std::cout << "---------------------------------------Squares---------------------------------------------------" << std::endl;
  varietyOfShapes.displayByType(std::string{ "Square" });
  std::cout << "---------------------------------------Rectangles---------------------------------------------------" << std::endl;
  varietyOfShapes.displayByType(std::string{ "Rectangle" });
  std::cout << "---------------------------------------Triangles---------------------------------------------------" << std::endl;
  varietyOfShapes.displayByType(std::string{ "Triangle" });
  std::cout << "---------------------------------------By Area---------------------------------------------------" << std::endl ;
  varietyOfShapes.displayByArea();
  std::cout << "-----------------------------------------By Perimeter-------------------------------------------------" << std::endl ;
  varietyOfShapes.displayByPerimeter();
  std::cout << "-------------------------------------By Number Of Sides-----------------------------------------------------" << std::endl ;
  varietyOfShapes.displayByNumberOfSides();
  
  


  
}