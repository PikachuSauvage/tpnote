// =====================================================================
//                                  Includes
// =====================================================================
#ifndef STRING_H_
#define STRING_H_

#include <cstdlib>
#include <cstdio>

class String{
 protected:
 
    // length of the String, unsigned integral type
    size_t size_;

    // \0 ended tab of char representing the String
    char* data_;
    
    // size of the storage space currently allocated for the String
    size_t capacity_;
    
    // Max length a String can reach 
    static const size_t MAX_SIZE;
    
    // =================================================================
    //                              Protected Methods
    // =================================================================
    
    size_t getCapacity(size_t size); 
    static size_t length(const char* s);
    
 public:
    // =================================================================
    //                               Constructors
    // =================================================================
    
    String();
    String(size_t n , char c) ;
    String(char* str_in);
    String(const String& str);
    
    // =================================================================
    //                                 Destructor
    // =================================================================
    
    ~String();
    // =================================================================
    //                              Public Methods
    // =================================================================
    const char* c_str() const noexcept;
    void clear () noexcept;
    bool empty() const noexcept;
    void reserve (size_t n );
    void reserve ();
    void resize(size_t count);
    void resize(size_t count, char c);
    // =================================================================
    //                                  Getters
    // =================================================================
    size_t length() const noexcept;
    size_t max_size() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;
 
    // =================================================================
    //                                 Operators
    // =================================================================
    inline String& operator=(const char* other);
    inline String& operator=(const String elem);
    inline String& operator=(char c);
    char getChar(int pos)const;
    // operator + overloading  with string given
    friend String operator+(const String& s, const char c);
    friend String operator+(const String& A, const String& B);
    friend String operator+(const String& lhs, const char* rhs);
    
};

// =====================================================================
//                            Operators' inline definitions
// =====================================================================

/**
 * \brief operator= overloading
 * \details overloading with char* given
 * \param char*
 * \return *this
 */

inline String& String :: operator=(const char* other){
    size_=length(other);
    capacity_=getCapacity(size_);
    data_=new char[capacity_+1];
    data_[size_]='\0';
    return *this;
}
/**
 * \brief operator= overloading
 * \details overloading with char given
 * \param char
 * \return *this
 */
inline String& String :: operator=(char c){
    size_=1;
    capacity_=getCapacity(size_);
    data_=new char[capacity_+1]; 
    data_[0]=c;
    data_[size_]='\0';
    return *this;
}

/**
 * \brief operator= overloading
 * \details overloading with String given
 * \param String
 * \return *this
 */
inline String& String::operator=(const String elem){
    size_=elem.size();
    capacity_=getCapacity(size_);
    for(unsigned int i=0; i<size_;i++){
	data_[i]=elem.data_[i];
    }
    return *this;
}

#endif // STRING_H_
