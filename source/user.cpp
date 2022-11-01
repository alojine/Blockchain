#include "user.h"
#include "hash.h"

User::User(string u, double b) {
    Hash Hash;
    this->userName = u;
    this->publicKey = Hash.makeHash(u);
    this->balance = b;
}

// getters
string User::getUserName() {
    return this->userName;
}

string User::getPublicKey() {
    return this->publicKey;
}

double User::getBalance() {
    return this->balance;
}

// setters
void User::setUserName(string s) {
    this->userName = s;
}

void User::setPublicKey(string s) {
    this->publicKey = s;
}

void User::setBalance(double s) {
    this->balance = s;
}

