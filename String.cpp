

// ===========================================================================
//                                  Includes
// ===========================================================================

#include "String.h"
// =========================================================================
//                               Definition of static attribute
// =========================================================================
const size_t String ::MAX_SIZE = 100;




// ===========================================================================
//                                Constructors
// ===========================================================================

//Constructeur par defaut
String::String(){
	size_=0;
	capacity_=getCapacity(0);
	data_=nullptr;
}

//constructeur par valeur
String::String(size_t n , char c){
	size_=n;
	capacity_=getCapacity(n);
	data_=new char[capacity_+1];
  for (unsigned int i =0; i<n; i++){
    data_[i]=c;
  }
  data_[n]='\0';
}

//methode de construction par copie
String::String( const String& s ){
  if(s.size()<MAX_SIZE){  
    size_=s.size();
    capacity_=getCapacity(size_);
    data_= new char[capacity_+1]; // dpa OK
    for(unsigned int i=0; i<size_;i++){
      data_[i]=s.getChar(i);
    }
    data_[size_+1]='\0';
  }
}

// ===========================================================================
//                                 Destructor
// ===========================================================================



// ===========================================================================
//                               Public Methods
// ===========================================================================
size_t String::getCapacity(size_t size){
	return size*2;
}
const char* String::c_str() const{
  return data_;
}

void String::clear(){
  data_[0]='\0';
  size_=0;
}

String& String::operator=(const String elem){
  size_=elem.size();
  capacity_=getCapacity(size_);
  for(unsigned int i=0; i<size_;i++){
    data_[i]=elem.data_[i];
  }
  return *this;
}


//operateur +(char) prend en parametre un char c et l'ajoute à la chaine s
//prise en parametre
String operator+(const String& s, const char c){
  String Snew;
  Snew.size_=s.size_+1;
  Snew.capacity_=Snew.getCapacity(Snew.size_);
  Snew.data_=new char[Snew.capacity_+1];
  for(unsigned int i=0; i<s.size_;i++){
    Snew.data_[i]=s.data_[i];
  }
  Snew.data_[s.size_]=c;
  Snew.data_[s.size_+1]='\0';
  return Snew;  
} 

// =========================================================================
//                                  Getters
// =========================================================================

size_t String::size()const {
  return size_;
}


char String::getChar(int i)const{
  return data_[i];
}



 
// =========================================================================
//                                  Setters
// =========================================================================



// ===========================================================================
//                              Public Methods
// ===========================================================================


