// ===========================================================================
//                                  Includes
// ===========================================================================



#ifndef STRING_H_
#define STRING_H_

#include <cstdlib>


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
String(size_t n , char c) ;
//constructeur par copie 
String( const String& s );

  
// ===========================================================================
//                                 Destructor
// ===========================================================================


// =========================================================================
//                              Public Methods
// =========================================================================
const char* c_str() const;
void clear();
String& operator=(const String elem);

  // =========================================================================
  //                                  Getters
  // =========================================================================
size_t size() const;
char getChar(int i)const;

  // =========================================================================
  //                                  Setters
  // =========================================================================
 
 
 

friend String operator+(const String& s, const char c);


};



#endif // STRING_H_
