#pragma once
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
};