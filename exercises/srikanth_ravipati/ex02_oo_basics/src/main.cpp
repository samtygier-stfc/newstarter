#include "ShapeSorter.h"

int main(void) {

    std::vector<std::unique_ptr<Shape>> vecShape;
    vecShape.push_back(std::make_unique<Rectangle>("Rectangle", 2, 3.0, 4.0));
    // Square is instantiated as a rectangle with one distinct side and
    // two equal side values
    vecShape.push_back(std::make_unique<Rectangle>("Square", 1, 3.0));
    vecShape.push_back(std::make_unique<Circle>("Circle", 1, 3.0));
    vecShape.push_back(std::make_unique<Triangle>("Triangle", 2, 3.0, 4.0));
    vecShape.push_back(std::make_unique<Rectangle>("Rectangle", 2, 5.0, 4.0));

    for (auto &vecShapeElement : vecShape) {
      vecShapeElement->calculateInfo();
    }

    for (auto &vecShapeElement : vecShape) {
      vecShapeElement->printInfo();
    }

    std::unique_ptr<ShapeSorter> objShapeSorter = std::make_unique<ShapeSorter>();
    objShapeSorter->equal_N_Sides(vecShape, 1);
    objShapeSorter->sameType(vecShape, "Rectangle");
    objShapeSorter->perimeterDescent(vecShape);
    objShapeSorter->areaDescent(vecShape);

    return 0;
}