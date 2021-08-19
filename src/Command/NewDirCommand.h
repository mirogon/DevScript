#pragma once

#include "ICommand.h"

class NewDirCommand : public ICommand
{
    public:

    NewDirCommand(const std::string& newDirPath);
    NewDirCommand(std::string&& newDirPath);

    std::string Path();

    private:

    std::string newPath;
    
};