#include "user.h"

User::User(string u, string p, double b){
    this->userName = u;
    this->publicKey = p;
    this->balance = b;

    return *this;
}

// getters
string &User::getuserName() const {
    return this->userName;
}

string &User::getpublicKey() const {
    return this->publicKey;
}

string &User::getbalance() const {
    return this->balance;
}

// setters
void User::setuserName(string s){
    this->userName = s;
}

void setPublicKey(string s){
    this->publicKey = s;
}

void User::setBalance(double s){
    this->balance = s;
}

