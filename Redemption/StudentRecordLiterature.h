#ifndef STUDENTRECORDLITERATURE_H
#define STUDENTRECORDLITERATURE_H

#include "StudentRecord.h"

class StudentRecordLiterature : public StudentRecord {
  
 public:

  StudentRecordLiterature(){};
  ~StudentRecordLiterature() {};

  virtual void print( std::ostream & out = std::cout ) const  {
    out << lastname_ << "," << firstname_ << "," << scores_[0] << "," << scores_[1] << "," << scores_[2] << "," << score() << std::endl;
  }

  virtual bool input( std::istream & in )  {
    // First add name (last,first)
    std::string line;
    std::getline( in, line, ',');
    lastname_ = line;
    std::getline( in, line, ',');
    firstname_ = line;
    // Now get each score. Literature has three, with weights 0.4, 0.4, 0.2
    std::getline( in, line, ',' );
    scores_.push_back( std::atof( line.c_str() ) );
    weights_.push_back( 0.4 );
    std::getline( in, line, ',' );
    scores_.push_back( std::atof( line.c_str() ) );
    weights_.push_back( 0.4 );
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
