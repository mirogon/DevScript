#pragma once
#include "../global.h"
#include "ICommand.h"

class CopyFileCommand : public ICommand
{
    public:

    CopyFileCommand(const std::string& from, const std::string& to);
    CopyFileCommand(std::string&& from, std::string&& to);

    std::string FileToCopy();
    std::string PathToCopyTo();

    private:

    std::string fileToCopy;
    std::string pathToCopyTo;

};