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
    String( const String& s );
    
    // =================================================================
    //                                 Destructor
    // =================================================================
    
    ~String();
    // =================================================================
    //                              Public Methods
    // =================================================================
    const char* c_str() const noexcept;
    void clear ();
    bool empty() const noexcept;
    void reserve (size_t n );
    void reserve ();
    void resize(size_t count);
    // =========================================================================
    //                                  Getters
    // =========================================================================
    size_t size() const;
    char getChar(int i)const;
    // get capacity, method for users
    inline size_t capacity() const;
    size_t length() const noexcept;
    size_t max_size() const noexcept;

    // =========================================================================
    //                                  Setters
    // =========================================================================
 
    // =========================================================================
    //                                 Operators
    // =========================================================================
    // operator = overloading with char* given
    inline String& operator=(const char* other);
    inline String& operator=(const String elem);
    inline String& operator=(char c);
    // operator + overloading  with string given
    friend String operator+(const String& s, const char c);
    friend String operator+(const String& A, const String& B);
    friend String operator+(const String& lhs, const char* rhs);
};

// ===========================================================================
//                             Getters' inline definitions
// ===========================================================================
inline size_t String::capacity() const{
    return capacity_;
}

// ===========================================================================
//                            Operators' inline definitions
// ===========================================================================

inline String& String :: operator=(const char* other){
    size_=length(other);
    capacity_=getCapacity(size_);
    data_=new char[capacity_+1];
    data_[size_]='\0';
    return *this;
}
//
inline String& String :: operator=(char c){
    size_=1;
    capacity_=getCapacity(size_);
    data_=new char[capacity_+1]; 
    data_[0]=c;
    data_[size_]='\0';
    return *this;
}

inline String& String::operator=(const String elem){
    size_=elem.size();
    capacity_=getCapacity(size_);
    for(unsigned int i=0; i<size_;i++){
	data_[i]=elem.data_[i];
    }
    return *this;
}

#endif // STRING_H_
