#include "shapesorter.h"

ShapeSorter::ShapeSorter(){}

void ShapeSorter::print_by_sides(vector<Shape*> &vec, int side_nb, ostream &os){

    for (vector<Shape*>::iterator it = vec.begin(); it != vec.end(); ++it){
        if ((*it)->sides == side_nb){
            (*it)->display(os);
        }
    }
}

void ShapeSorter::print_by_type(vector<Shape*> &vec, string type, ostream &os){

    for (vector<Shape*>::iterator it = vec.begin(); it != vec.end(); ++it){
        if ((*it)->shape_type == type){
            (*it)->display(os);
        }
    }
}

bool perimeter_comp(Shape *s1, Shape *s2){
    return s1->perimeter() < s2->perimeter();
}

bool area_comp(Shape *s1, Shape *s2){
    return s1->area() < s2->area();
}

void ShapeSorter::print_by_perimeter(vector<Shape*> &vec, ostream &os){
    sort(vec.begin(), vec.end(), perimeter_comp);
    for (vector<Shape*>::iterator it = vec.begin(); it != vec.end(); ++it){
        (*it)->display(os);
    }

}

void ShapeSorter::print_by_area(vector<Shape*> &vec, ostream &os){
    sort(vec.begin(), vec.end(), area_comp);
    for (vector<Shape*>::iterator it = vec.begin(); it != vec.end(); ++it){
        (*it)->display(os);
    }

}
