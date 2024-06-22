#pragma once
#include <iostream>

class string
{
public:
    string(const char* m_other);
    ~string();
    int length(const char* m_other);
    friend std::ostream& operator<<(std::ostream& stream, string& str) { stream << str.m_data; return stream; }
    friend const char* operator (string& str)
    {

    }
private:
    char* m_data;
    int m_size;
};
