#include "StudentRecord.h"


StudentRecord::StudentRecord(){}


std::string StudentRecord::firstname() const { return firstname_; }
std::string StudentRecord::lastname() const { return lastname_; }
double StudentRecord::score() const { return score_; }


bool StudentRecord::operator>( StudentRecord const & right ) const {
  return this->score() > right.score();
};

bool StudentRecord::operator>=( StudentRecord const & right ) const {
  return this->score() >= right.score();
};

bool StudentRecord::operator<( StudentRecord const & right ) const {
  return this->score() < right.score();
};

bool StudentRecord::operator<=( StudentRecord const & right ) const {
  return this->score() <= right.score();
};

void StudentRecord::compute_score(void) {

  
  score_ = 0.0;
  for ( unsigned int i = 0; i < scores_.size(); ++i ) {
    double score = scores_[i];
    double weight = weights_[i];
    score_ += score * weight;
  }
  
}



std::ostream & operator<<( std::ostream & out, StudentRecord const &right ){ right.print(out); return out; }
std::istream & operator>>( std::istream & in, StudentRecord  &right ){ right.input(in); return in; }
