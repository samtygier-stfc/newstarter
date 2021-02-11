#include "Shape.h"

Shape::Shape(const std::string& inputType, const unsigned int& input_N_Sides)
    : type { inputType }, nSides {input_N_Sides}
{
}

void Shape::calculateInfo(){
         calculatePerimeter();
         calculateArea();
       }

void Shape::printInfo() const {
           std::cout << "Type: " << type << "\t" << "nSides: " << nSides <<
                        "\t" << "Perimeter: " << perimeter << "\t" << "Area: " << area << "\n";
       }