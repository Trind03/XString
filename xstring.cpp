#include <cstdint>
#include "string.h"

string::string(const char* m_other): m_data(new char[length(m_other) + 1])
{

}

string::~string()
{
    delete[] m_data;
    m_data = nullptr;
}

uint32_t length(const char*& m_data)
{
    uint32_t length = 0;
    while(m_data[length] != '\0')   length++;
    return length;
}
