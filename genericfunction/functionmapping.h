#ifndef FUNCTIONMAPPING_H
#define FUNCTIONMAPPING_H

#include <functional>
#include <any>

/***************************************
 *          Generic function           *
 ***************************************/
template<typename Ret>
struct CallableFunc
{
    CallableFunc() {}

    template<typename F>
    CallableFunc(F&& func) : CallableFunc(std::function(std::forward<F>(func))) {}

    template<typename ... Args>
    CallableFunc(std::function<Ret(Args...)> func) : m_any(func) {}

    template<typename ... Args>
    Ret operator()(Args&&... args) {
        return std::invoke(std::any_cast<std::function<Ret(Args...)>>(m_any),std::forward<Args>(args)...);
    }

    std::any m_any;
};


#include <string>
#include <unordered_map>
#include <QDebug>

using namespace std;

class FunctionMapping
{
public:
    static FunctionMapping* INSTANCE;

    template<typename T>
    CallableFunc<T> callFunc(string functionName) {
        if (std::is_same<T, void>::value) {
            return voidRetFuncMap[functionName];
        }
        else if (std::is_base_of<string, T>::value) {
            return stringRetFuncMap[functionName];
        }
        else if (std::is_same<T, int>::value) {
            return intRetFuncMap[functionName];
        }
        else if (std::is_same<T, float>::value) {
            return floatRetFuncMap[functionName];
        }
        else if (std::is_same<T, double>::value) {
            return doubleRetFuncMap[functionName];
        }
        else if (std::is_same<T, bool>::value) {
            return boolRetFuncMap[functionName];
        }
        else if (std::is_base_of<void*, T>::value) {
            return pointerRetFuncMap[functionName];
        }
    }

    unordered_map<string, CallableFunc<void>> voidRetFuncMap;
    unordered_map<string, CallableFunc<void*>> pointerRetFuncMap;
    unordered_map<string, CallableFunc<float>> floatRetFuncMap;
    unordered_map<string, CallableFunc<int>> intRetFuncMap;
    unordered_map<string, CallableFunc<string>> stringRetFuncMap;
    unordered_map<string, CallableFunc<double>> doubleRetFuncMap;
    unordered_map<string, CallableFunc<bool>> boolRetFuncMap;

private:
    FunctionMapping();
    ~FunctionMapping();
};

#endif // FUNCTIONMAPPING_H
