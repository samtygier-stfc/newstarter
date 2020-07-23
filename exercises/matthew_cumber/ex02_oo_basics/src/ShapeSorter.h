#pragma once

/** A function to compare the area of two shapes
 * @param s1 The first shape
 * @param s2 The second shape
 * @return A boolean true if the area of s1 < area of s2, false otherwise
 */
bool compareArea(const std::unique_ptr<Shape> &s1, const std::unique_ptr<Shape> &s2)
{
  return s1->area() < s2->area();
}

/** A function to compare the perimeter of two shapes
 * @param s1 The first shape
 * @param s2 The second shape
 * @return A boolean true if the perimeter of s1 < area of s2, false otherwise
 */
bool comparePerimeter(const std::unique_ptr<Shape> &s1, const std::unique_ptr<Shape> &s2)
{
  return s1->perimeter() < s2->perimeter();
}

template <class T> class ShapeSorter
{
public:

  /** A method to print only shapes of only a given type
   * @param shapes A vector of pointers of shape objects
   * @param type A string which is the type of shapes to be printed
   */
  void findType(const std::vector<std::unique_ptr<T>> &shapes, const std::string type)
  {
    // Loop all shapes and check if types match param type
    for(const auto &shape : shapes)
    {
      if(shape->getType() == type)
        std::cout << shape->toString() << std::endl;
    }

    return;
  }

  /** A method to print only shapes with a given number of sides
   * @param shapes A vector of pointers of shape objects
   * @param numSides The number of sides a shape must have to be printed
   */
  void findSides(const std::vector<std::unique_ptr<T>> &shapes, const int numSides)
  {
    // Loop all shapes and check if types match param numSides
    for(const auto &shape : shapes)
    {
      if(shape->getNumSides() == numSides)
        std::cout << shape->toString() << std::endl;
    }
    return;
  }

  /** A method to print the area of the shapes in a vector in descending order
   * @param shapes A vector of pointers of shape objects
   * @return No return value
   */
  void printOrderArea(std::vector<std::unique_ptr<T>> &shapes)
  {
    // Sort shapes by area then reverse order to get descending order
    std::sort(shapes.begin(), shapes.end(), compareArea);
    std::reverse(shapes.begin(), shapes.end());

    for(const auto &shape : shapes)
    {
      std::cout << shape->toString() << std::endl;
    }

    return;
  }

  /** A method to print the perimeter of the shapes in a vector in descending order
   * @param shapes A vector of pointers of shape objects
   * @return No return value
   */
  void printOrderPerimeter(std::vector<std::unique_ptr<T>> &shapes)
  {
    // Sort shapes by perimeter then reverse order to get descending order
    std::sort(shapes.begin(), shapes.end(), comparePerimeter);
    std::reverse(shapes.begin(), shapes.end());

    for(const auto &shape : shapes)
    {
      std::cout << shape->toString() << std::endl;
    }

    return;
  }
};