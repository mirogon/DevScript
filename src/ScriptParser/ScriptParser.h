#pragma once

#include "../global.h"
#include "IScriptParser.h"

class ScriptParser : public IScriptParser
{
    public:

    void SetFile(const std::string& file) override;
    
    private:

    void Parse() override;

};