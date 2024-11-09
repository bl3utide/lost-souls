#ifndef STATE_H
#define STATE_H

#include <iostream>

class StateAction final
{
public:
    void execute();
};

class Context;

class State
{
public:
    virtual ~State() = default;
    void setContext(Context* context) { this->context_ = context; }
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
    void handle1() override;
    void handle2() override
    {
        std::cout << "ConcreteStateA handles request2." << std::endl;
    }
};

class ConcreteStateB : public State
{
public:
    void handle1() override
    {
        std::cout << "ConcreteStateB handles request1." << std::endl;
    }
    void handle2() override
    {
        std::cout << "ConcreteStateB handles request2" << std::endl;
        std::cout << "ConcreteStateB wants to change the state of the context."
            << std::endl;

        this->context_->transitionTo(new ConcreteStateA);
    }
};

#endif // STATE_H