#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QDebug>
#include <vector>

class Object
{
public:
    Object(){}

    void func1(int param) {
        qDebug() << QString::number(param);
    }
};

void friendFunc1(std::vector<void*> params) {
    return static_cast<Object*>(params.at(0))->func1(*static_cast<int*>(params.at(1)));
}

void* spawnObject() {
    return new Object();
}

void printString(int param) {
    qDebug() << QString::number(param);
}
#endif // FUNCTIONS_H
