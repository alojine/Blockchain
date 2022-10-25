#include "transaction.h"
#include "generator.h"
#include "user.h"

class App{
    private: //
        int argc;
        char **argv;
        string argument;        

    public:
        void Args(int argc, char **argv);
        void run();
};