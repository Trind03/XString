#include <cstdint>
#include "xstring.h"
#include <iostream>

string::string(const char* m_other)
{
    m_size = calculate_size(m_other);
    m_data = new char[m_size];
    std::memcpy(m_data, m_other, m_size);
}
string::string() 
{
    constexpr uint8_t size = 1;
    m_data = new char[m_size];
    std::memcpy(m_data, "", size);
}

string::string(char*&& ptr): m_data(ptr)
{

}
string::~string()
{
    //delete[] m_data;
    //m_data = nullptr;
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