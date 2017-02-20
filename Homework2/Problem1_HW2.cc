#include <iostream>
#include <cmath>
#include <limits>

int main(void){
  float x1, x2, y1, y2;
  float tolerance = 0.0000001f;
  float slope;
  float xm;
  float ym;
  float b; 
  
  std::cout << "Enter x1, y1;then x2, y2" << std::endl;
  std::cin >> x1 >> y1 >> x2 >> y2;

  if ( std::abs(x1 - x2) < tolerance) {
  std::cout << "Invalid input, use a wider delta-x and then try again!" << std::endl;
  } else {

  slope = (y2-y1)/(x2-x1);
  xm = (x2+x1)/2;
  ym =(y2+y1)/2;
  b = y1-slope*x1; 
    std::cout << "Midpoint is: (" << xm << "," << ym << ")" <<  std::endl;
    std::cout << "Slope is:" << slope <<  std::endl;
    std::cout << "Y-intercept is:" << b <<  std::endl;
    std::cout << "Equation is: y=" << slope << "x+" << b <<  std::endl;
  }
return 0;  
}
