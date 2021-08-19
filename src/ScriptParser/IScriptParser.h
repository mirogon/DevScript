#pragma once
#include <string>

class IScriptParser
{
   public: 

    IScriptParser();

    virtual void SetFile(const std::string& file) = 0;
    virtual void Parse() = 0;

    protected:
    std::string file;

};