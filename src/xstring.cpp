#include <cstdint>
#include "xstring.h"
#include <cstring>
#include <iostream>

#ifdef Debug
    #define checkpoint(message,obj,addr) std::cout << message << " - " << "Object: " << obj << " - address: " << addr << "\n\n";
#endif

 
string::string(const char* m_other): m_size(calculate_size(m_other))
{
    m_data = new char[m_size];
    m_data[m_size] = '\0';
    std::memcpy(m_data, m_other, m_size);
}
   
string::string() : m_size(2)
{
    m_data = new char[m_size];
    std::memcpy(m_data, "\0", m_size);
}

string::string(char*&& other): m_size(calculate_size(other))
{
    delete[] m_data;
    m_data = nullptr;

    m_data = new char[calculate_size(other)];
    std::memcpy(m_data,other,m_size);
    other = nullptr;
}

string::~string() 
{
    delete[] this->m_data;
    m_data = nullptr;
}

std::size_t string::length()
{
    return m_size;
}
std::size_t string::calculate_size(const char* m_other)
{
    int length = 0;
    while(m_other[length] != '\0') length++;
    length++;
    m_size = length;
    return length;
}

int string::to_upper()
{
    /*
    if(this->m_data == nullptr || this->length() == 0) return EXIT_FAILURE;

    for(int i = 0; i < this->length(); i++)
    {
        uint16_t Char = (uint16_t)m_data[i];
        if(Char >= 97 && Char <= 122)
        {
            Char - 32;
            m_data[i] = (char)Char;
        }
        continue;
    }*/
    return EXIT_SUCCESS;
}