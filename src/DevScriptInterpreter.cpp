#include "DevScriptInterpreter.h"


void DevScriptInterpreter::PrintUsage()
{
    std::cout<<"Usage: DevScript <file>"<<std::endl;
}

DevScriptInterpreter::DevScriptInterpreter(int argc, char* argv[])
{
    if(argc < 2)
    {
        PrintUsage();
        throw std::exception("not enough arguments!");
    }
    //Check if first arg is a ds file
    std::string file = argv[1];

    if(file.find(".ds") == std::string::npos)
    {
       PrintUsage(); 
       throw std::exception("file is not a valid .ds file!");
    }

    if(!std::filesystem::exists(file))
    {
        throw std::exception("file does not exist!");
    }

    this->file = file;
}