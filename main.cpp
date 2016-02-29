
#include <iostream>
#include <cstdio>
#include "String.h"

using namespace std;
int main(int argc, char* argv[]){
  printf("Hello\n");
  String h();
  String h2(5,'x');
  cout << h2.length() << endl;
  h2.resize(20);
  cout << h2.length() << endl;
  h2.resize(0);
  cout << h2.length() << endl;
  return 0;
}


