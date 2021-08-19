#include "CommandExecuter.h"

#include "../Command/ICommand.h"
#include "../Command/NewDirCommand.h"


void CommandExecuter::ExecuteCommand(std::shared_ptr<ICommand> command)
{
    if(IsType<ICommand, NewDirCommand>(command.get()))
    {
        NewDirCommand* newdirCmd = dynamic_cast<NewDirCommand*>(command.get());
        std::cout<<"NewDirCommand: "<<newdirCmd->Path()<<std::endl;
    }
    
}