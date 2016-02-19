

#include <cstdio>
#include "String.h"

int main(int argc, char* argv[]){
  printf("Hello\n");
  String h();
  String h2(5,'x');
  size_t d=h2.capacity();
  printf("capacité : %zu \n",d);
  return 0;
}


