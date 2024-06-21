#pragma once

class string
{
public:
    string(const char* m_other);
    int length(const char*& m_data);

    char* m_data;
};