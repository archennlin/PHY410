
#include <stdio.h>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordLiterature.h"
#include "StudentRecordHistory.h"

int main(int argc, char * argv[]) {
 
 std::ifstream inf(argv[1]);
 std::vector<std::shared_ptr<StudentRecord> > lit,his,phy;
 double phyavg=0.;
 double litavg=0.;
 double hisavg=0.;

 while( !inf.eof()){
   std::string line;
   std::getline(inf, line, '\n');

   if(line == ""){
     break;
   }
   else{
     std::stringstream temp(line);
     std::string token;
     std::getline(temp, token, ',');
     std::string student;
     std::getline(temp, student, '\n');
     std::stringstream rec(student);

       if (token == "Physics"){
	 std::shared_ptr<StudentRecord> p1(new StudentRecordPhysics());
	 p1->input(rec);
	 phy.push_back(p1);
	 phy[phy.size()-1]->print(std::cout);
	 phyavg += phy[phy.size()-1]->score();
       }
      else if(token == "History"){
	 std::shared_ptr<StudentRecord> p1(new StudentRecordHistory());
	 p1->input(rec);
	 his.push_back(p1);
	 his[his.size()-1]->print(std::cout);
	 hisavg += his[his.size()-1]->score();
       }
       else if(token == "Literature"){
	 std::shared_ptr<StudentRecord> p1(new StudentRecordLiterature());
	 p1->input(rec);
	 lit.push_back(p1);
	 lit[lit.size()-1]->print(std::cout);
	 litavg += lit[lit.size()-1]->score();
       }
       else{
	 std::cout <<student<< " invalid data."<<std::endl;
	 break;
       }
   }
 }
 phyavg /= phy.size();
  hisavg /= his.size();
   litavg /= phy.size();

   std::cout << "The avarage of Physics class is "<< phyavg << std::endl;
   std::cout << "The avarage of History class is "<< hisavg << std::endl;
   std::cout << "The avarage of Literature class is "<< litavg << std::endl;
 
  return 0; 
}
