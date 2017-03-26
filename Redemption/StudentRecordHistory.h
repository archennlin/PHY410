#ifndef STUDENTRECORDHISTORY_H
#define STUDENTRECORDHISTORY_H

#include "StudentRecord.h"

class StudentRecordHistory : public StudentRecord {
  
 public:

  StudentRecordHistory(){};
  ~StudentRecordHistory() {};

  virtual void print( std::ostream & out = std::cout ) const  {
    out << lastname_ << "," << firstname_ << "," << scores_[0] << "," << scores_[1] << "," << score() << std::endl;
  }

  virtual bool input( std::istream & in )  {
    // First add name (last,first)
    std::string line;
    std::getline( in, line, ',');
    lastname_ = line;
    std::getline( in, line, ',');
    firstname_ = line;
    // Now get each score. History has two. The highest score is weighted 0.6, the lower is 0.4
    std::getline( in, line, ',' );
    double score1 = std::atof( line.c_str() );
    std::getline( in, line );
    double score2 = std::atof( line.c_str() );    
    if ( score1 > score2 ) {
      scores_.push_back( score1 ); weights_.push_back( 0.6 );
      scores_.push_back( score2 ); weights_.push_back( 0.4 );
    } else {
      scores_.push_back( score2 ); weights_.push_back( 0.6 );
      scores_.push_back( score1 ); weights_.push_back( 0.4 );
    }
    if ( line == "") 
      return false;
    else {
      compute_score();
      return true;
    }
  }
};

#endif
