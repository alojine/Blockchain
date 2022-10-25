#include "app.h"

void App::Args(int argc, char **argv)
{
    this->argc = argc;
    this->argv = argv;
    this->argument = argv[1];
}

void App::run(){
    if(argument == "--st"){
        cout << "hello";
    }



    
}