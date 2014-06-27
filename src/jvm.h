#ifndef JVM_H_
#define JVM_H_

#include "object.h"

#include "logger.h"
#include "classes.h"

namespace cjvm{
class Jvm : public Object
{
public:
  Jvm();
  virtual ~Jvm();

private:
  Logger logger;
  Classes classes;
  // Threads threads;
  // Scheduler scheduler;

};


} /* namespace */

#endif /* JVM_H_ */
