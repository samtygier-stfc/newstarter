#pragma once
#include "BaseShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "ShapeSorter.h"



int main(int, char **)
{
    Square smallSquare{ 4 };
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


    ShapeSorter varietyOfShapes;
    varietyOfShapes.addShape(std::make_shared<Square>(smallSquare));
    varietyOfShapes.addShape(std::make_shared<Rectangle>(smallRectangle));
    varietyOfShapes.addShape(std::make_shared<Triangle>(smallTriangle));
    varietyOfShapes.addShape(std::make_shared<Circle>(smallCircle));
    varietyOfShapes.addShape(std::make_shared<Square>(largeSquare));
    varietyOfShapes.addShape(std::make_shared<Triangle>(largeTriangle));
    varietyOfShapes.addShape(std::make_shared<Circle>(largeCircle));
    varietyOfShapes.addShape(std::make_shared<Rectangle>(largeRectangle));
    varietyOfShapes.addShape(std::make_shared<Rectangle>(largerRectangle));
    varietyOfShapes.addShape(std::make_shared<Square>(largerSquare));
    varietyOfShapes.addShape(std::make_shared<Circle>(largestCircle));
    varietyOfShapes.addShape(std::make_shared<Rectangle>(largestRectangle));
    varietyOfShapes.addShape(std::make_shared<Square>(largestSquare));
    varietyOfShapes.addShape(std::make_shared<Triangle>(largestTriangle));
    

    std::cout << "---------------------------------------Squares---------------------------------------------------" << std::endl;
    varietyOfShapes.displayByType(std::string{ "Square" });

    std::cout << "---------------------------------------Rectangles---------------------------------------------------" << std::endl;
    varietyOfShapes.displayByType(std::string{ "Rectangle" });

    std::cout << "---------------------------------------Triangles---------------------------------------------------" << std::endl;
    varietyOfShapes.displayByType(std::string{ "Triangle" });

    std::cout << "---------------------------------------Circle---------------------------------------------------" << std::endl;
    varietyOfShapes.displayByType(std::string{ "Circle" });

    std::cout << "---------------------------------------By Area---------------------------------------------------" << std::endl;
    varietyOfShapes.displayByArea();

    std::cout << "-----------------------------------------By Perimeter-------------------------------------------------" << std::endl;
    varietyOfShapes.displayByPerimeter();

    std::cout << "-------------------------------------By Number Of Sides-----------------------------------------------------" << std::endl;
    varietyOfShapes.displayByNumberOfSides();


  

  
}