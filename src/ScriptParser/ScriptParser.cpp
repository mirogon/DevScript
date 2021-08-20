#include "ScriptParser.h"
#include "../Command/NewDirCommand.h"
#include "../Command/NewFileCommand.h"
#include "../Command/RemoveFileCommand.h"
#include "../Command/CopyFileCommand.h"
#include "../Command/MoveFileCommand.h"

ScriptParser::ScriptParser():
    IScriptParser()
{
}
void ScriptParser::SetFile(const std::string& file)
{
    this->file = file;
}

std::vector<std::shared_ptr<ICommand>> ScriptParser::Parse()
{
    std::vector<std::shared_ptr<ICommand>> commands;

    std::ifstream fileReadStream(file, std::ios::in);

    std::string line;
    while(std::getline(fileReadStream, line))
    {
        if(line.find("mkdir") != std::string::npos || line.find("create_directory") != std::string::npos || line.find("create_folder") != std::string::npos)
        {
            //Get folder name
            std::string folderName = "";
            size_t parenthesesStart = line.find('(');
            if(parenthesesStart == std::string::npos)
            {
                continue;
            }
            for(auto it = line.begin()+parenthesesStart+1; *it != ')'; ++it)
            {
                if(*it == ' ' || *it == 34 || *it == 39)
                {
                    continue;
                }
                folderName += *it;
            }                
            commands.push_back(std::make_shared<NewDirCommand>(folderName)); 
            continue;
        }
        else if(line.find("create_file") != std::string::npos || line.find("touch") != std::string::npos)
        {
            //Get filename
            std::string newFileName = "";
            size_t parenthesesStart = line.find('(');
            if(parenthesesStart == std::string::npos)
            {
                continue;
            }
            for(auto it = line.begin() + parenthesesStart +1; *it != ')'; ++it)
            {
                if(*it == ' ' || *it == 34 || *it == 39)
                {
                    continue;
                }
                newFileName+=*it;
            }
            commands.push_back(std::make_shared<NewFileCommand>(newFileName));
            continue;
        }
        else if(line.find("remove_file") != std::string::npos || line.find("rm") != std::string::npos)
        {
            //File to remove
            std::string fileName = "";
            size_t parenthesesStart = line.find('(');
            if(parenthesesStart == std::string::npos)
            {
                continue;
            }
            for(auto it = line.begin() + parenthesesStart + 1; *it != ')'; ++it)
            {
                if(*it == ' ' || *it == 34 || *it == 39)
                {
                    continue;
                }
                fileName += *it;
            }
            commands.push_back(std::make_shared<RemoveFileCommand>(fileName));
            continue;
        }
        else if(line.find("copy_file") != std::string::npos || line.find("cp") != std::string::npos)
        {
            //File to copy
            std::string fileToCopy = "";
            size_t parenthesesStart = line.find('(');
            if(parenthesesStart == std::string::npos)
            {
                continue;
            }
            for(auto it = line.begin() + parenthesesStart +1; *it != ','; ++it)
            {
                if(*it == ' ' || *it == 34 || *it == 39)
                {
                    continue;
                }
                fileToCopy += *it;
            }

            //path to copy to
            std::string pathToCopyTo = "";
            size_t commaStart = line.find(',');
            if(commaStart == std::string::npos)
            {
                continue;
            }

            for(auto it = line.begin() + commaStart +1; *it != ')'; ++it)
            {
                if(*it == ' ' || *it == 34 || *it == 39)
                {
                    continue;
                }
                pathToCopyTo += *it;
            }

            commands.push_back(std::make_shared<CopyFileCommand>(fileToCopy, pathToCopyTo));
            continue;
        }
        else if(line.find("move_file") != std::string::npos || line.find("mv") != std::string::npos)
        {
            //File to move
            std::string fileToMove = "";
            size_t parenthesesStart = line.find('(');
            if(parenthesesStart == std::string::npos)
            {
                continue;
            }
            for(auto it = line.begin() + parenthesesStart +1; *it != ','; ++it)
            {
                if(*it == ' ' || *it == 34 || *it == 39)
                {
                    continue;
                }
                fileToMove += *it;
            }

            //path to move to
            std::string newFilePath = "";
            size_t commaStart = line.find(',');
            if(commaStart == std::string::npos)
            {
                continue;
            }

            for(auto it = line.begin() + commaStart +1; *it != ')'; ++it)
            {
                if(*it == ' ' || *it == 34 || *it == 39)
                {
                    continue;
                }
                newFilePath += *it;
            }

            commands.push_back(std::make_shared<MoveFileCommand>(fileToMove, newFilePath));
            continue;
        }
    }
    fileReadStream.close();
    return commands;
}
