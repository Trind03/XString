#include <cstdint>
#include "xstring.h"
#include <cstring>
#include <iostream>

#ifdef Debug
    #define checkpoint(message,obj,addr) std::cout << message << " - " << "Object: " << obj << " - address: " << addr << "\n\n";
#endif

 
string::string(const char* m_other)
{
    std::cout << "Default assignment" << std::endl;
    write_size(m_other);
    m_data = new char[m_size];
    m_data[m_size] = '\0';
    std::memcpy(m_data, m_other, length());
    std::cout << "Data size: " << m_size << std::endl;
}

string::string()
{
    write_size("");
    std::cout << "Default" << std::endl;
    m_data = new char[m_size];
    std::memcpy(m_data, "\0", length());
}

string::string(char*&& other)
{
    write_size(other);
    std::cout << "Default copy" << std::endl;

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
    return this->m_size;
}

/* This function expects raw metadata without null termination */
void string::write_size(const char* metadata)
{
    std::size_t data_size = 0;
    data_size = strlen(metadata);
    data_size += 1;
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