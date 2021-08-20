#include "NewFileCommand.h"

NewFileCommand::NewFileCommand(const std::string& pFile)
{
    this->fileName = pFile;
}

NewFileCommand::NewFileCommand(std::string&& pFile)
{
    this->fileName = pFile;
}

std::string NewFileCommand::Filename()
{
    return fileName;
}