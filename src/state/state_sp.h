#ifndef STATE_SP_H
#define STATE_SP_H

#include <iostream>
#include <memory>
#include "action.h"

namespace Code1Sp
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
    Context(std::unique_ptr<State> state);
    ~Context();
    void transitionTo(std::unique_ptr<State> state);
    void request1() { this->state_->handle1(); }
    void request2() { this->state_->handle2(); }

private:
    std::unique_ptr<State> state_;
};

class ConcreteStateA : public State
{
public:
    ConcreteStateA()
    {
        std::cout << "[ConcreteStateA::ConcreteStateA] called" << std::endl;
    }
    ~ConcreteStateA()
    {
        std::cout << "[ConcreteStateA::~ConcreteStateA] called" << std::endl;
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
        std::cout << "[ConcreteStateB::ConcreteStateB] called" << std::endl;
    }
    ~ConcreteStateB()
    {
        std::cout << "[ConcreteStateB::~ConcreteStateB] called" << std::endl;
    }
    void handle1() override
    {
        std::cout << "ConcreteStateB handles request1." << std::endl;
    }
    void handle2() override;
};

} // namespace Code1Sp

#endif // STATE_SP_H
