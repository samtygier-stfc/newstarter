#include "Shape.h"

Rectangle::Rectangle(const std::string& inputType, const unsigned int& input_N_Sides, const double& inputSide1, const double& inputSide2)
               : Shape::Shape(inputType, input_N_Sides), side1 { inputSide1 }, side2 { inputSide2 }
           {
           }

Rectangle::Rectangle(const std::string& inputType, const unsigned int& input_N_Sides, const double& inputSide)
               : Shape::Shape(inputType, input_N_Sides), side1 { inputSide }, side2 { inputSide }
           {
           }