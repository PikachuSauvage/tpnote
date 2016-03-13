

#include <cstdio>
#include "String.h"

int main(int argc, char* argv[]){
    //Test Constructors:
    printf("==Test for defaut constructor String()==\n");
    String h1=String();
    printf("String h1 delarated with String h=String()\n");
    printf("c_str: %s \n",h1.c_str());
    printf("Length: %zu \n", h1.length());
    printf("Capacity: %zu \n\n",h1.capacity());
    
	printf("==Test for fill constructor String(size_t n, char c)==\n");
    String h2=String(5,'x');
    printf("String h2 delarated with String h2=String(5,'x')\n");
    printf("c_str: %s \n",h2.c_str());
    printf("Length: %zu \n", h2.length());
    printf("Capacity: %zu \n\n",h2.capacity());
    
    String h3=String(55,'x');
	printf("String h3 delarated with String h3=String(55,'x')\n");
	printf("c_str: %s \n",h3.c_str());
    printf("Length: %zu \n", h3.length());
    printf("Capacity: %zu \n\n",h3.capacity());
    
	printf("String h4 delarated with String h4=String(155,'x')\n");
    String h4=String(155,'x');
    printf("c_str: %s \n",h4.c_str());    
    printf("Length: %zu \n", h4.length());
    printf("Capacity: %zu \n\n",h4.capacity());
    
    printf("==Test for Copy Constructor String(const String& str)==\n");
    String h5=String(h1);
    printf("String h5 delarated with String h5=String(h1)\n");
    printf("c_str: %s \n",h5.c_str());
    printf("Length: %zu \n", h5.length());
    printf("Capacity: %zu \n\n",h5.capacity());
    //printf("sizeof %lu\n",sizeof(h4.c_str()));
    String h6=String(h4);
    printf("String h6 delarated with String h6=String(h4)\n");
    printf("c_str: %s \n",h6.c_str());
    printf("Length: %zu \n", h6.length());
    printf("Capacity: %zu \n\n",h6.capacity());
	
	printf("==Test for C_str Constructor String(char* s)==\n");
	char c1[]= "abcdefg";
	printf("c1 = %s\n", c1);
	String h7=String(c1);
    printf("String h7 delarated with String h7=String(c1)\n");
    printf("c_str: %s \n",h7.c_str());
    printf("Length: %zu \n", h7.length());
    printf("Capacity: %zu \n\n",h7.capacity());
    
    char c2[]= "12345678901234567890123456789012345678901234567890"
    "123456789012345678901234567890123456789012345678901234567890"
    "1234567890";
    printf("c2 =%s (lenth=110)\n",c2);
	String h8=String(c2);
    printf("String h8 delarated with String h8=String(c2)\n");
    printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    
    
    //Test of Public Methods
    printf("==Test for c_str()==\n");
    
    
    //String h2(5,'x');
    //String h3=h2;
    ////printf ("%s \n",h3.c_str());
    //printf ("%c \n",h2.getChar(1));
    //printf ("%c \n",h3.getChar(1));
    //printf ("%s \n",h2.c_str());
    //h2.clear();
    //printf ("%s \n",h2.c_str());
    //h2=h3;
    //printf ("%s \n",h2.c_str());
    //h3=h2+'c';
    //printf ("%s \n",h3.c_str());
    //// test capacity
    //size_t d=h2.capacity();
    //printf("capacité : %zu \n",d);
  
    ////test reserve
    //h2.reserve(15);
    //d=h2.capacity();
    //printf("capacité : %zu \n",d);
    //printf("length before: %zu \n", h2.length());
    ////test = with char*
    //char* c1= new char('a');
    //h=c1;
    //delete c1;
  
    ////test + with string
    //String h6(5,'a');
    //String h4= h6 + h2;
    //printf("Hi there \n");
    //// Test for operator+(const String& lhs, const char* rhs)
    //printf("Test for operator+(const String& lhs, const char* rhs\n");
    //h2=h2+h6;
    //printf("length : %zu \n", h2.length());
    //printf("capacity : %zu \n", h2.capacity());
    return 0;
}


