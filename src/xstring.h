#pragma once
#include <iostream>
#include <cstring>

class string
{
public:
    string(const char* m_other); 
    string();
    string(char*&& ptr);
    //string(string& str) = delete;
    ~string();

    int length();

    friend std::ostream& operator<<(std::ostream& stream, string& str) { stream << str.m_data; return stream; }
    
    friend string operator+(string& string1, string& string2)
    {
        int total = string1.calculate_size(string1.m_data) + string2.calculate_size(string2.m_data);
        total++;
        char* str = new char[total]; str[total - 1] = '\0';
 
        strcpy_s(str,total,string1.m_data);
        strcat_s(str,total,string2.m_data);
        
        string1.~string();
        string2.~string();
        return string(str);
    }
/*
    friend string operator+(const char* string1, string new_str)
    {
        int total_size = new_str.calculate_size(string1) + new_str.calculate_size(new_str.m_data);
    }
*/
    explicit operator const char*() const { return m_data; }
private:
    int calculate_size(const char* m_other);
    char* m_data;
    int m_size;
    bool m_data_mem;
};
