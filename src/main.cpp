#include "DevScriptInterpreter.h"
#include "ScriptParser/ScriptParser.h"
#include "CommandExecuter/CommandExecuter.h"

int main(int argc, char* argv[])
{

    try
    {
        std::unique_ptr<IScriptParser> scriptParser = std::make_unique<ScriptParser>();
        std::unique_ptr<ICommandExecuter> commandExecuter = std::make_unique<CommandExecuter>();
        //IScriptParser* p = new ScriptParser();
        DevScriptInterpreter interpreter(argc, argv, scriptParser.release(), commandExecuter.release());
        interpreter.Execute();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}