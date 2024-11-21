#include "smart_pointer.h"

namespace Code2 {

void SmartPointerAction::execute() const {
    std::cout
        << "[SmartPointerAction::execute] make raw pointer through a unique_ptr"
        << std::endl;
    auto bar = std::make_unique<Bar>(new Foo{ 3 });
    bar->whatIsFooX();
    std::cout << "[SmartPointerAction::execute] override bar obj" << std::endl;
    bar = std::make_unique<Bar>(new FooFoo{ 4, 44 });
    bar->whatIsFooX();
    nl();
    std::cout << "[SmartPointerAction::execute] override obj using reset"
              << std::endl;
    std::unique_ptr<Biz> biz;
    std::cout << "[SmartPointerAction::execute] 1st reset\n";
    biz.reset(Biz::create(10));
    std::cout << "[SmartPointerAction::execute] 2nd reset\n";
    biz.reset(Biz::create(12));
    nl();
    std::cout << "[SmartPointerAction::execute] pointer in smart pointer\n";
    // auto having_something = std::make_unique<HpConcrete>(30);
    HpConcrete having_something{ 30 };

    std::cout << "[SmartPointerAction::execute] exec end" << std::endl;
}

} // namespace Code2