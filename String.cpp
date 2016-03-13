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
	       "it will be shortened to MAX_SIZE which is %lu \n"
	       ,MAX_SIZE);
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
    data_= new char[capacity_+1];
    for(unsigned int i=0; i<size_;i++)
	data_[i]=str[i];
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
	if (len>= MAX_SIZE){
	    printf("Warning : c_str input is too long and will be"
		   "shortened to MAX_SIZE which is %lu\n", MAX_SIZE);
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
void String::clear() noexcept{
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
    if (n>size_){// do nothing if not
	if (n>MAX_SIZE){
	    printf("Warning(reserve): can't allow required capacity\n");
	    //When requied size exceed, refuse and do nothing
	} else {
	    //realloc
	    char* new_data = new char[n+1];
	    for (unsigned int i =0; i<=size_; i++)
		new_data[i]=data_[i];
	    delete[] data_;
	    data_=new_data;
	    capacity_=n;
	}
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
    if (count > MAX_SIZE){
	printf("Warning (String::resize): requied size exceed MAX_SIZE "
	       "and it will be shortened to MAX_SIZE which is %zu\n",
	       MAX_SIZE);
	count=MAX_SIZE;
    }
    if (count > size_){
	if (count < capacity_) {
	    for (size_t i=size_; i<count; i++)
		data_[i]=' ';
	    data_[count]='\0';
	    size_=count;
	} else {
	    char* nptr= new char [getCapacity(count)+1];
	    for (unsigned int i =0; i<size_; i++)
		nptr[i]=data_[i];
	    for (size_t i=size_; i<count; i++)
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
    if (count > MAX_SIZE){
	printf("Warning (String::resize): requied size exceed MAX_SIZE "
	       "and it will be shortened to MAX_SIZE which is %zu\n",
	       MAX_SIZE);
	count=MAX_SIZE;
    }
    if (count > size_){
	if (count < capacity_) {
	    for (unsigned int i=size_; i< count; i++)
		data_[i]=c;
	    data_[count]='\0';
	    size_=count;
	} else {
	    char* nptr=new char [count+1];
	    for (unsigned int i=0; i<size_; i++)
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

size_t String::capacity() const noexcept{
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

String operator+(const String& lhs,const String& rhs){
    String result;
    if (lhs.size_+rhs.size_>String :: MAX_SIZE){ //why String::MAX_SIZE
	printf("Warning (operator+()):too long, "
	       "taking only left hand side");
	result.size_=lhs.size_;
	result.capacity_=lhs.capacity_;
	delete[] result.data_;
	result.data_=new char [result.capacity_+1];
	for (unsigned int i=0; i<result.size_; i++)
	    result.data_[i]=lhs.data_[i];
    } else {
	result.size_=lhs.size_+rhs.size_;
	result.capacity_=result.getCapacity(result.size_);
	delete[] result.data_;
	result.data_=new char [result.capacity_+1];
	for (unsigned int i=0; i<lhs.size(); i++)
	    result.data_[i]=lhs.data_[i];
	for (unsigned int i=lhs.size(); i<=result.size(); i++)
	    result.data_[i]=rhs.data_[i-lhs.size_];
	//result.data_[result.size_]='\0';
    }
    return result;
}


/**
 * \brief operator+ overloading
 * \details returns a newly constructed String object with its value 
 * being the concatenation of the characters in a String lhs followed  
 * by those of c_string rhs
 * \param String& lhs
 * \param char* rhs
 * \return String
 */

String operator+(const String& lhs, const char* rhs){
    String result;
    int rhs_length = result.length(rhs); 
    //In case that string is super long 
    if (lhs.length()+rhs_length > String::MAX_SIZE ) {
	printf("Warning (operator+): strings concatenation size "
	       "out of range, taking only left hand side\n");
	result=lhs;
	return result;
    } else {
	result.size_=lhs.length()+rhs_length;
	result.capacity_=result.getCapacity(result.size_);
	result.data_= new char[result.capacity_ + 1];
	for (unsigned int i=0; i < lhs.length(); i++)
	    result.data_[i]=lhs.data_[i];
	for (int i=0; i < rhs_length; i++)
	    result.data_[i+lhs.length()]=rhs[i];
	result.data_[result.size_]='\0';
	// Need to give '\0' manually in case str.len()=0 and c_str=100
	// and not null-terminated
		
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
 * being the concatenation of the characters in a String lhs followed 
 * by those of c_string rhs
 * \param String& lhs
 * \param char* rhs
 * \return String
 */

String operator+(const char* lhs, const String& rhs){
    String result;
    int lhs_length = result.length(lhs); 
    //In case that string is super long 
    if (lhs_length+rhs.length() > String::MAX_SIZE ) {
	printf("Warning(operator+): strings concatenation size out "
	       "of range, taking only left hand side\n");
	result=lhs;
	return result;
    } else {
	result.size_=rhs.length()+lhs_length;
	result.capacity_=result.getCapacity(result.size_);
	result.data_= new char[result.capacity_ + 1];
	for (unsigned int i=0; i < lhs_length; i++)
	    result.data_[i]=lhs[i];
	for (int i=0; i <= rhs.length(); i++)
	    result.data_[i+lhs_length]=rhs.data_[i];
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
    String result;
    if(s.size()==String::MAX_SIZE){
	printf("Warning(operator +): "
	       "MAX_SIZE achived, failed add one more char\n");
	result=s;
	return result;
    }else{
	result.size_=s.size_+1;
	result.capacity_=result.getCapacity(result.size_);
	result.data_=new char[result.capacity_+1];
	for(unsigned int i=0; i<s.size_;i++)
	    result.data_[i]=s.data_[i];
	result.data_[s.size_]=c;
	result.data_[s.size_+1]='\0';
	return result;
    }
}

String operator+(const char c, const String& s){
    String result;
    if(s.size()==String::MAX_SIZE){
	printf("Warning(operator +): "
	       "failed to add a max-sized string\n");
	result=c;
	return result;
    }else{
	result.size_=s.size_+1;
	result.capacity_=result.getCapacity(result.size_);
	result.data_=new char[result.capacity_+1];
	result.data_[0]=c;
	for(unsigned int i=1; i<=s.size_;i++)
	    result.data_[i]=s.data_[i];
	result.data_[s.size_+1]='\0';
	return result;
    }
}
/**
 * \brief operator[] overload
 * \details returns a reference to the character at position pos in the 
 * String
 * \param int pos
 * \return char&
 */
char& String::operator[] (size_t pos){
    if (pos<=MAX_SIZE)
	return data_[pos];
    else{
	printf("Warning(operator[]): "
	       "Requied position out of range, returning last char\n");
	return data_[MAX_SIZE];//Haven't found a better solution;
    }
}

const char& String::operator[] (size_t pos) const{
    if (pos<=MAX_SIZE)
	return data_[pos];
    else{
	printf("Warning(operator[]): "
	       "Requied position out of range, returning last char\n");
	return data_[MAX_SIZE];//Haven't found a better solution;
    }
}
