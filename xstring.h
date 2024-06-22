#pragma once
#include <iostream>

class string
{
public:
    string(const char* m_other);
    ~string();
    int length(const char* m_other);

    friend std::ostream& operator<<(std::ostream& stream, string& str) { stream << str.m_data; return stream; }

    /*
     The bug here stems from the impolicit conversion functionality from string to const char*,
     that results in undefined behavior.
    */
    operator const char*() const noexcept { return m_data; }
private:
    char* m_data;
    int m_size;
};
