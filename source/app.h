#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

#include "transaction.h"
#include "transactionPool.h"
#include "user.h"
#include "userPool.h"
#include "block.h"
#include "generator.h"

class App {
    private:
        int argc;
        char** argv;
        string argument;

    public:
        void Args(int argc, char** argv);
        void run();
        void mineAll();
        void mineAmount();
        void stats(vector<User> Users, vector<User> copyOfUsers);
};

// UserPool UserPool, vector<User> Users, 