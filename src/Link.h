#ifndef EASYDOC_LINK_H
#define EASYDOC_LINK_H

#include "CXXDesc.h"

#include <string>

namespace easydoc
{

class Link
{
public:
  inline void setFullyQualifiedName(const std::string& name);
  inline const std::string& getFullyQualifiedName() const;

private:
  std::string fullyQualifiedName;
  CXXDesc* cxxDesc;
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
  std::string::size_type pos = 0;
  auto subject = link.getFullyQualifiedName();

  if ((pos = subject.find("::", 0)) == 0)
    subject.erase(0, 2);

  while ((pos = subject.find("::", pos)) != std::string::npos)
  {
    subject.replace(pos, 2, "/");
    pos += 1;
  }
  return subject;
}

} // namespace easydoc

#endif
