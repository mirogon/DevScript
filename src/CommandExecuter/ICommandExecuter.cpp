#include "ICommandExecuter.h"

ICommandExecuter* ICommandExecuter::GetInstance()
{
    static auto executer = std::make_unique<ICommandExecuter>();
    return executer.get();
}
