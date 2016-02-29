

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

String::String(){
	size_=0;
	capacity_=getCapacity(0);
	data_=nullptr;
}


String::String(size_t n , char c){
	size_=n; 
	capacity_=getCapacity(n);
	data_=new char[capacity_+1];
  for (unsigned int i =0; i<n; i++){
    data_[i]=c;
  }
  data_[n]='\0';
}



// ===========================================================================
//                                 Destructor
// ===========================================================================
String::~String(){
  delete data_;
  data_=nullptr;
}
// ===========================================================================
//                               Public Methods
// ===========================================================================
size_t String::getCapacity(size_t size){
	return size*2;
}

bool String :: empty() const{
  if (size_==0){
    return true;
  }
  else {
    return false;
    }
}

void String :: reserve (size_t n ){ //default 0 ?
  
  if (n>size_){
    if (n>MAX_SIZE){
      printf("can't allow required capacity");
    }
    else {
      char* new_data;
      new_data = new char[n+1];
      for (unsigned int i =0; i<=size_; i++){
        new_data[i]=data_[i];
      }
      delete data_;
      data_=new_data;
      capacity_=n;
    }
  
  }
  else {
      char* new_data;
      new_data = new char[size_];
      for (unsigned int i =0; i<size_; i++){
        new_data[i]=data_[i];
      }
      delete data_;
      data_=new_data;
      capacity_=size_;
      
  }

}
// =========================================================================
//                                  Getters
// =========================================================================



 
// =========================================================================
//                                  Setters
// =========================================================================



// ===========================================================================
//                              Public Methods
// ===========================================================================

// ===========================================================================
//                            Operators' definitions
// ===========================================================================
String operator+(const String& A,const String& B){
  String result;
  result.size_=A.size_+B.size_;
  result.capacity_=A.capacity_+B.capacity_;
  result.data_=new char [result.capacity_+1];
  for (unsigned int i=0; i<result.size_; i++){
    if (i<A.size_){
      result.data_[i]=A.data_[i];
    }
    else {
      result.data_[i]=B.data_[i-A.size_];
    }
  }
  return result;
}

