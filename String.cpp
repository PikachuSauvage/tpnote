

// ===========================================================================
//                                  Includes
// ===========================================================================

#include "String.h"
#include <cstdlib>
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
//                               Public Methods
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
			data_=(char *)realloc(data_, count+1);
			for (size_t i=size_; i< count; i++)
				data_[i]=' ';
			data_[count]='\0';
			size_=count;
		}		
	} else {
		data_[count]='\0';
		size_=count;
	} // Besoin de tester avec valgrind
}



