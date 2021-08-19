#pragma once

#include "global.h"
#include "CommandExecuter/ICommandExecuter.h"

class DevScriptInterpreter
{

    public:

    DevScriptInterpreter(int argc, char* argv[]);


    private:

    void PrintUsage();


    private/*Member*/:

    std::string file;

};