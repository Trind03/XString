#pragma once
#include <iostream>
#include <cstring>

class string
{
public:
    string(const char* m_other); 
    string();
    string(char*&& other);
    string(string&) = delete;
    ~string();
    
    std::size_t length();
    int to_upper();

    /* Overloads for operators */
    friend std::ostream& operator<<(std::ostream& stream, string& str) { stream << str.m_data; return stream; }
    
    friend string operator+(string& string1, string& string2)
    {
        int total = string1.length(string1.m_data) + string2.length(string2.m_data);

        return string(string1.m_data += *string1.m_data);
    }
    const char* operator==(const char* param) const
    {
        return this->m_data;
    }

    string& operator=(const char*&& data)
    {
        if(m_data != data)
        {
            delete[] m_data;
            m_data = nullptr;
        }
        m_data = new char[length(data)];
        std::memcmp(m_data,data,length());
        return *this;
    }

    explicit operator const char*() const { return m_data; }
private:
    std::size_t length(const char* m_other);
    char* m_data;
    bool live_data;
    std::size_t m_size;
};
