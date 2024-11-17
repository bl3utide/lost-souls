#include "state_sp.h"

namespace Code1Sp {

void StateAction::execute() const {
    auto context =
        std::make_unique<Context>(std::make_unique<ConcreteStateA>());
    context->request1();
    context->request2();
}

Context::Context(std::unique_ptr<State> state) : state_(nullptr) {
    std::cout << "[Context::Context] called" << std::endl;
    this->transitionTo(std::move(state));
}

Context::~Context() {
    std::cout << "[Context::~Context] called" << std::endl;
}

void Context::transitionTo(std::unique_ptr<State> state) {
    std::cout << "Context: transition to " << typeid(*state).name() << ".\n";
    this->state_ = std::move(state);
    this->state_->setContext(this);
}

void ConcreteStateA::handle1() {
    std::cout << "ConcreteStateA handles request1." << std::endl;
    ;
    std::cout << "ConcreteStateA wants to change the state of the context."
              << std::endl;

    this->context_->transitionTo(std::make_unique<ConcreteStateB>());
}

void ConcreteStateB::handle2() {
    std::cout << "ConcreteStateB handles request2" << std::endl;
    std::cout << "ConcreteStateB wants to change the state of the context."
              << std::endl;

    this->context_->transitionTo(std::make_unique<ConcreteStateA>());
}

} // namespace Code1Sp