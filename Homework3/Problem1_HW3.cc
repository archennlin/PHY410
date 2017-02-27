#include <iostream>
#include <cmath>


int main(void){
  int n,k;
  unsigned int i=0;
  float m,l;
  std::cout<<"enter the number of vectors you are going to compare."<<std::endl;
  std::cin>>n;
  float a[n]={};
  float b[n]={};
  std::cout<<"enter the x-component of all vectors in order."<<std::endl;

  for ( unsigned int i = 0; i < n; ++i) {
    std::cout<<"enter the x-component:"<<std::endl;
std::cin >> a[i];
  }

 std::cout<<"enter the x-component of all vectors in order."<<std::endl;
 for ( unsigned int i = 0; i < n; ++i){
   std::cout<<"enter the y-component:"<<std::endl;
   std::cin >> b[i];
  }
 
 m=a[0]*a[0]+b[0]*b[0];
 
  for (i = 0; i < n; ++i){
     if(a[i]*a[i]+b[i]*b[i]<m){
       m=a[i]*a[i]+b[i]*b[i];
       k=i;
     }
   }
  l=sqrt(m);
  std::cout<<"the minimal pair is (" << a[k] <<"," << b[k] <<"), and the magnitude is "<< l <<std::endl;
 return 0;
}
