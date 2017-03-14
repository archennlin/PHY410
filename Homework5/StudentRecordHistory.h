#ifndef STUDENTRECORDHISTORY_H
#define STUDENTRECORDHISTORY_H

#include "StudentRecord.h"

class StudentRecordHistory : public StudentRecord {
  
 public:

  StudentRecordHistory();
  ~StudentRecordHistory();

  virtual void print( std::ostream & out = std::cout ) const;

  virtual bool input( std::istream & in );
};

#endif
