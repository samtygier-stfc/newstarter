#include "ShapeBase.h"

std::string ShapeBase::getName() const { return m_name; }

unsigned ShapeBase::getSides() const { return m_sides; }

unsigned ShapeBase::getCount() const { return m_refCount; }
