#ifndef STUDENTRECORDPHYSICS_H
#define STUDENTRECORDPHYSICS_H

#include "StudentRecord.h"

class StudentRecordPhysics : public StudentRecord {
  
 public:

  StudentRecordPhysics(){};
  ~StudentRecordPhysics() {};

  virtual void print( std::ostream & out = std::cout ) const  {
    out << lastname_ << "," << firstname_ << "," << scores_[0] << "," << scores_[1] << "," << score() << std::endl;;
  }

  virtual bool input( std::istream & in )  {
    // First add name (last,first)
    std::string line;
    std::getline( in, line, ',');
    lastname_ = line;
    std::getline( in, line, ',');
    firstname_ = line;
    // Now get each score. Physics has two, with weights 0.8 and 0.2
    std::getline( in, line, ',' );
    scores_.push_back( std::atof( line.c_str() ) );
    weights_.push_back( 0.8 );
    std::getline( in, line );
    scores_.push_back( std::atof( line.c_str() ) );
    weights_.push_back( 0.2 );
    if ( line == "") 
      return false;
    else {      
      compute_score();
      return true;
    }
  }

};


#endif
