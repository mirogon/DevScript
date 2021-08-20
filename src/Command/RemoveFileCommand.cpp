#include "RemoveFileCommand.h"

RemoveFileCommand::RemoveFileCommand(const std::string& pFile) 
{
   this->fileToRemove = pFile; 
}

RemoveFileCommand::RemoveFileCommand(std::string&& pFile) 
{
   this->fileToRemove = pFile; 
}

std::string RemoveFileCommand::Filename() 
{
    return this->fileToRemove;
}
