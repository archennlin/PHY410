#include "StudentRecordHistory.h"

StudentRecordHistory::StudentRecordHistory(){};
StudentRecordHistory::~StudentRecordHistory() {};

void StudentRecordHistory::print( std::ostream & out ) const  {
  out << "History score : " << lastname_ << "," << firstname_
      << ", score 0: " << scores_[0]/0.6 << ", score 1: " << scores_[1]/0.4 
      << ", total: " << score() << std::endl;
}

bool StudentRecordHistory::input( std::istream & in )  {
  // First add name (last,first)
  std::string line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  // Now get each score. with weights 0.6, 0.4
  std::getline( in, line, ',' );
  scores_.push_back( std::atof( line.c_str() ) );
  std::getline( in, line );
  scores_.push_back( std::atof( line.c_str() ) );
  double swap;
  if(scores_[0] > scores_[1]){
    scores_[0] = scores_[0]*0.6;
    scores_[1] = scores_[1]*0.4;
  }
  else{
    swap = scores_[0];
    scores_[0]=scores_[1]*0.6;
    scores_[1]=swap*0.4;
  }
      
  if ( line == "") 
    return false;
  else {
    compute_score();
    return true;
  }
}
