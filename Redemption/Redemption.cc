
#include <stdio.h>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordLiterature.h"
#include "StudentRecordHistory.h"

bool lessthan( std::shared_ptr<StudentRecord> const &left, std::shared_ptr<StudentRecord> const & right) { return *left < *right;}

int main(int argc, char * argv[]) {
 
 std::ifstream inf(argv[1]);
 std::vector<std::shared_ptr<StudentRecord> > records,lit,his,phy;
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
	 records.push_back(p1);
	 phy.push_back(p1);
	 //phy[phy.size()-1]->print(std::cout);
	 phyavg += phy[phy.size()-1]->score();
       }
      else if(token == "History"){
	 std::shared_ptr<StudentRecord> p1(new StudentRecordHistory());
	 p1->input(rec);
	 records.push_back(p1);
	 his.push_back(p1);
	 // his[his.size()-1]->print(std::cout);
	 hisavg += his[his.size()-1]->score();
       }
       else if(token == "Literature"){
	 std::shared_ptr<StudentRecord> p1(new StudentRecordLiterature());
	 p1->input(rec);
	 records.push_back(p1);
	 lit.push_back(p1);
	 //lit[lit.size()-1]->print(std::cout);
	 litavg += lit[lit.size()-1]->score();
       }
       else{
	 std::cout <<student<< " invalid data."<<std::endl;
	 break;
       }
   }
 }

 std::sort( records.begin(), records.end(), lessthan);
 std::sort( phy.begin(), phy.end(), lessthan);
 std::sort( his.begin(), his.end(), lessthan);
 std::sort( lit.begin(), lit.end(), lessthan);

 std::cout << "Physics class sorted by total score: " << std::endl;
 for (std::shared_ptr<StudentRecord> const & rec : phy ){
   rec->print(std::cout );
 }
 std::cout << "History class sorted by total score: " << std::endl;
 for (std::shared_ptr<StudentRecord> const & rec : his ){
   rec->print(std::cout );
 }
  std::cout << "Literature class sorted by total score: " << std::endl;
 for (std::shared_ptr<StudentRecord> const & rec : lit ){
   rec->print(std::cout );
 }
  std::cout << "Total grade of all student sorted by total score: " << std::endl;
 for (std::shared_ptr<StudentRecord> const & rec : records ){
   rec->print(std::cout );
 }

 
 std::cout<<std::endl;
 
}
