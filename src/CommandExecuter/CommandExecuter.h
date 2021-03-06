#pragma once

#include "../global.h"
#include "ICommandExecuter.h"

class CommandExecuter : public ICommandExecuter
{
    public:

    void ExecuteCommand(std::shared_ptr<ICommand> command) override;
};