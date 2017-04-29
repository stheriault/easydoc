#include "ClassDesc.h"

#include "Serializable.h"

#include <iostream>
#include <fstream>

main()
{
  easydoc::ClassDesc cd;
  cd.setFullyQualifiedName("Hello world");
  easydoc::ClassDesc scd;
  scd.setFullyQualifiedName("From Steven");
  cd.addSubClass(scd);

  // save data to archive
  {
    std::ofstream ofs("filename");
    boost::archive::binary_oarchive oa(ofs);
    // write class instance to archive
    oa << cd;
    // archive and stream closed when destructors are called
  }

  // ... some time later restore the class instance to its orginal state
  easydoc::ClassDesc cd2;
  {
    // create and open an archive for input
    std::ifstream ifs("filename");
    boost::archive::binary_iarchive ia(ifs);
    // read class state from archive
    ia >> cd2;
    // archive and stream closed when destructors are called
  }

  std::cout << cd2.getFullyQualifiedName() << std::endl;
  std::cout << cd2.getSubClass(0).getFullyQualifiedName() << std::endl;

  easydoc::Link l;
  l.setFullyQualifiedName("to::you::and::you::and::you");

  std::cout << getLinkPath(l) << std::endl;

  return 0;
}
