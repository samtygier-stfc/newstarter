#include "Shape.h"

Triangle::Triangle(const std::string& inputType, const unsigned int& input_N_Sides, const double& inputBase, const double& inputHeight)
              : Shape::Shape(inputType, input_N_Sides), base { inputBase }, height { inputHeight }
          {
          }