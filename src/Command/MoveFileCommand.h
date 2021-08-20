#pragma once
#include "../global.h"
#include "ICommand.h"

class MoveFileCommand : public ICommand
{
    public:

    MoveFileCommand(const std::string& pFileToMove, const std::string& pPathToMoveTo);
    MoveFileCommand(std::string&& pFileToMove, std::string&& pPathToMoveTo);

    std::string FileToMove();
    std::string PathToMoveTo();

    private:

    std::string fileToMove;
    std::string pathToMoveTo; 
};