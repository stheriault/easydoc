#ifndef EASYDOC_LINK_H
#define EASYDOC_LINK_H

#include "CXXDesc.h"

#include <string>

namespace easydoc
{

class Link
{
private:
  std::string fullyQualifiedName;
  CXXDesc* cxxDesc;

public:
  inline void setFullyQualifiedName(const std::string& name);
  inline const std::string& getFullyQualifiedName() const;
};

void Link::setFullyQualifiedName(const std::string& name)
{
  fullyQualifiedName = name;
}

const std::string& Link::getFullyQualifiedName() const
{
  return fullyQualifiedName;
}

std::string getLinkPath(const Link& link)
{
  //TODO if starts with ::, remove them

  std::string::size_type pos = 0;
  auto subject = link.getFullyQualifiedName();

  while ((pos = subject.find("::", pos)) != std::string::npos)
  {
    subject.replace(pos, 2, "/");
    pos += 1;
  }
  return subject;
}

} // namespace easydoc

#endif
