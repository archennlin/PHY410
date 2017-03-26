#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

class StudentRecord {
 public:
  StudentRecord();
  ~StudentRecord(){}

  std::string firstname() const;
  std::string lastname() const;
  double score() const;


  virtual void print ( std::ostream & out = std::cout ) const = 0;

  virtual bool input ( std::istream & in ) = 0;

  bool operator>( StudentRecord const & right ) const;
  bool operator<( StudentRecord const & right ) const;
  bool operator>=( StudentRecord const & right ) const;
  bool operator<=( StudentRecord const & right ) const;


  friend std::ostream & operator<<( std::ostream & out, StudentRecord const & );
  friend std::istream & operator>>( std::istream & in , StudentRecord const &);


 protected:
  std::string firstname_;              // first name of student
  std::string lastname_;               // last name of student
  std::vector<double> scores_;         // set of scores for the student
  std::vector<double> weights_;        // set of weights for the student
  double score_;                       // average score

  void compute_score(void);            // protected function to compute the score
};

#endif
