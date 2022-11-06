#include <QCoreApplication>
#include "functionmapping.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FunctionMapping::INSTANCE->voidRetFuncMap["printString"]((int)10);

    std::vector<void*> params;
    void* obj = FunctionMapping::INSTANCE->pointerRetFuncMap["spawnObject"]();
    qDebug() << "spawn object successfully";
    params.push_back(obj);
    params.push_back(new int(10));
    FunctionMapping::INSTANCE->voidRetFuncMap["friendFunc1"](static_cast<vector<void*>>(params));

    return a.exec();
}
