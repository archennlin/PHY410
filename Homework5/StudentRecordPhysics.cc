#include "StudentRecordPhysics.h"

StudentRecordPhysics::StudentRecordPhysics(){};
StudentRecordPhysics::~StudentRecordPhysics() {};

void StudentRecordPhysics::print( std::ostream & out  ) const  {
  out << "Physics score : " << lastname_ << "," << firstname_
      << ", score 0: " << scores_[0]/0.8 << ", score 1: " << scores_[1]/0.2
      << ", total: " << score() << std::endl;
}

bool StudentRecordPhysics::input( std::istream & in )  {
  // First add name (last,first)
  std::string line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  // Now get each score. Physics has two
  std::getline( in, line, ',' );
  scores_.push_back( 0.8*std::atof( line.c_str() ) );
  std::getline( in, line );
  scores_.push_back( 0.2*std::atof( line.c_str() ) );
  if ( line == "") 
    return false;
  else {      
    compute_score();                     // Make sure to call compute_score in input!
    return true;
  }
}
