#include <iostream>

/**
 * Anonymouse namespace - only accesed in this this file
 */
namespace{ 
    void consoleText(){
        std::cout << "Some text" << std::endl;
    }
}

/**
 * Nested namespaces 
 */
int x = 10;
namespace first {
    int x = 1;
    namespace second {
        int xInFirstNamespaces = x; //one upper
        int xInOutsideNamespaces = ::x; // outside namespaces
    }
}

int main(){
    consoleText(); 

    std::cout << "X from first namespaces " << first::second::xInFirstNamespaces << std::endl;
    std::cout << "X from outside namespaces " << first::second::xInOutsideNamespaces << std::endl;

    return 0;
}