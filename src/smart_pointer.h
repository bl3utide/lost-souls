#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <iostream>
#include <memory>

namespace Code2
{

class Foo;

class SmartPointerAction final
{
public:
    void execute();
};

class Foo
{
    int x_;
public:
    explicit Foo(int x) : x_(x)
    {
        std::cout << "[Foo::Foo] x = " << x_ << std::endl;
    }
    virtual ~Foo()
    {
        std::cout << "[Foo::~Foo] x = " << x_ << std::endl;
    }
    void printX() const noexcept
    {
        std::cout << "[Foo::printX] " << x_ << std::endl;
    }
    auto getX() const noexcept { return x_; }
};

class FooFoo : public Foo
{
    int y_;
public:
    explicit FooFoo(int x, int y) : y_(y), Foo(x)
    {
        std::cout << "[FooFoo::FooFoo] y = " << y_ << std::endl;
    }
    ~FooFoo()
    {
        std::cout << "[FooFoo::~FooFoo] y = " << y_ << std::endl;
    }
    void printY() const noexcept
    {
        std::cout << "[FooFoo::printY] " << y_ << std::endl;
    }
    auto getY() const noexcept { return y_; }
};

class Bar
{
public:
    // constructor accepts obj as pointer
    Bar(Foo* foo) : foo_(foo)
    {
        std::cout << "[Bar::Bar] foo.x_ : " << foo_->getX() << std::endl;
    }
    ~Bar()
    {
        std::cout << "[Bar::~Bar] foo.x_ : " << foo_->getX() << std::endl;
    }
    void whatIsFooX()
    {
        foo_->printX();
    }
private:
    // having obj as smart pointer
    const std::unique_ptr<Foo> foo_;
};

} // namespace Cod2

#endif // SMART_POINTER_H
