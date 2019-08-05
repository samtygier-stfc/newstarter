#include "Use.h"

Use::Use() : m_refCount(new unsigned(1)) {}
Use::Use(const Use &useObj) : m_refCount(useObj.m_refCount) { ++*m_refCount; }
Use::~Use() {
  if (--*m_refCount == 0) {
    delete m_refCount;
  }
}
Use::operator size_t() const { return *m_refCount; }
Use& Use::operator=(const Use &useObj) {
  ++*useObj.m_refCount;
  if (--*m_refCount == 0) {
    delete m_refCount;
  }
  m_refCount = useObj.m_refCount;
  return *this;
}