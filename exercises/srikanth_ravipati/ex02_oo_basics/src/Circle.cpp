#include "Circle.h"

Circle::Circle(const std::string &inputType, const unsigned int &input_N_Sides, 
               const double &inputRadius)
    : Shape::Shape(inputType, input_N_Sides), radius { inputRadius }
    {
    }