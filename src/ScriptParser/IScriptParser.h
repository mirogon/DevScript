#pragma once
#include "../global.h"

class ICommand;

class IScriptParser
{
   public: 

    IScriptParser();

    virtual void SetFile(const std::string& file) = 0;
    virtual std::vector<std::shared_ptr<ICommand>> Parse() = 0;

    protected:
    std::string file;

};