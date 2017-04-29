#ifndef EASYDOC_CLASS_DESC_H
#define EASYDOC_CLASS_DESC_H

#include "Serializable.h"
#include "Link.h"

#include <string>
#include <vector>

namespace easydoc
{

class ClassDesc :
  public CXXDesc
{
private:
  std::string fullyQualifiedName;
  std::vector<ClassDesc> subClasses;

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive& ar, const unsigned int version)
  {
    ar & fullyQualifiedName;
    ar & subClasses;
  }

public:
  inline void setFullyQualifiedName(const std::string& name);
  inline const std::string& getFullyQualifiedName() const;

  inline void addSubClass(const ClassDesc& cl);
  inline const ClassDesc&
    getSubClass(std::vector<ClassDesc>::size_type index) const;
  inline ClassDesc& getSubClass(std::vector<ClassDesc>::size_type index);
};

void ClassDesc::setFullyQualifiedName(const std::string& name)
{
  fullyQualifiedName = name;
}

const std::string& ClassDesc::getFullyQualifiedName() const
{
  return fullyQualifiedName;
}

void ClassDesc::addSubClass(const ClassDesc& cl)
{
  subClasses.emplace_back(cl);
}

const ClassDesc&
ClassDesc::getSubClass(std::vector<ClassDesc>::size_type index) const
{
  return subClasses[index];
}

ClassDesc& ClassDesc::getSubClass(std::vector<ClassDesc>::size_type index)
{
  return subClasses[index];
}

} // namespace easydoc

#endif
