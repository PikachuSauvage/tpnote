#include "String.h"

int String::getCapacity(int n){
	return n*2;
}


String::String(){
	size_=0;
	capacity_=getCapacity(0);
	data_=nullptr;
}


