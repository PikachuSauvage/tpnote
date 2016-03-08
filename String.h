// ===========================================================================
//                                  Includes
// ===========================================================================
#ifndef STRING_H_
#define STRING_H_

#include <cstdlib>
#include <cstdio>

class String{
 protected:
 
  size_t size_;
  char* data_;
  size_t capacity_;
  static const size_t MAX_SIZE;

// =========================================================================
//                              Protected Methods
// ========================================================================= 
  // methode qui retourne la capcite en fonction de la taille de la chaine
	size_t getCapacity(size_t size); 
	static size_t length(const char* s);
 public:
// =========================================================================
//                               Constructors
// =========================================================================
//constructeur par defaut
String();
//constructeur par repetition d'un caractere c, n fois
String(size_t n , char c) ;
String(char* str_in);
//constructeur par copie 
String( const String& s );
size_t length() const noexcept;
size_t max_size() const noexcept;
void resize(size_t count);
  
// ===========================================================================
//                                 Destructor
// ===========================================================================
//destructor
~String();
// =========================================================================
//                              Public Methods
// =========================================================================
const char* c_str() const;
void clear();

// whether the String is empty or not 
bool empty() const;
//adapt the String capacity_ to a length up to n characters
void reserve (size_t n );
void reserve ();
  // =========================================================================
  //                                  Getters
  // =========================================================================
size_t size() const;
char getChar(int i)const;
// get capacity
inline size_t capacity() const;

  // =========================================================================
  //                                  Setters
  // =========================================================================
 
  // =========================================================================
  //                                 Operators
  // =========================================================================
friend String operator+(const String& s, const char c);
// operator = overloading with char* given
inline String& operator=(const char* other);
String& operator=(const String elem);
String& operator=(char c);
// operator + overloading  with string given
friend String operator+(const String& A,const String& B);
};

// ===========================================================================
//                             Getters' inline definitions
// ===========================================================================
inline size_t String::capacity() const{
  return capacity_;
}

// ===========================================================================
//                            Operators' inline definitions
// ===========================================================================
//inline String& String :: operator=(const char* other){
  //size_=1;
  //capacity_=getCapacity(size_);
  //data_=new char[capacity_+1];
  //data_[0]=*other;
  //data_[1]='\0';
  //return *this;
//}

inline String& String :: operator=(const char* other){
	size_=length(other);
	capacity_=getCapacity(size_);
	data_=new char[capacity_+1];
	data_[size_]='\0';
	return *this;
}

inline String& String :: operator=(char c){
	size_=1;
	capacity_=getCapacity(size_);
	data_=new char[capacity_+1]; 
	data_[0]=c;
	data_[size_]='\0';
	return *this;
}

#endif // STRING_H_
