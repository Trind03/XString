#pragma once

class string
{
public:
    string(const char* m_other);
    ~string();
    int length(const char*& m_data);

    char* m_data;
};