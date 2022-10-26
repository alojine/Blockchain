#ifndef HASH_H
#define HASH_H

#include <iostream>

using namespace std;

class Hash{
    private:
        string str_;

        int rightRotate(int n, int d);
        int leftRotate(int n, int d);

        string leftRotate(string str1, int n);
        string rightRotate(string str1, int n);

        int rotr(std::uint32_t v, std::int32_t shift);
        int rotl(std::uint32_t v, std::int32_t shift);

        string binToHex(string s);
    
    public:
        Hash();     //default c
        ~Hash();    //destructor

        void setHash(std::string);  // setter   
        const string& getHash() const;  // getter
        const string& makeHash(std::string);

};

#endif