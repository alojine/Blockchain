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
        string getUserName();
        string getPublicKey();
        double getBalance();

        // setters
        void setUserName(const string s);
        void setPublicKey(const string s);
        void setBalance(const double b);

};