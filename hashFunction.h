#pragma once
#include <string>

class CHashFunction {
public:
    int m_Adler32HashFunction(const std::string& key, int capacity);
};
