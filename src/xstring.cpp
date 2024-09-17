#include <cstdint>
#include "xstring.h"
#include <cstring>
#include <iostream>

#ifdef Debug
    #define checkpoint(message,obj,addr) std::cout << message << " - " << "Object: " << obj << " - address: " << addr << "\n\n";
#endif

 
string::string(const char* m_other): live_data(true), m_size(calculate_size(m_other))
{
    checkpoint("Assignment constructor",this,&this->m_data)
    m_data = new char[m_size + 1];
    m_data[m_size] = '\0';
    std::memcpy(m_data, m_other, m_size);
}
   
string::string() : live_data(true), m_size(2)
{
    checkpoint("Default constructor",this,&this->m_data)
    m_data = new char[m_size];
    std::memcpy(m_data, " \0", m_size);
}

string::string(char*&& other): m_data(std::move(other)), live_data(true)
{
    checkpoint("Move assignment constructor",this,&this->m_data)
    other = nullptr;
}

string::~string() 
{
    checkpoint("default deconstructor",this,&this->m_data)
    std::cout << this << std::endl;

    delete[] this->m_data;
    m_data = nullptr;
}

int string::length()
{
    return m_size;
}
int string::calculate_size(const char* m_other)
{
    int length = 0;
    while(m_other[length] != '\0') length++;
    return length;
}

int string::to_upper()
{
    if(this->m_data == nullptr || this->length() == 0) return EXIT_FAILURE;

    for(int i = 0; i < this->length(); i++)
    {

    }
    return EXIT_SUCCESS;
}