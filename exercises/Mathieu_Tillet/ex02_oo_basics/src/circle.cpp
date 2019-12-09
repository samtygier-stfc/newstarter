#include "circle.h"

Circle::Circle(): radius(0){
    sides = 1;
    shape_type = "Circle";
}

Circle::Circle(double r): radius(r){
    sides = 1;
    shape_type = "Circle";
}

double Circle::area(){
    return M_PI*radius*radius;
}

double Circle::perimeter(){
    return 2*M_PI*radius;
}
