#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>

namespace cjvm{

class Object
{
public:
  Object(std::string n):name(n) {}
  virtual ~Object() {}
  std::string getName(){
    return name;
  }
private:
  std::string name;
};

} /* namespace */

#endif /*OBJECT_H_*/