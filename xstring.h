#pragma once
#include <iostream>

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
    
    friend string operator+(string string1, string string2)
    {
        int string1_size = string1.calculate_size(string1.m_data),string2_size = string2.calculate_size(string2.m_data);

        char* str = new char(string1_size + string2_size);

        strcpy(str,string1.m_data);
        strcpy(str,string2.m_data);
        
        string1.~string();
        string2.~string();

        string result = std::move(str);
        return result;
    }
    explicit operator const char*() const { return m_data; }
private:
    int calculate_size(const char* m_other);
    char* m_data;
    int m_size;
};
