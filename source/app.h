#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
#include <random>

#include "transaction.h"
#include "transactionPool.h"
#include "user.h"
#include "userPool.h"
#include "block.h"
#include "generator.h"

const int d = 63;

class App {
    private:
        int argc;
        char** argv;
        string argument;

    public:
        void Args(int argc, char** argv);
        void run();
        void five();
        void stats(vector<User> Users, vector<User> copyOfUsers);
};

// UserPool UserPool, vector<User> Users, 