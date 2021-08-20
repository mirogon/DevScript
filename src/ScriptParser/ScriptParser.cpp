#include "ScriptParser.h"
#include "../Command/NewDirCommand.h"
#include "../Command/NewFileCommand.h"

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
        std::cout<<"parsing line..."<<std::endl;
        std::cout<<line<<std::endl;
        if(line.find("mkdir") != std::string::npos)
        {
            //Get folder name
            std::string folderName = "";
            size_t parenthesesStart = line.find('(');
            if(parenthesesStart != std::string::npos)
            {
                for(auto it = line.begin()+parenthesesStart+1; *it != ')'; ++it)
                {
                    if(*it == ' ' || *it == 34 || *it == 39)
                    {
                        continue;
                    }
                    folderName += *it;
                }                
            }

            commands.push_back(std::make_shared<NewDirCommand>(folderName)); 
            continue;
        }
        else if(line.find("create_file") != std::string::npos)
        {
            //Get filename
            std::string newFileName = "";
            size_t parenthesesStart = line.find('(');
            if(parenthesesStart != std::string::npos)
            {
                for(auto it = line.begin() + parenthesesStart +1; *it != ')'; ++it)
                {
                    if(*it == ' ' || *it == 34 || *it == 39)
                    {
                        continue;
                    }
                    newFileName+=*it;
                }
            }
            commands.push_back(std::make_shared<NewFileCommand>(newFileName));
            continue;
        }
    }
    fileReadStream.close();
    return commands;
}
