#pragma once

#include "../global.h"
#include "IScriptParser.h"

class ScriptParser : public IScriptParser
{
    public:

    ScriptParser();
    void SetFile(const std::string& file) override;
    std::vector<std::shared_ptr<ICommand>> Parse() override;

    private:


};