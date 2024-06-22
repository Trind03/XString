#pragma once
#include <iostream>

class string
{
public:
    string(const char* m_other);
    ~string();
    int length(const char* m_other);
    char* m_data;
    int m_size;
    friend std::ostream& operator<<(std::ostream& stream, string& str) { stream << str.m_data; return stream; }
};
