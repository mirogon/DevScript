#pragma once
#include <string>

class IScriptParser
{
   public: 

    IScriptParser(const std::string& path);


    private:

    void Parse();

    std::string file;

};