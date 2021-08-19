#pragma once
#include "global.h"

class ICommand;

class ICommandExecuter
{
    public:

    static ICommandExecuter* GetInstance();

    virtual void ExecuteCommand(std::shared_ptr<ICommand> command) = 0;

    private:
};