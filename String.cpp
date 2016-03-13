// =====================================================================
//                                  Includes
// =====================================================================

#include "String.h"
// =====================================================================
//                               Definition of static attribute
// =====================================================================
const size_t String::MAX_SIZE = 100;
// =====================================================================
//                                Constructors
// =====================================================================

/**
 * \brief Defaut Constructor 
 * \details default
 * \param void
 * \return \e void
 */
String::String(){
    size_=0;
    capacity_=getCapacity(0);
    data_=new char[capacity_+1];
    data_[size_]='\0';
}
/**
 * \brief Fill Constructor 
 * \details repetition of a single character
 * \param size_t n as length of the String
 * \param char c as repeted character
 * \return \e void
 */
String::String(size_t n , char c){
	if (n>MAX_SIZE) {
		printf("Warning: input size exceed the MAX_SIZE,"
		"it will be shorted to MAX_SIZE which is %lu \n",MAX_SIZE);
		n=MAX_SIZE;
	}
    size_=n;
    capacity_=getCapacity(n);
    data_=new char[capacity_+1];
    for (unsigned int i =0; i<n; i++){
		data_[i]=c;
    }
    data_[n]='\0';
}

/**
 * \brief Copy Constructor 
 * \details 
 * \param const String& s as copied String
 * \return \e void
 */
String::String (const String& str){ 
	size_=str.size();
	capacity_=getCapacity(size_);
	data_= new char[capacity_+1]; // dpa OK
	for(unsigned int i=0; i<size_;i++)
	    data_[i]=str.getChar(i);
	data_[size_]='\0';
}

/**
 * \brief Constructor from c-string
 * \details from a null-terminated c-string
 * \param char* str_in 
 * \return \e void
 */
String::String(char* str_in){
	size_=length(str_in);
    capacity_=getCapacity(size_);
    data_=new char[capacity_+1];
    for (unsigned int i = 0; i < size_; i++)
		data_[i]=str_in[i];
	data_[size_]='\0';
}


// =====================================================================
//                                 Destructor
// =====================================================================

/**
 * \brief Destructor
 * \details 
 * \param void
 * \return \e void
 */

String::~String()
{
    //printf("Welcome to destructors\n");
    delete[] data_;
    data_=nullptr;
}
// =====================================================================
//                               Protected Methods
// =====================================================================

/**
 * \brief getCapacity
 * \details calculate capacity from a given string size
 * \param size_t size
 * \return size_t size
 */

size_t String::getCapacity(size_t size){
    size=size*2;
    if (size>(MAX_SIZE/2))
      return MAX_SIZE;
    else
      return size;
}

/**
 * \brief length
 * \details get the length of a null-terminated chain
 * \param const char* s
 * \return size_t len
 */

size_t String::length(const char* s){
    size_t len=0;
    while (s[len] != '\0'){
		if (len>= MAX_SIZE-1){
			printf("Warning : c_str input is too long and will be"
			"shorted to MAX_SIZE which is %lu\n", MAX_SIZE);
			break;
		}
		len++;
    }
    return len;
}

// =====================================================================
//                               Public Methods
// =====================================================================

/**
 * \brief c_str
 * \details return a pointer to an array that contains a null terminated
 * sequence of character (a c-string) representing the current value of
 * the String object 
 * \param void
 * \return char* data_
 */
const char* String::c_str() const noexcept{
    return data_;
}

/**
 * \brief clear
 * \details erase the content of the String wich become an empty String
 * with a length of 0 characters
 * \param void
 * \return void
 */
void String::clear(){
	data_[0]='\0';
    size_=0;
}

/**
 * \brief empty
 * \details whether the String is empty or not, true if the String 
 * length is 0, false otherwise
 * \param void
 * \return bool 
 */
bool String :: empty() const noexcept{
    if (size_==0){
	return true;
    }
    else {
	return false;
    }
}

/**
 * \brief reserve
 * \details adapt the String capacity_ to a length up to n characters
 * If n is greater than the current string size while smaller than 
 * MAX_SIZE, the capacity is set to n
 * If its smaller than size then the capacity is set to size
 * \param size_t n
 * \return void
 */
void String :: reserve (size_t n){ 
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
	    delete[] data_;
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
	delete[] data_;
	data_=new_data;
	capacity_=size_;
    }
}
/**
 * \brief reserve overload
 * \details set the capacity to size
 * \param void
 * \return void
 */
void String :: reserve (){
    char* new_data;
    new_data = new char[size_];
    for (unsigned int i =0; i<size_; i++){
	new_data[i]=data_[i];
    }
    delete[] data_;
    data_=new_data;
    capacity_=size_;
}

/**
 * \brief resize
 * \details resize a String to length of count character, complete with
 * 			space if needed
 * \param size_t count
 * \return void
 */
 
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
	    delete[] data_;
	    data_=nptr;
	    size_=count;
	}
    } else {
	data_[count]='\0';
	size_=count;
    }
}
/**
 * \brief resize
 * \details resize a String to length of count character, complete with 
 * 			character c if needed
 * \param size_t count, char c
 * \return void
 */
 
void String::resize(size_t count, char c){
    if (count > size_){
		if (count < capacity_) {
			for (size_t i=size_; i< count; i++)
				data_[i]=c;
			data_[count]='\0';
			size_=count;
		} else {
			char* nptr= new char [count+1];
			for (unsigned int i =0; i<size_; i++)
				nptr[i]=data_[i];
			for (size_t i=size_; i< count; i++)
				nptr[i]=c;
			nptr[count]='\0';
			delete[] data_;
			data_=nptr;
			size_=count;
		}
    } else {
		data_[count]='\0';
		size_=count;
    }
}



// =====================================================================
//                                  Getters
// =====================================================================


/**
 * \brief length
 * \details get the length of a String
 * \param void
 * \return size_t 
 */

size_t String::length() const noexcept{
    return size_;
}

/**
 * \brief length
 * \details get the maximum length the String can reach
 * \param void
 * \return size_t 
 */

size_t String::max_size() const noexcept{
    return MAX_SIZE;
}

/**
 * \brief size
 * \details get the length of a String
 * \param void
 * \return size_t 
 */

size_t String::size()const noexcept {
    return size_;
}


/**
 * \brief capacity
 * \details get the size of the storage space currently allocated for 
 * the String
 * \param void
 * \return size_t 
 */

size_t String::capacity() const{
    return capacity_;
}

 
// =====================================================================
//                            Operators' definitions
// =====================================================================

/**
 * \brief operator+ overloading
 * \details returns a newly constructed String object with its value 
 * being the concatenation of the characters in a String A followed by 
 * those of String B
 * \param String&A
 * \param String&B
 * \return String
 */

String operator+(const String& A,const String& B){
    String result;
    if (A.size_+B.size_>String :: MAX_SIZE){ //why String::MAX_SIZE
	printf("too long, only first string added");
	result.size_=A.size_;
	result.capacity_=A.capacity_;
	delete[] result.data_;
	result.data_=new char [result.capacity_+1];
	for (unsigned int i=0; i<result.size_; i++){
	    result.data_[i]=A.data_[i];
	}
	return result;
    }
    else {
	result.size_=A.size_+B.size_;
	result.capacity_=A.capacity_+B.capacity_;
	delete[] result.data_;
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
}

/**
 * \brief operator+ overloading
 * \details returns a newly constructed String object with its value 
 * being the concatenation of the characters in a String lhs followed by 
 * those of c_string rhs
 * \param String& lhs
 * \param char* rhs
 * \return String
 */

String operator+(const String& lhs, const char* rhs){
	String result;
	int rhs_length = result.length(rhs); //In case that string is super long 
	if (lhs.length()+rhs_length > String::MAX_SIZE ) {
		printf("Warning: strings concatenation size out of range");
		result.size_=lhs.size_;
		result.capacity_=lhs.capacity_;
		result.data_= new char[result.capacity_ + 1];
		for (unsigned int i=0; i < result.size_; i++)
			result.data_[i]=lhs.data_[i];
		return result;
	} else {
		result.size_=lhs.length()+rhs_length;
		result.capacity_=result.getCapacity(result.size_);
		result.data_= new char[result.capacity_ + 1];
		for (unsigned int i=0; i < lhs.length(); i++)
			result.data_[i]=lhs.data_[i];
		for (int i=0; i < rhs_length; i++)
			result.data_[i+lhs.length()]=rhs[i];
		// Here, we need to make a choice bewteen lhs.length() and 
		// lhs.size_
		// lhs.length() is a legal public method which not requires 
		// make friend of 2 objects
		// On the other hand, it will be called at each turn in the for 
		// loop, which could be a lot if string is long.
		return result;
	}
}

/**
 * \brief operator+ overloading
 * \details returns a newly constructed String object with its value 
 * being the concatenation of the characters in a String s followed by 
 * c character
 * \param String&s
 * \param char c
 * \return String
 */

String operator+(const String& s, const char c){
    if(s.size()==String::MAX_SIZE){
	printf("Depasse capacite");
	return s;
    }else{
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
}


/**
 * \brief operator[] overload
 * \details returns a reference to the character at position pos in the 
 * String
 * \param int pos
 * \return char&
 */

char String::getChar(int pos)const{
    return data_[pos];
}
