#include "../xstring.h"
#include <iostream>

int main()
{
    string mystring = "Hello World!";
    if(mystring == "Hello World!")
        std::cout <<"its hello world!";
    else
        std::cout << "its not hello world" << std::endl;
    std::cout << mystring;
    return EXIT_SUCCESS;
}