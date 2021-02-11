/**
 * Skeleton main routine
 */

#include "Shape.h"
#include <vector>


int main(void){

    std::vector<std::unique_ptr<Shape>> vecShape;
    vecShape.push_back(std::make_unique<Rectangle>("Rectangle", 2, 3.0, 4.0));
    // Square is instantiated as a rectangle with one side and two equal side values
    vecShape.push_back(std::make_unique<Rectangle>("Square", 1, 3.0, 3.0));
    vecShape.push_back(std::make_unique<Circle>("Circle", 1, 3.0));
    vecShape.push_back(std::make_unique<Triangle>("Triangle", 2, 3.0, 4.0));
    vecShape.push_back(std::make_unique<Rectangle>("Rectangle", 2, 5.0, 4.0));

    return 0;
}