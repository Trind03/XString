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
    
    int length();
    int to_upper();


    friend std::ostream& operator<<(std::ostream& stream, string& str) { stream << str.m_data; return stream; }
    
    friend string operator+(string& string1, string& string2)
    {
        int total = string1.calculate_size(string1.m_data) + string2.calculate_size(string2.m_data);
        total++;
        char* str = new char[total]; str[total - 1] = '\0';
 
        strcpy(str,string1.m_data);
        strcat(str,string2.m_data);
        return string(std::move(str));
    }
    const char* operator==(const char* param) const
    {
        return this->m_data;
    }
    explicit operator const char*() const { return m_data; }
private:
    int calculate_size(const char* m_other);
    char* m_data;
    std::size_t m_size;
    bool live_data;
};
