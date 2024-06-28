#include <iostream>
#include "../xstring.h"

int main()
{
    string hello = "Hello ";
    string world = "World";
    string hello_world = hello + world;
    std::cout << hello_world << std::endl; 
}