#include "hashfunction.h"

int CHashFunction::m_MidSquareHashFunction(int key, int capacity) {
    long long square = 1LL * key * key;

    square /= 10;
    int middle = square % 100;

    return middle % capacity;
}

int CHashFunction::m_Adler32HashFunction(const std::string& key, int capacity) {
    const int MOD_ADLER = 65521;
    int a = 1, b = 0;

    for (char ch : key) {
        a = (a + (unsigned char)ch) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }

    unsigned int hash = (b << 16) | a;
    return hash % capacity;
}
