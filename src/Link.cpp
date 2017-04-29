#include "Link.h"

namespace easydoc
{

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
