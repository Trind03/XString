#pragma once
#include <iostream>
#include <cstring>

class string
{
public:
    string(const char* m_other); 
    string();
    string(char*&& other);
    ~string();
    
    std::size_t length();
    int to_upper();

    /* Overloads for operators */
    friend std::ostream& operator<<(std::ostream& stream, string& str)
    {
        std::cout << "<< overload" << std::endl;
        stream << str.m_data; return stream;
    }
    
    // Out of order
private:
    friend string operator+(string& string1, string& string2)
    {
        std::size_t size = strlen(string1.m_data) + strlen(string2.m_data) + 1;
        std::cout << "+ overload" << std::endl;
        char* new_data = new char[size];
        strcpy(new_data, string1.m_data);
        strcpy(new_data, string2.m_data);
        strcpy(new_data, "\0");
        string data = string(std::move(new_data));
        delete[] new_data;
        return data;
    }
public:
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
