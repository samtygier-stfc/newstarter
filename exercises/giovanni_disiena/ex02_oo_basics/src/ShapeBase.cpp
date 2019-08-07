#include "ShapeBase.h"

/** Constructs ShapeBase object
 *
 * @param sides: number of sides of the shape
 * @param name: name of shape type
 *
 */
ShapeBase::ShapeBase(unsigned int sides, std::string name)
    : m_sides(sides), m_name(name){};

/** Retrieves shape type name member variable
 *
 * @return m_name: name member variable
 *
 */
std::string ShapeBase::getName() const { return m_name; }

/** Retrieves shape number of sides member variable
 *
 * @return m_sides: sides member variable
 *
 */
unsigned ShapeBase::getSides() const { return m_sides; }