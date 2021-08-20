#include "MoveFileCommand.h"
MoveFileCommand::MoveFileCommand(const std::string& pFileToMove, const std::string& pPathToMoveTo) 
{
    fileToMove = pFileToMove;
    pathToMoveTo = pPathToMoveTo;
}

MoveFileCommand::MoveFileCommand(std::string&& pFileToMove, std::string&& pPathToMoveTo) 
{
   fileToMove = pFileToMove;
   pathToMoveTo = pPathToMoveTo; 
}

std::string MoveFileCommand::FileToMove() 
{
    return fileToMove;
}
std::string MoveFileCommand::PathToMoveTo()
{
    return pathToMoveTo;
}

