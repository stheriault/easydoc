#ifndef EASYDOC_CLASS_DESC_H
#define EASYDOC_CLASS_DESC_H

#include "Serializable.h"

#include <string>

namespace easydoc
{

class ClassDesc :
  public Serializable
{
private:
  std::string fullyQualifiedName;

public:
  void setFullyQualifiedName(std::string name) {fullyQualifiedName = name;};
  std::string getFullyQualifiedName() const {return fullyQualifiedName;};

};

} // namespace easydoc

#endif
