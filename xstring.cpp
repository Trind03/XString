#include <cstdint>
#include "xstring.h"
#include <iostream>

string::string(const char* m_other): m_data_mem(true)
{
    m_size = calculate_size(m_other);
    m_data = new char[m_size + 1];
    m_data[m_size] = '\0';
    std::memcpy(m_data, m_other, m_size);
}

string::string(): m_data_mem(true)
{
    constexpr uint8_t size = 2;
    m_data = new char[m_size];
    std::memcpy(m_data, " \0", size);
}

string::string(char*&& m_other): m_data(std::move(m_other)), m_data_mem(true)
{
    m_other = nullptr;
}

string::~string()
{
    if(m_data_mem)
    {
        delete[] m_data;
        m_data_mem = false;
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
