#include <iostream>
#include "../xstring.h"

int main()
{
    string hello = "Hello ";
    string World = "World ";
    string Hello_World = hello + World;
   std::cout << Hello_World << std::endl; 
}