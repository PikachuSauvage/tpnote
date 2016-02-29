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
  
  
  
  
  
  
  
  
 public:
 
  

// =========================================================================
//                               Constructors
// =========================================================================
//constructeur par defaut
String();
//constructeur par repetition d'un caractere c, n fois
String(size_t n , char c);
  
// ===========================================================================
//                                 Destructor
// ===========================================================================
//destructor
~String();

// =========================================================================
//                              Public Methods
// =========================================================================
// whether the String is empty or not 
bool empty() const;

//adapt the String capacity_ to a length up to n characters
void reserve (size_t n = 0);
  // =========================================================================
  //                                  Getters
  // =========================================================================
// get capacity
inline size_t capacity() const;

  // =========================================================================
  //                                  Setters
  // =========================================================================
 
  // =========================================================================
  //                                 Operators
  // =========================================================================

// = operator with char* given
inline String& operator=(const char* other);
//friend String operator+(const String& A,const String& B);
};

// ===========================================================================
//                            Getters' definitions
// ===========================================================================
inline size_t String :: capacity() const{
  return capacity_;
}

// ===========================================================================
//                            Operators' definitions
// ===========================================================================
inline String& String :: operator=(const char* other){
  size_=1;
  capacity_=getCapacity(size_);
  data_=new char[capacity_+1];
  data_[0]=*other;
  data_[1]='\0';
  return *this;
}


#endif // STRING_H_
