#include <iostream>
#include <memory>

#include "callback.h"
#include "state.h"
#include "smart_pointer.h"

static void exeCallbackAction()
{
    CallbackT c;
    try
    {
        InputConnection conn;
        std::cout << typeid(conn).name() << std::endl;
        CallbackAssignor<CallbackConcereteA>{ conn }.setCallback();
        c = conn.cb_;
        conn.invoke();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    c(9, 10);
}

static void exeStateAction()
{
    std::cout << "======== state ========" << std::endl;
    const auto action = std::make_unique<StateAction>();
    action->execute();
}

static void exeSmartPointerAction()
{
    std::cout << "======== smart pointer ========" << std::endl;
    auto action = std::make_unique <SmartPointerAction>();
    action->execute();
}

int main()
{
    exeStateAction();
    exeSmartPointerAction();
    return EXIT_SUCCESS;
}
