#include "NewDirCommand.h"


NewDirCommand::NewDirCommand(const std::string& pPath):
    ICommand()
{
    this->newPath = pPath;
}

NewDirCommand::NewDirCommand(std::string&& pPath):
    ICommand()
{
    this->newPath = pPath;
}

std::string NewDirCommand::Path()
{
    return newPath;
}

