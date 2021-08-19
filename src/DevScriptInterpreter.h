#pragma once

#include "global.h"
#include "CommandExecuter/ICommandExecuter.h"

class IScriptParser;

class DevScriptInterpreter
{

    public:

    DevScriptInterpreter(int argc, char* argv[], IScriptParser* scriptParser, ICommandExecuter* commandExecuter);
    void Execute();
    void PrintUsage();

    private/*Member*/:

    std::unique_ptr<IScriptParser> scriptParser;
    std::unique_ptr<ICommandExecuter> commandExecuter;

};