#ifndef EASYDOC_LINK_H
#define EASYDOC_LINK_H

#include "CXXDesc.h"

#include <string>

namespace easydoc
{

// link class
class Link
{
public:
  inline void setFullyQualifiedName(const std::string& name);
  inline const std::string& getFullyQualifiedName() const;

  enum class linkType
  {
    ClassDesc,
    FunctionDesc,
  };

private:
  std::string fullyQualifiedName;
  CXXDesc* cxxDesc;
  linkType type;
};

// link member function inline definitions
void Link::setFullyQualifiedName(const std::string& name)
{
  fullyQualifiedName = name;
}

const std::string& Link::getFullyQualifiedName() const
{
  return fullyQualifiedName;
}

// non member function declarations
std::string getLinkPath(const Link& link);

} // namespace easydoc

#endif
