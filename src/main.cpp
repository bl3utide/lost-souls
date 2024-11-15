#include <iostream>
#include <memory>

#include "callback/callback.h"
#include "state/state.h"
#include "state/state_sp.h"
#include "smart_pointer/smart_pointer.h"
#include "mediator/mediator.h"

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
    using namespace Code1;
    std::cout << "======== state ========" << std::endl;
    const auto action = std::make_unique<StateAction>();
    action->execute();
    std::cout << "\n";
}

static void exeStateSpAction()
{
    using namespace Code1Sp;
    std::cout << "======== state (smart pointer version) ========" << std::endl;
    const auto action = std::make_unique<StateAction>();
    action->execute();
    std::cout << "\n";
}

static void exeSmartPointerAction()
{
    using namespace Code2;
    std::cout << "======== smart pointer ========" << std::endl;
    auto action = std::make_unique<SmartPointerAction>();
    action->execute();
    std::cout << "\n";
}

static void exeMediatorAction()
{
    using namespace Code3;
    std::cout << "======== mediator ========" << std::endl;
    auto action = std::make_unique<MediatorAction>();
    action->execute();
    std::cout << "\n";
}

int main()
{
    exeStateAction();
    exeStateSpAction();
    exeSmartPointerAction();
    exeMediatorAction();
    return EXIT_SUCCESS;
}
