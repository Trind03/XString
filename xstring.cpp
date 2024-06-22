#include <cstdint>
#include "xstring.h"
#include <iostream>

string::string(const char* m_other)
{
    m_size = length(m_other);
    m_data = new char[m_size];
    std::memcpy(m_data, m_other, m_size);
}
string::~string()
{
    delete[] m_data;
}
int string::length(const char* m_other)
{
    
    int length = 0;
    while(m_other[length] != '\0') length++;
    return length;
}