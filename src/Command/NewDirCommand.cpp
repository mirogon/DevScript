#include "NewDirCommand.h"


NewDirCommand::NewDirCommand(const std::string& newPath):
    ICommand()
{
    this->newPath = newPath;
}

NewDirCommand::NewDirCommand(std::string&& newDirPath):
    ICommand()
{
    this->newPath = newPath;
}

std::string NewDirCommand::Path()
{
    return newPath;
}

