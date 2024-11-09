#include "state.h"

void StateAction::execute()
{
    Context* context = new Context(new ConcreteStateA);
    context->request1();
    context->request2();
    delete context;
}

Context::Context(State* state)
    : state_(nullptr)
{
    this->transitionTo(state);
}

Context::~Context()
{
    deallocate();
}

void Context::transitionTo(State* state)
{
    std::cout << "Context: transition to " << typeid(*state).name() << ".\n";
    deallocate();
    this->state_ = state;
    this->state_->setContext(this);
}

void Context::deallocate()
{
    if (this->state_ != nullptr)
    {
        delete this->state_;
    }
}

void ConcreteStateA::handle1()
{
    std::cout << "ConcreteStateA handles request1." << std::endl;;
    std::cout << "ConcreteStateA wants to change the state of the context."
        << std::endl;

    this->context_->transitionTo(new ConcreteStateB);
}