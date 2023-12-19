#include "string.h"
#include <iostream>

int main() {
    String myString = "Hello, World!";

    
    std::cout << "Character at index 7: " << myString[7] << std::endl;

    
    int index = myString('o');
    if (index != -1) {
        std::cout << "'o' found at index: " << index << std::endl;
    }
    else {
        std::cout << "'o' not found in the string." << std::endl;
    }

   
    int length = static_cast<int>(myString);
    std::cout << "Length of the string: " << length << std::endl;

    return 0;
}
