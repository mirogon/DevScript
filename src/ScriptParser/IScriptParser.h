#pragma once
#include <string>

class IScriptParser
{
   public: 

    IScriptParser();

    virtual void SetFile(const std::string& file) = 0;

    protected:

    virtual void Parse() = 0;

    std::string file;

};