/*Create a program that calculates the factorial of an unsigned integer, if the integer is less than 20. This should use a function called "factorial" that computes the factorial. But if the input is larger than 20, create a function called "Stirling" that will use Stirling's approximation to compute its logarithm instead. Your code should handle both cases with the same "main" program.*/


#include <iostream>
#include <cmath>


int main(void){
  
    unsigned int n;
    float factorial = 1;
  std::cout << "Enter a positive integer smaller than 30" << std::endl;
  while( std::cin >> n ) {
    if ( n < 0 || n > 30 ) {
      std::cout << "Invalid number entered, exiting." << std::endl;
      break;
    } else if (n<20 && n>=0){
      for(int i = 1; i <=n; ++i){
        factorial *= i;
    }
	std:: cout << "Factorial of " << n << " = " << factorial << std::endl;
	break;
    }else {
      factorial =exp(n*log(n)-n);

	std:: cout << "Factorial of " << n << " given by Stirling approximation = " << factorial << std::endl;
	break;
      }
    }
      return 0;
}
