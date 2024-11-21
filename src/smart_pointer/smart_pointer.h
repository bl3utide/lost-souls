#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include "action.h"
#include <iostream>
#include <memory>

namespace Code2 {

class Foo;

class SmartPointerAction final : public ActionBase {
public:
    void execute() const override;
};

class Foo {
    int x_;

public:
    explicit Foo(int x)
        : x_(x) {
        std::cout << "[Foo::Foo] x = " << x_ << std::endl;
    }

    virtual ~Foo() {
        std::cout << "[Foo::~Foo] x = " << x_ << std::endl;
    }

    void printX() const noexcept {
        std::cout << "[Foo::printX] " << x_ << std::endl;
    }

    auto getX() const noexcept {
        return x_;
    }
};

class FooFoo : public Foo {
    int y_;

public:
    explicit FooFoo(int x, int y)
        : y_(y),
          Foo(x) {
        std::cout << "[FooFoo::FooFoo] y = " << y_ << std::endl;
    }

    ~FooFoo() {
        std::cout << "[FooFoo::~FooFoo] y = " << y_ << std::endl;
    }

    void printY() const noexcept {
        std::cout << "[FooFoo::printY] " << y_ << std::endl;
    }

    auto getY() const noexcept {
        return y_;
    }
};

class Bar {
public:
    // constructor accepts obj as pointer
    Bar(Foo* foo)
        : foo_(foo) {
        std::cout << "[Bar::Bar] foo.x_ : " << foo_->getX() << std::endl;
    }

    ~Bar() {
        std::cout << "[Bar::~Bar] foo.x_ : " << foo_->getX() << std::endl;
    }

    void whatIsFooX() {
        foo_->printX();
    }

private:
    // having obj as smart pointer
    const std::unique_ptr<Foo> foo_;
};

class Biz {
public:
    static Biz* create(int x) {
        return new Biz(x);
    }

    ~Biz() {
        std::cout << "[Biz::~Biz] biz.x_: " << x_ << std::endl;
    }

private:
    explicit Biz(int x)
        : x_(x) {
        std::cout << "[Biz::Biz] biz.x_: " << x_ << std::endl;
    }

    int x_;
};

class Something {
public:
    Something(int a)
        : a_(a) {
        std::cout << "Something::Something a = " << a_ << "\n";
    }

    ~Something() {
        std::cout << "Something::~Something a = " << a_ << "\n";
    }

private:
    int a_;
};

class HavingPointer {
public:
    explicit HavingPointer(int a)
        : something_(new Something{ a }) {
        std::cout << "HavingPointer::HavingPointer initialize something a = "
                  << a << "\n";
    }

    virtual ~HavingPointer() {
        std::cout << "HavingPointer::~HavingPointer called\n";
        if (something_ != nullptr) {
            std::cout << "HavingPointer::~HavingPointer finalize something\n";
            delete something_;
            something_ = nullptr;
        }
    }

    virtual void some_func() = 0;

private:
    Something* something_;
};

class HpConcrete : public HavingPointer {
public:
    explicit HpConcrete(int a)
        : HavingPointer(a) {
        std::cout << "HpConcrete::HpConcrete called\n";
    }

    ~HpConcrete() {
        std::cout << "HpConcrete::~HpConcrete called\n";
    }

    void some_func() override {
    }
};

} // namespace Code2

#endif // SMART_POINTER_H
