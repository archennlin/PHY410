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

  if ( scores_.size() == 0 ) {
    return ; 
  }

  score_ = 0.0;
  for ( unsigned int i = 0; i < scores_.size(); ++i ) {
    double iscore = scores_[i];
    score_ += iscore;
  }
  // Since the scores are weighted in each derived class files, we don't have to divide them by the number of scores  
  
}
