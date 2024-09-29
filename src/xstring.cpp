#include <cstdint>
#include "xstring.h"
#include <cstring>
#include <iostream>

#ifdef Debug
    #define checkpoint(message,obj,addr) std::cout << message << " - " << "Object: " << obj << " - address: " << addr << "\n\n";
#endif

 
string::string(const char* m_other)
{
    m_data = new char[length()];
    m_data[length()] = '\0';
    std::memcpy(m_data, m_other, length());
}

string::string()
{
    m_data = new char[length()];
    std::memcpy(m_data, "\0", length());
}

string::string(char*&& other)
{
    delete[] m_data;
    m_data = nullptr;

    m_data = new char[length(other)];
    std::memcpy(m_data,other,length());
    other = nullptr;
}

string::~string() 
{
    delete[] this->m_data;
    m_data = nullptr;
}

std::size_t string::length()
{
    return this->m_size;
}

std::size_t string::length(const char* charptr)
{
    std::size_t length = 0;

    if(charptr == nullptr)
        return EXIT_FAILURE;

    while(*charptr != '\0')
    {
        length++;
        charptr++;
    }
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