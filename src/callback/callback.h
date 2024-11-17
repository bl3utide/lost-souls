#ifndef CALLBACK_H
#define CALLBACK_H

#include <concepts>
#include <functional>
#include <iostream>

using CallbackT = void (*)(int, int);

class InputConnection {
public:
    void invoke() {
        cb_(1, 2);
    }

    void setCallback(CallbackT cb, void* data = (void*)0) {
        cb_ = cb;
    }

    CallbackT cb_;
};

class CallbackBase {
public:
    virtual ~CallbackBase() = default;
    virtual CallbackT getCallbackFunc() = 0;
};

class CallbackConcereteA : public CallbackBase {
public:
    CallbackT getCallbackFunc() override {
        return [](int a, int b) -> void {
            std::cout << "(invoked) a: " << a << ", b: " << b << std::endl;
        };
    }
};

template<class T>
    requires std::derived_from<T, CallbackBase>
class CallbackAssignor {
public:
    explicit CallbackAssignor<T>(InputConnection& conn)
        : conn_(&conn) {
        callback_ = std::make_unique<T>();
    }

    virtual void setCallback() final {
        auto fp = callback_->getCallbackFunc();
        conn_->setCallback(callback_->getCallbackFunc());
    }

private:
    InputConnection* conn_;
    std::unique_ptr<T> callback_;
    std::function<void(int, int)> callback_func_;
};

#endif // CALLBACK_H