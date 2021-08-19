#pragma once

#include "ICommand.h"

class NewDirCommand : public ICommand
{
    public:

    NewDirCommand(const std::string& newDirPath);
    private:

    std::string newPath;
    
};