#include "DevScriptInterpreter.h"

int main(int argc, char* argv[])
{

    try
    {
        DevScriptInterpreter interpreter(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}