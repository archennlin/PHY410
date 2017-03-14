#include "StudentRecordLiterature.h"

StudentRecordLiterature::StudentRecordLiterature(){};
StudentRecordLiterature::~StudentRecordLiterature() {};

void StudentRecordLiterature::print( std::ostream & out ) const  {
  out << "Literature score : " << lastname_ << "," << firstname_
      << ", score 0: " << scores_[0]/0.4 << ", score 1: " << scores_[1]/0.4 <<  ", score 2: " << scores_[2]/0.2
      << ", total: " << score() << std::endl;
}

bool StudentRecordLiterature::input( std::istream & in )  {
  // First add name (last,first)
  std::string line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  // Now get each score. Literature has three, with weights 0.4, 0.4, 0.2
  std::getline( in, line, ',' );
  scores_.push_back( 0.4*std::atof( line.c_str() ) );
  std::getline( in, line, ',' );
  scores_.push_back( 0.4*std::atof( line.c_str() ) );
  std::getline( in, line );
  scores_.push_back( 0.2*std::atof( line.c_str() ) );
  if ( line == "") 
    return false;
  else {
    compute_score();
    return true;
  }
}
