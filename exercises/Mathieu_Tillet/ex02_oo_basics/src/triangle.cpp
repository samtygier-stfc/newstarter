#include "triangle.h"

using namespace std;

Triangle::Triangle(): base(0), height(0){
    sides = 3;
    shape_type = "Triangle";
}

Triangle::Triangle(double t_height, double t_base): base(t_base), height(t_height){
    sides = 3;
    shape_type = "Triangle";
}

double Triangle::area(){
    return base*height/2;
}

double Triangle::perimeter(){
    return base + 2*sqrt(height*height + base*base/4);
}

ostream& Triangle::display(ostream &os){
    os << shape_type << " Base: " << base << " Height: " << height << endl;
}
