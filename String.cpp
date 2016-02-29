

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

String::String(char* str_in){
	size_t len=0;
	while (str_in[len] != '\0'){
		if (len>= MAX_SIZE-1) //Reserver la place de \0
			break;
		len++;
	}
	size_=len;
	capacity_=getCapacity(len);
	data_=new char[capacity_+1];
	for (unsigned int i = 0; i < len; i++)
		data_[i]=str_in[i]; 
	//Doit-on definir toujour le dernier case comme \0
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


bool String :: empty() const{
  if (size_==0){
    return true;
  }
  else {
    return false;
    }
}

void String :: reserve (size_t n){ //default 0 ?
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

size_t String::length() const noexcept{
	return size_;
}

size_t String::max_size() const noexcept{
	return MAX_SIZE;
}
 
// =========================================================================
//                                  Setters
// =========================================================================



// ===========================================================================
//                              Public Methods
// ===========================================================================
size_t String::getCapacity(size_t size){
	size=size*2;
	if (size>MAX_SIZE)
		return MAX_SIZE;
	else
		return size;
}


void String::resize(size_t count){
	if (count > size_){
		if (count < capacity_) {
			for (size_t i=size_; i< count; i++)
				data_[i]=' ';
			data_[count]='\0';
			size_=count;
		} else {
			char* nptr= new char [count+1];
			for (unsigned int i =0; i<size_; i++){
				nptr[i]=data_[i];
			}
			for (size_t i=size_; i< count; i++)
				nptr[i]=' ';
			nptr[count]='\0';
			delete data_;
			data_=nptr;
			size_=count;
		}
	} else {
		data_[count]='\0';
		size_=count;
	} // Besoin de tester avec valgrind
}
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



