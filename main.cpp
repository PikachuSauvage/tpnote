

#include <cstdio>
#include "String.h"

int main(int argc, char* argv[]){
  printf("Hello\n");
  String h=String();
  String h2(5,'x');
  
  size_t d=h2.capacity();
  printf("capacité : %zu \n",d);
  
  bool e1;
  e1 = h.empty();
  bool e2 = h2.empty();
  
  h2.reserve(15);
  d=h2.capacity();
  printf("capacité : %zu \n",d);
  
  return 0;

}


