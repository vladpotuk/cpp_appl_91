#include "string.h"
#include <cstring>

String::String() : data(nullptr), length(0) {}

String::String(const char* str) : length(static_cast<int>(strlen(str))) {
    data = new char[length + 1];
    strcpy_s(data, length + 1, str);
}

String::String(const String& other) : length(other.length) {
    data = new char[length + 1];
    strcpy_s(data, length + 1, other.data);
}

String::~String() {
    delete[] data;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        strcpy_s(data, length + 1, other.data);
    }
    return *this;
}

char& String::operator[](int index) {
    return data[index];
}

const char& String::operator[](int index) const {
    return data[index];
}

int String::operator()(char c) const {
    for (int i = 0; i < length; ++i) {
        if (data[i] == c) {
            return i;
        }
    }
    return -1;
}

String::operator int() const {
    return length;
}

String String::operator+(const String& other) const {
    String result;
    result.length = length + other.length;
    result.data = new char[result.length + 1];
    strcpy_s(result.data, length + 1, data);
    strcat_s(result.data, result.length + 1, other.data);
    return result;
}

bool String::operator==(const String& other) const {
    return (length == other.length) && (strcmp(data, other.data) == 0);
}

void String::append(const char* str) {
    int newLength = length + static_cast<int>(strlen(str));
    char* newData = new char[newLength + 1];
    strcpy_s(newData, length + 1, data);
    strcat_s(newData, newLength + 1, str);
    delete[] data;
    data = newData;
    length = newLength;
}

void String::append(char c) {
    char* newData = new char[length + 2];
    strcpy_s(newData, length + 1, data);
    newData[length] = c;
    newData[length + 1] = '\0';
    delete[] data;
    data = newData;
    length++;
}

void String::display() const {
    std::cout << data << std::endl;
}

