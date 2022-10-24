#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::endl;


class User {
    private:
        string userName;
        string publicKey;
        double balance;

    public:
        User(string u, string p, double b);

        // getters
        string getUserName() const;
        string getPublicKey() const {return this->publicKey;}
        double getBalance() const {return this->balance;}

        // setters
        void setUserName(const string s);
        void setPublicKey(const string s);
        void setBalance(const double b);

};