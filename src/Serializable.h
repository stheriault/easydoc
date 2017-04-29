#ifndef EASYDOC_SERIALIZABLE_H
#define EASYDOC_SERIALIZABLE_H

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/base_object.hpp>

namespace easydoc
{

template<class Archive>
class Serializable
{
public:
  virtual ~Serializable() =default;

  virtual void serialize(Archive& ar, const unsigned int version) =0;
};

} // namespace easydoc

#endif
