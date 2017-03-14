#ifndef STUDENTRECORDLITERATURE_H
#define STUDENTRECORDLITERATURE_H

#include "StudentRecord.h"

class StudentRecordLiterature : public StudentRecord {
  
 public:

  StudentRecordLiterature();
  ~StudentRecordLiterature();

  virtual void print( std::ostream & out = std::cout ) const;

  virtual bool input( std::istream & in );
};

#endif
