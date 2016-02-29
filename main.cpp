

#include <cstdio>
#include "String.h"

int main(int argc, char* argv[]){
  printf("Hello\n");
  String h;
  String h2(5,'x');
  String h3=h2;
  //printf ("%s \n",h3.c_str());
  printf ("%c \n",h2.getChar(1));
  printf ("%c \n",h3.getChar(1));
  printf ("%s \n",h2.c_str());
  h2.clear();
  printf ("%s \n",h2.c_str());
  h2=h3;
  printf ("%s \n",h2.c_str());
  h3=h2+'c';
  printf ("%s \n",h3.c_str());
  
  return 0;
}


