#include "circle.h"
#include<ostream>

using namespace std;

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

ostream& Circle::display(ostream &os){
    return os << shape_type << " Radius: " << radius;
}
