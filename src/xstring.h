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
    friend std::ostream& operator<<(std::ostream& stream, string& str)
    {
        std::cout << "<< overload" << std::endl;
        stream << str.m_data; return stream;
    }
    
    friend string operator+(string& string1, string& string2)
    {
        std::cout << "+ overload" << std::endl;
        return string(string1.m_data += *string1.m_data);
    }
    const char* operator==(const char* param) const
    {
        std::cout << "== overload" << std::endl;
        return this->m_data;
    }

    string& operator=(const char*&& data)
    {
        std::cout << "= overload" << std::endl;
        if(m_data != data)
        {
            delete[] m_data;
            m_data = nullptr;
        }
        m_size = strlen(data);
        m_data = new char[m_size];
        std::memcmp(m_data,data,length());
        return *this;
    }

    explicit operator const char*() const { return m_data; }
    std::size_t length(const char* m_other);
private:
    void write_size(const char* metadata);
    char* m_data;
    bool live_data;
    std::size_t m_size;
};
