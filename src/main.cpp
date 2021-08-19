#include "DevScriptInterpreter.h"

#include "ScriptParser/ScriptParser.h"

int main(int argc, char* argv[])
{

    try
    {
        std::unique_ptr<IScriptParser> scriptParser = std::make_unique<ScriptParser>();
        DevScriptInterpreter interpreter(argc, argv, scriptParser.release());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}