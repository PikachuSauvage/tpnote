

#include <cstdio>
#include "String.h"

int main(int argc, char* argv[]){
  printf("Hello\n");
  String h();
  String h2(5,'x');
  String h3=h2;
  printf ("%c \n",h2.getChar(1));
  printf ("%c \n",h3.getChar(1));
  return 0;
}


