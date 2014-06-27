#include "jvm.h"

namespace cjvm{

Jvm::Jvm()
  :Object("jvm")
  ,logger(Logger())
  ,classes(Classes())
{

}

Jvm::~Jvm()
{

}

} /* namespace */