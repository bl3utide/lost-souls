#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>
#include <iostream>
#include "action.h"

namespace Code3
{

class MediatorAction final : public ActionBase
{
public:
    void execute() const override;
};

class BaseComponent;
class Mediator
{
public:
    virtual void notify(BaseComponent* sender, std::string event) const = 0;
};

class BaseComponent
{
protected:
    Mediator* mediator_;

public:
    BaseComponent(Mediator* mediator = nullptr)
        : mediator_(mediator)
    {
    }
    void setMediator(Mediator* mediator)
    {
        this->mediator_ = mediator;
    }
};

class Component1 : public BaseComponent
{
public:
    void DoA()
    {
        std::cout << "Component 1 does A.\n";
        this->mediator_->notify(this, "A");
    }
    void DoB()
    {
        std::cout << "Component 1 does B.\n";
        this->mediator_->notify(this, "B");
    }
};

class Component2 : public BaseComponent
{
public:
    void DoC()
    {
        std::cout << "Component 2 does C.\n";
        this->mediator_->notify(this, "C");
    }
    void DoD()
    {
        std::cout << "Component 2 does D.\n";
        this->mediator_->notify(this, "D");
    }
};

class ConcreteMediator : public Mediator
{
private:
    Component1* component1_;
    Component2* component2_;

public:
    ConcreteMediator(Component1* c1, Component2* c2)
        : component1_(c1), component2_(c2)
    {
        this->component1_->setMediator(this);
        this->component2_->setMediator(this);
    }
    void notify(BaseComponent* sender, std::string event) const override
    {
        if (event == "A")
        {
            std::cout << "Mediator reacts on A and triggers following operations:\n";
            this->component2_->DoC();
        }
        if (event == "D")
        {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            this->component1_->DoB();
            this->component2_->DoC();
        }
    }
};

} // namespace Code3

#endif // MEDIATOR_H
