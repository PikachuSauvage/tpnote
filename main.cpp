

#include <cstdio>
#include "String.h"

int main(int argc, char* argv[]){
  printf("Hello\n");
  String h=String();
  String h2(5,'x');
  
  // test capacity
  size_t d=h2.capacity();
  printf("capacité : %zu \n",d);
  
  //test reserve
  h2.reserve(15);
  d=h2.capacity();
  printf("capacité : %zu \n",d);
  
  //test = with char*
  char* c1= new char('a');
  h=c1;
  delete c1;
  
  //test + with string
  String h3(5,'a');
  String h4= h3 + h2;
  printf("Hi there \n");
  
  return 0;
}


