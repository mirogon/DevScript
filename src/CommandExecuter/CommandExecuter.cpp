#include "CommandExecuter.h"

#include "../Command/ICommand.h"
#include "../Command/NewDirCommand.h"
#include "../Command/NewFileCommand.h"

void CommandExecuter::ExecuteCommand(std::shared_ptr<ICommand> command)
{
    if(IsType<ICommand, NewDirCommand>(command.get()))
    {
        NewDirCommand* newdirCmd = dynamic_cast<NewDirCommand*>(command.get());
        std::cout<<"NewDirCommand: "<<newdirCmd->Path()<<std::endl;
        std::filesystem::create_directories(newdirCmd->Path());
    }
    
    else if(IsType<ICommand, NewFileCommand>(command.get()))
    {
        NewFileCommand* newFileCmd = dynamic_cast<NewFileCommand*>(command.get());
        std::cout<<"NewFileCommand: "<<newFileCmd->Filename()<<std::endl;
        std::fstream fileOut;
        fileOut.open(newFileCmd->Filename(), std::ios::out);
        fileOut.close();
    }

}