#include "CommandExecuter.h"

#include "../Command/ICommand.h"
#include "../Command/NewDirCommand.h"
#include "../Command/NewFileCommand.h"
#include "../Command/RemoveFileCommand.h"
#include "../Command/CopyFileCommand.h"
#include "../Command/MoveFileCommand.h"

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

    else if(IsType<ICommand, RemoveFileCommand>(command.get()))
    {
        RemoveFileCommand* rmFileCmd = dynamic_cast<RemoveFileCommand*>(command.get());
        std::cout<<"RemoveFileCommand: "<<rmFileCmd->Filename()<<std::endl;
        std::filesystem::remove(rmFileCmd->Filename());
    }

    else if(IsType<ICommand, CopyFileCommand>(command.get()))
    {
        CopyFileCommand* cpFileCmd = dynamic_cast<CopyFileCommand*>(command.get());
        std::cout<<"CopyFileCommand: "<<cpFileCmd->FileToCopy()<<", "<<cpFileCmd->PathToCopyTo()<<std::endl;
        std::filesystem::copy(cpFileCmd->FileToCopy(), cpFileCmd->PathToCopyTo());
    }

    else if(MoveFileCommand* mvFileCmd = DynCast<ICommand, MoveFileCommand>(command.get()); mvFileCmd) 
    {
        std::cout<<"MoveFileCommand: "<<mvFileCmd->FileToMove()<<", "<<mvFileCmd->PathToMoveTo()<<std::endl;
        std::filesystem::rename(mvFileCmd->FileToMove(), mvFileCmd->PathToMoveTo());
    }

}