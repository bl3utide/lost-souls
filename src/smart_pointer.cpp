#include "smart_pointer.h"

void SmartPointerAction::execute()
{
    std::cout << "[SmartPointerAction::execute] make raw pointer through a unique_ptr" << std::endl;
    auto bar = std::make_unique<Bar>(new Foo{ 3 });
    bar->whatIsFooX();
    std::cout << "[SmartPointerAction::execute] override bar obj" << std::endl;
    bar = std::make_unique<Bar>(new FooFoo{ 4, 44 });
    bar->whatIsFooX();
    std::cout << "[SmartPointerAction::execute] exec end" << std::endl;
}
