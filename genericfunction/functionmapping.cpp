#include "functionmapping.h"
#include "functions.h"

FunctionMapping* FunctionMapping::INSTANCE = new FunctionMapping();

FunctionMapping::FunctionMapping()
{
    voidRetFuncMap["printString"] = &printString;
    voidRetFuncMap["friendFunc1"] = &friendFunc1;
    pointerRetFuncMap["spawnObject"] = &spawnObject;
}
