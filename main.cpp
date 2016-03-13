

#include <cstdio>
#include "String.h"

int main(int argc, char* argv[]){
    //Test Constructors:
    printf("*******Test for defaut constructor String()*******\n");
    String h1=String();
    printf("String h1 delarated with String h=String()\n");
    printf("c_str: %s \n",h1.c_str());
    printf("Length: %zu \n", h1.length());
    printf("Capacity: %zu \n\n",h1.capacity());
    
	printf("******Test for fill constructor String(size_t n, char c)"
	"******\n");
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
    
    printf("******Test for Copy Constructor String(const String& str)"
    "*******\n");
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
	
	printf("******Test for C_str Constructor String(char* s)******\n");
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
    printf("c2 = %s (lenth=110)\n",c2);
	String h8=String(c2);
    printf("String h8 delarated with String h8=String(c2)\n");
    printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    
    
    //Test of Public Methods
    printf("******Test for resize()******\n");
    h8.resize(5);
	printf("h8.resize(5):\n");
	printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    h8.resize(0);
    printf("h8.resize(0):\n");
    printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    h8.resize(120);
    printf("h8.resize(120):\n");
    printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    h8.resize(0,'c');
    printf("h8.resize(0,'c');:\n");
    printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    h8.resize(120,'c');
    printf("h8.resize(120,'c'):\n");
    printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    
    printf("******Test for clear()******\n");
    printf("Before h8.clear\n");
    printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    h8.clear();
	printf("After h8.clear()\n");
    printf("c_str: %s \n",h8.c_str());
    printf("Length: %zu \n", h8.length());
    printf("Capacity: %zu \n\n",h8.capacity());
    
    printf("*********Test for empty()*******\n");
    printf("String h1 (defined with defaut constructor):\n");
    printf("c_str: %s \n",h1.c_str());
    printf("Length: %zu \n", h1.length());
    printf("Capacity: %zu \n",h1.capacity());
    printf("Empty: %d\n\n",h1.empty());
    printf("String h2:\n");
    printf("c_str: %s \n",h2.c_str());
    printf("Length: %zu \n", h2.length());
    printf("Capacity: %zu \n",h2.capacity());
    printf("Empty: %d\n\n",h2.empty());
    
    printf("******Test for reserve()******\n");
    printf("String h2:\n");
    printf("Length: %zu \n", h2.length());
    printf("Capacity: %zu \n\n",h2.capacity());
    h2.reserve(4);
    printf("h2.reserve(4)\n");
    printf("Length: %zu \n", h2.length());
    printf("Capacity: %zu \n\n",h2.capacity());
    h2.reserve(40);
    printf("h2.reserve(40)\n");
    printf("Length: %zu \n", h2.length());
    printf("Capacity: %zu \n\n",h2.capacity());
    h2.reserve(140);
    printf("h2.reserve(140)\n");
    printf("Length: %zu \n", h2.length());
    printf("Capacity: %zu \n\n",h2.capacity());
	
	// operator + (String& , String&)
	printf("******Test for operator+(str, str)******\n");
	String h9(10,'9');
	String h10=h9+h3;
	printf("String h10 = String h9 + String h3\n");
	printf("c_str: %s \n",h10.c_str());
	printf("Length: %zu \n", h10.length());
    printf("Capacity: %zu \n\n",h10.capacity());
    printf("String h10 = String h3 + String h9\n");
	h10=h3+h9;
	printf("c_str: %s \n",h10.c_str());
	printf("Length: %zu \n", h10.length());
    printf("Capacity: %zu \n\n",h10.capacity());
    
    printf("******Test for operator+(str, char *)******\n");
    printf("String h11=h9+\"abcdefg\"\n");
    String h11=h9+"abcdefg";
	printf("c_str: %s \n",h11.c_str());
	printf("Length: %zu \n", h11.length());
    printf("Capacity: %zu \n\n",h11.capacity());
    printf("h11=h9+c1\n");
    h11=h9+c1;
    printf("c_str: %s \n",h11.c_str());
	printf("Length: %zu \n", h11.length());
    printf("Capacity: %zu \n\n",h11.capacity());

    printf("******Test for operator +(char*, str)******\n");
    printf("h11=c1+h9\n");
    h11=c1+h9;
    printf("c_str: %s \n",h11.c_str());
	printf("Length: %zu \n", h11.length());
    printf("Capacity: %zu \n\n",h11.capacity());
    printf("h11=c2+h9\n");
    h11=c2+h9;
    printf("c_str: %s \n",h11.c_str());
	printf("Length: %zu \n", h11.length());
    printf("Capacity: %zu \n\n",h11.capacity());
    
    printf("******Test for operator +(str, char)******\n");
    printf("h11=h9+'z'\n");
    h11=h9+'z';
    printf("c_str: %s \n",h11.c_str());
	printf("Length: %zu \n", h11.length());
    printf("Capacity: %zu \n\n",h11.capacity());
    printf("h13=h6+'z'\n");
    String h13=h6+'z';
    printf("c_str: %s \n",h13.c_str());
	printf("Length: %zu \n", h13.length());
    printf("Capacity: %zu \n\n",h13.capacity());
    printf("******Test for operator +(str, char)******\n");
    printf("h11='z'+h9\n");
    h11='z'+h9;
    printf("c_str: %s \n",h11.c_str());
	printf("Length: %zu \n", h11.length());
    printf("Capacity: %zu \n\n",h11.capacity());
	printf("h13='z'+h6\n");
    h13='z'+h6;
    printf("c_str: %s \n",h13.c_str());
	printf("Length: %zu \n", h13.length());
    printf("Capacity: %zu \n\n",h13.capacity());
    return 0;
}


