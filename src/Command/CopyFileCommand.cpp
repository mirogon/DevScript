#include "CopyFileCommand.h"

CopyFileCommand::CopyFileCommand(const std::string& from, const std::string& to) 
{
    this->fileToCopy = from;
    this->pathToCopyTo = to;    
}

CopyFileCommand::CopyFileCommand(std::string&& from, std::string&& to) 
{
    this->fileToCopy = from;
    this->pathToCopyTo = to;
}

std::string CopyFileCommand::FileToCopy() 
{
    return fileToCopy;
}

std::string CopyFileCommand::PathToCopyTo()
{
    return pathToCopyTo;
}


