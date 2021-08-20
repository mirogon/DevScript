#pragma once

#include "../global.h"
#include "ICommand.h"

class RemoveFileCommand : public ICommand
{
    public:

    RemoveFileCommand(const std::string& pFile);
    RemoveFileCommand(std::string&& pFile);

    std::string Filename();

    private:

    std::string fileToRemove;
};