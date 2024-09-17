#include <cstdint>
#include "xstring.h"
#include <cstring>
#include <iostream>

#ifdef Debug
    #define checkpoint(message) std::cout << message << std::endl;
#endif

 
string::string(const char* m_other): live_data(true), m_size(calculate_size(m_other))
{
    m_data = new char[m_size + 1];
    m_data[m_size] = '\0';
    std::memcpy(m_data, m_other, m_size);
}
   
string::string() : live_data(true), m_size(2)
{
    m_data = new char[m_size];
    std::memcpy(m_data, " \0", m_size);
}

string::string(char*&& m_other): m_data(std::move(m_other)), live_data(true)
{
    m_other = nullptr;
}

string::~string() 
{
    if(live_data)
    {
        delete[] this->m_data;
    }
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
    if(m_data == nullptr || length() == 0) return EXIT_FAILURE;

    for(int i = 0; i < length(); i++)
    {

    }
    return EXIT_SUCCESS;
}