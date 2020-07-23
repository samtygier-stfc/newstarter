#include "Shapes.h"

int main(int, char **)
{
  Square smallSquare{4};
  Square largeSquare{ 6 };
  Square largerSquare{ 8 };
  Square largestSquare{ 10 };
 // std::cout << largeSquare.calculateArea() << "   " << largeSquare.calculatePerimeter();
  Triangle smallTriangle{ 3,4 };
  Triangle largeTriangle{ 6,8 };
  Triangle largestTriangle{ 10,12 };

  Rectangle smallRectangle{ 2,3 };
  Rectangle largeRectangle{ 4,5 };
  Rectangle largerRectangle{ 6,7 };
  Rectangle largestRectangle{ 8,10 };

  std::vector < BaseShape*> allShapes;
  allShapes.push_back(&smallSquare);
  allShapes.push_back(&smallRectangle);
  allShapes.push_back(&smallTriangle);
  allShapes.push_back(&largeSquare);
  allShapes.push_back(&largeTriangle);
  allShapes.push_back(&largeRectangle);
  allShapes.push_back(&largerSquare);
  allShapes.push_back(&largerRectangle);
  allShapes.push_back(&largestSquare);
  allShapes.push_back(&largestTriangle);
  allShapes.push_back(&largestRectangle);
  
  //std::cout << allShapes[1]->type;
  ShapeSorter varietyOfShapes{ allShapes };
  Square squareShape{ 20 };
  varietyOfShapes.addShape(squareShape);
  Rectangle rectangleShape{ 20,15 };
  varietyOfShapes.addShape(rectangleShape);
  Triangle triangleShape{ 20,20 };
  varietyOfShapes.addShape(triangleShape);
  std::cout << "---------------------------------------Squares---------------------------------------------------" << std::endl;
  varietyOfShapes.displayByType("Square");
  std::cout << "---------------------------------------Rectangles---------------------------------------------------" << std::endl;
  varietyOfShapes.displayByType("Rectangle");
  std::cout << "---------------------------------------Triangles---------------------------------------------------" << std::endl;
  varietyOfShapes.displayByType("Triangle");
  std::cout << "---------------------------------------By Area---------------------------------------------------" << std::endl ;
  varietyOfShapes.displayByArea();
  std::cout << "-----------------------------------------By Perimeter-------------------------------------------------" << std::endl ;
  varietyOfShapes.displayByPerimeter();
  std::cout << "-------------------------------------By Number Of Sides-----------------------------------------------------" << std::endl ;
  varietyOfShapes.displayByNumberOfSides();
  
  


  
}