#include "ScriptParser.h"
#include "../Command/NewDirCommand.h"

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
    commands.push_back(std::make_shared<NewDirCommand>("test420"));

    return commands;
}
