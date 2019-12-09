#include "triangle.h"

Triangle::Triangle(){
    sides = 3;
    shape_type = "Triangle";
    base = 0;
    height = 0;
    //Triangle(0, 0);
}

Triangle::Triangle(double t_height, double t_base){
    sides = 3;
    shape_type = "Triangle";
    base = t_base;
    height = t_height;
}

double Triangle::area(){
    return base*height/2;
}

double Triangle::perimeter(){
    return base + 2*sqrt(height*height + base*base/4);
}
