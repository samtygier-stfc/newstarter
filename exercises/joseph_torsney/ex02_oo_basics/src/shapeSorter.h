#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "shape.h"
#include <iostream>
#include <vector>

class ShapeSorter {
  public:
    ShapeSorter(std::vector<Shape*> v) {
      shapes = v;
    }
  
  /** Prints the shape objects that match a given type
   * 
   * @param type the type of shapes to print
   */
  void printMatching(std::string type) {
    for (auto it = shapes.begin(); it != shapes.end(); it++) {
      if (type == (*it)->getType()) {
        std::cout << (*it)->toString() << std::endl;
      }
    }
  }

  /** Prints the shape objects that have a given number of sides
   * 
   * @param sides the number of sides of shapes to print
   */
  void printSides(int sides) {
    for (auto it = shapes.begin(); it != shapes.end(); it++) {
      if (sides == (*it)->getSides()) {
        std::cout << (*it)->toString() << std::endl;
      }
    }
  }

  /** Prints the areas of the shapes in descending order
   * 
   */
  void printAreas() {

  }

  /** Prints the perimeters of the shapes in descending order
   * 
   */
  void printPerimeters() {

  }

  private:
    std::vector<Shape*> shapes;
};

#endif