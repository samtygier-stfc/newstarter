#include "rectangle.h"

Rectangle::Rectangle(): side_1(0), side_2(0){
    shape_type = "Rectangle";
    sides = 4;
}

Rectangle::Rectangle(double s_1, double s_2): side_1(s_1), side_2(s_2){
    shape_type = "Rectangle";
    sides = 4;
}

double Rectangle::area(){
    return side_1*side_2;
}

double Rectangle::perimeter(){
    return 2*(side_1 + side_2);
}

ostream& operator<<(ostream &os, const Rectangle &r){
    os << r.shape_type << " Side 1: " << r.side_1 << " Side 2: " << r.side_2 << endl;
}
