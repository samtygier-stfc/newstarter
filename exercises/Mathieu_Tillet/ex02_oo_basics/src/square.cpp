#include "square.h"

Square::Square(): side_length(0){
    shape_type = "Square";
    sides = 4;
}

Square::Square(double side): side_length(side){
    shape_type = "Square";
    sides = 4;
}

double Square::area(){
    return side_length*side_length;
}

double Square::perimeter(){
    return 4*side_length;
}

ostream& operator<<(ostream &os, const Square &s){
    os << s.shape_type << " Side length: " << s.side_length << endl;
}
