#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "action.h"

namespace Code1
{

class StateAction final : public ActionBase
{
public:
    void execute() const override;
};

class Context;

class State
{
public:
    virtual ~State() = default;
    void setContext(Context* context) {
        this->context_ = context;
    }
    virtual void handle1() = 0;
    virtual void handle2() = 0;

protected:
    Context* context_;
};

class Context
{
public:
    Context(State* state);
    ~Context();
    void transitionTo(State* state);
    void request1() { this->state_->handle1(); }
    void request2() { this->state_->handle2(); }

private:
    void deallocate();
    State* state_;
};

class ConcreteStateA : public State
{
public:
    ConcreteStateA()
    {
        std::cout << "ConcreteStateA::ConcreteStateA called" << std::endl;
    }
    ~ConcreteStateA()
    {
        std::cout << "ConcreteStateA::~ConcreteStateA called" << std::endl;
    }
    void handle1() override;
    void handle2() override
    {
        std::cout << "ConcreteStateA handles request2." << std::endl;
    }
};

class ConcreteStateB : public State
{
public:
    ConcreteStateB()
    {
        std::cout << "ConcreteStateB::ConcreteStateB called" << std::endl;
    }
    ~ConcreteStateB()
    {
        std::cout << "ConcreteStateB::~ConcreteStateB called" << std::endl;
    }
    void handle1() override
    {
        std::cout << "ConcreteStateB handles request1." << std::endl;
    }
    void handle2() override;
};

} // namespace Code1

#endif // STATE_H