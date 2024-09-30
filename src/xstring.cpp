#include <cstdint>
#include "xstring.h"
#include <cstring>
#include <iostream>

#ifdef Debug
    #define checkpoint(message) std::cout << message << std::endl;
#endif

 
string::string(const char* m_other)
{
    this->m_size = strlen(m_other);
    checkpoint("Default assignment")
    write_size(m_other);
    m_data = new char[m_size];
    m_data[m_size] = '\0';
    std::memcpy(m_data, m_other, length());
    std::cout << "Data size: " << m_size << std::endl;
}

string::string()
{
    write_size("");
    checkpoint("Default")
    m_data = new char[m_size];
    std::memcpy(m_data, "\0", length());
}

string::string(char*&& other)
{
    write_size(other);
    checkpoint("Default copy")

    delete[] m_data;
    m_data = nullptr;

    m_data = new char[m_size];
    m_data[m_size] = '\0';
    std::memcpy(m_data,other ,length());
    other = nullptr;
}

string::~string() 
{
    delete[] this->m_data;
    m_data = nullptr;
}

std::size_t string::length()
{
    std::size_t len = this->m_size;
    return len;
}

/* This function expects raw metadata without null termination */
void string::write_size(const char* metadata)
{
    std::size_t data_size = 0;
    data_size = strlen(metadata);
    ++data_size;
    this->m_size = data_size;
    return;
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