#ifndef STUDENTRECORDPHYSICS_H
#define STUDENTRECORDPHYSICS_H

#include "StudentRecord.h"

class StudentRecordPhysics : public StudentRecord {
  
 public:

  StudentRecordPhysics();
  ~StudentRecordPhysics();

  virtual void print( std::ostream & out = std::cout ) const;

  virtual bool input( std::istream & in );
};

#endif
