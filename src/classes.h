#ifndef CLASSES_H_
#define CLASSES_H_

#include "object.h"

namespace cjvm{

class Classes : public Object{
public:
  Classes();
  ~Classes();
  int loadClassFile(std::string filename);

};


} /* namespace */

#endif /* CLASSES_H_ */