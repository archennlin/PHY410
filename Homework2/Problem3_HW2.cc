#include <iostream>
#include <string>

int main(void) {

 std::string a, b, c;
 int p1=0, p2=0, p3=0, sum;
  
std::cout << "Entrees:" << std::endl;
std::cout << "  e1. Veggie burger: $7" << std::endl;
std::cout << "  e2. Falafel wrap: $6" << std::endl;
std::cout << "  e3. Salami sandwich: $9" << std::endl;

std::cout << "We also offer one of three sides:" << std::endl;

std::cout << "  s1. French fries. $2" << std::endl;
std::cout << "  s2. Hummus with pita chips. $3" << std::endl;
std::cout << "  s3. Celery and carrots $2" << std::endl;

std::cout << "There are eight choices for beverages:" << std::endl; 

std::cout << "  b1. Tap Water. Free of charge." << std::endl;
std::cout << "  b2. Sparkling water. $2" << std::endl;
std::cout << "  b3. Domestic beer. $4." << std::endl;
std::cout << "  b4. Imported beer. $6." << std::endl;
std::cout << "  b5. Red wine. $7." << std::endl;
std::cout << "  b6. White wine. $7." << std::endl;
std::cout << "  b7. Coffee. $1." << std::endl;
std::cout << "  b8. Tea. $1." << std::endl;

std::cout << "Discounted combinations:" << std::endl;
std::cout << "  A veggie burger and fries, plus any non-alcoholic drink (b1,b2,b7,b8) is $8." << std::endl;
std::cout << "  A Falafel wrap plus hummus with pita chips, and any hot beverage (Coffee or Tea) is $7." << std::endl;
std::cout << "  A salami sandwich with any side and any alcoholic beverage is $13." << std::endl;

std::cout << "Please enter your choice of the entree: " << std::endl;
  std::cin >> a;
  while (a!="e1" && a!="e2" && a!="e3")
   {std::cout << "invalid codes, please enter again: " << '\n';
        std::cin >> a;}
  
  std::cout << "Please enter your choice of the side: " << std::endl;
  std::cin >> b;
  while (b!="s1" && b!="s2" && b!="s3")
     {std::cout << "invalid codes, please enter again: " << '\n';
        std::cin >> b;}

  std::cout << "Please enter your choice of the beverage: " << std::endl;
  std::cin >> c;
  while (c!="b1" && c!="b2" && c!="b3" && c!="b4" && c!="b5" && c!="b6" && c!="b7" && c!="b8")
     {std::cout << "invalid codes, please enter again: " << '\n';
        std::cin >> c;}
  
  
  if (a=="e1"){p1=7;}
  else if (a=="e2"){p1=6;}
  else if (a=="e3"){p1=9;}
  else {}
  
  if (b=="s1"){p2=2;}
  else if (b=="s2"){p2=3;}
  else if (b=="s3"){p2=2;}
  else {}

  if (c=="b1"){p3=0;}
  else if (c=="b2"){p3=2;}
  else if (c=="b3"){p3=4;}
  else if (c=="b4"){p3=6;}
  else if (c=="b5"){p3=7;}
  else if (c=="b6"){p3=7;}
  else if (c=="b7"){p3=1;}
  else if (c=="b8"){p3=1;}
  else {}
  sum=p1+p2+p3;
  
  //special combo 1
  if (a=="e1" && b=="s1")
    { if (c=="b1" || c=="b2" || c=="b7" || c=="b8")
	{sum=8;}
      else {};}
  else {}

  //special combo 2
  if (a=="e2" && b=="s2")
    { if (c=="b1" || c=="b2" || c=="b7" || c=="b8")
	{sum=7;}
      else {};}
  else {}

 
  //special combo 3
  if (a=="e3")
    { if (c=="b3" || c=="b4" || c=="b5" || c=="b6")
  	{sum=13;}
	   else {};}
   else {}
  
  //output
    std:: cout << "Your choices are: " << a << " " << b  << " " << c << std::endl;
    std::cout << "Your total is: " << sum  << " dollars" << std::endl;

  return 0;
}
