#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* data;
    int length;

public:
    
    String();
    String(const char* str);
    String(const String& other);
    ~String();
    String& operator=(const String& other);

    
    char& operator[](int index);
    const char& operator[](int index) const;
    int operator()(char c) const;
    operator int() const;

    
    String operator+(const String& other) const; 
    bool operator==(const String& other) const;  
    void append(const char* str);                
    void append(char c);                         

    
    void display() const;
};

#endif 
