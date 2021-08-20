#pragma once

#include "../global.h"
#include "ICommand.h"

class NewFileCommand : public ICommand
{

    public:

    NewFileCommand(const std::string& pFile);
    NewFileCommand(std::string&& pFile);

    std::string Filename();

    private:

    std::string fileName;

};